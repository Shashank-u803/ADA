#include <stdio.h>
#include <stdlib.h>

#define INF 999

int find(int parent[], int i){
	if(parent[i] != i)
		parent[i] = find(parent, parent[i]); 
	return parent[i];
}

int** create_graph(int n){
	int** cost = (int**)calloc(n, sizeof(int*));
	for(int i = 0; i < n; i++){
		cost[i] = (int*)calloc(n, sizeof(int));
	}

	printf("Enter the Cost matrix values (999 if no direct edge):\n");
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			printf("cost[%d][%d]: ", i, j);
			scanf("%d", &cost[i][j]);
		}
	}
	return cost;
}

void kruskal(int** cost, int n){
	int parent[10];
	int t[10][2]; // MST edge list
	int count = 0, sum = 0, k = 0;
	int min, u, v;

	// Initialize each node as its own parent
	for(int i = 0; i < n; i++){
		parent[i] = i;
	}

	while(count < n - 1){
		min = INF;
		u = -1;
		v = -1;

		// Find the minimum weight edge that doesn't form a cycle
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(find(parent, i) != find(parent, j) && cost[i][j] < min){
					min = cost[i][j];
					u = i;
					v = j;
				}
			}
		}

		// Union the sets
		if(u != -1 && v != -1){
			int root_u = find(parent, u);
			int root_v = find(parent, v);
			parent[root_u] = root_v;

			t[k][0] = u;
			t[k][1] = v;
			sum += cost[u][v];
			k++;
			count++;
		}
	}

	// Print the MST
	printf("\nEdges in the Minimum Spanning Tree:\n");
	for(int i = 0; i < k; i++){
		printf("%d -- %d\n", t[i][0], t[i][1]);
	}
	printf("Total cost of MST: %d\n", sum);
}

void free_graph(int** cost, int n){
	for(int i = 0; i < n; i++){
		free(cost[i]);
	}
	free(cost);
}

int main(){
	int n;
	printf("Enter number of nodes: ");
	scanf("%d", &n);

	int** cost = create_graph(n);
	kruskal(cost, n);
	free_graph(cost, n);

	return 0;
}
