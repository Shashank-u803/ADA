#include <stdio.h>
#include <stdlib.h>

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

void dfs(int** graph, int* visited, int* stack, int* top, int n, int node){
	visited[node] = 1;

	// Visit all adjacent unvisited vertices
	for(int i = 0; i < n; i++){
		if(graph[node][i] == 1 && !visited[i]){
			dfs(graph, visited, stack, top, n, i);
		}
	}

	// Push to stack after visiting all descendants
	stack[(*top)++] = node;
}

void topo_sort(int** graph, int n){
	int* visited = (int*)calloc(n, sizeof(int));
	int* stack = (int*)calloc(n, sizeof(int));
	int top = 0;

	// Call DFS for all unvisited nodes
	for(int i = 0; i < n; i++){
		if(!visited[i]){
			dfs(graph, visited, stack, &top, n, i);
		}
	}

	// Print in reverse order of finishing time
	printf("Topological Order:\n");
	for(int i = top - 1; i >= 0; i--){
		printf("%d ", stack[i]);
	}
	printf("\n");

	free(visited);
	free(stack);
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
