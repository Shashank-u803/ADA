#include <stdio.h>
#include <stdlib.h>

// Create adjacency matrix
int** create_graph(int n){
	int** graph = (int**)calloc(n, sizeof(int*));
	for(int i = 0; i < n; i++){
		graph[i] = (int*)calloc(n, sizeof(int));
	}

	printf("Enter the adjacency matrix (1 for edge, 0 for no edge):\n");
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			printf("edge[%d][%d]: ", i, j);
			scanf("%d", &graph[i][j]);
		}
	}
	return graph;
}

// Calculate in-degrees of all nodes
void compute_indegree(int** graph, int* indegree, int n){
	for(int i = 0; i < n; i++){
		indegree[i] = 0;
		for(int j = 0; j < n; j++){
			if(graph[j][i] == 1){
				indegree[i]++;
			}
		}
	}
}

// Perform topological sort using source removal
void topo_sort(int** graph, int n){
	int* indegree = (int*)calloc(n, sizeof(int));
	int* visited = (int*)calloc(n, sizeof(int));
	int count = 0;

	compute_indegree(graph, indegree, n);

	printf("Topological Order:\n");
	while(count < n){
		int found = 0;
		for(int i = 0; i < n; i++){
			if(indegree[i] == 0 && visited[i] == 0){
				// Node with no incoming edges → print and remove
				printf("%d ", i);
				visited[i] = 1;
				count++;
				found = 1;
				// Reduce indegree of its neighbors
				for(int j = 0; j < n; j++){
					if(graph[i][j] == 1){
						indegree[j]--;
					}
				}
				break;
			}
		}
		if(!found){
			printf("\nCycle detected. Topological sort not possible.\n");
			break;
		}
	}
	printf("\n");

	free(indegree);
	free(visited);
}

void free_graph(int** graph, int n){
	for(int i = 0; i < n; i++){
		free(graph[i]);
	}
	free(graph);
}

int main(){
	int n;
	printf("Enter number of nodes: ");
	scanf("%d", &n);

	int** graph = create_graph(n);
	topo_sort(graph, n);
	free_graph(graph, n);

	return 0;
}
