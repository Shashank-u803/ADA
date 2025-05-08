#include <stdio.h>
#include <stdlib.h>

int n;
int min_cost = 999999;

// Swap utility
void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

// Calculate cost of a path
int calc_cost(int** cost, int* path){
	int total = 0;
	for(int i=0;i<n-1;i++){
		total += cost[path[i]][path[i+1]];
	}
	total += cost[path[n-1]][path[0]]; // return to starting city
	return total;
}

// Generate permutations
void tsp(int** cost, int* path, int l){
	if(l == n){
		int total = calc_cost(cost, path);
		if(total < min_cost){
			min_cost = total;
		}
		return;
	}
	for(int i=l;i<n;i++){
		swap(&path[l], &path[i]);
		tsp(cost, path, l+1);
		swap(&path[l], &path[i]); // backtrack
	}
}

int** create_matrix(int n){
	int** cost = (int**)calloc(n, sizeof(int*));
	for(int i=0;i<n;i++){
		cost[i] = (int*)calloc(n, sizeof(int));
	}
	printf("Enter cost matrix:\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("cost[%d][%d]: ", i, j);
			scanf("%d", &cost[i][j]);
		}
	}
	return cost;
}

void free_matrix(int** cost, int n){
	for(int i=0;i<n;i++){
		free(cost[i]);
	}
	free(cost);
}

int main(){
	printf("Enter number of cities: ");
	scanf("%d", &n);

	if(n > 10 || n < 2){
		printf("Enter 2 to 10 cities only.\n");
		return 0;
	}

	int** cost = create_matrix(n);
	int* path = (int*)calloc(n, sizeof(int));
	for(int i=0;i<n;i++) path[i] = i;

	tsp(cost, path, 1); // fix city 0 as starting point

	printf("Minimum tour cost = %d\n", min_cost);

	free_matrix(cost, n);
	free(path);
	return 0;
}
