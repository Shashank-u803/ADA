#include <stdio.h>
#include <stdlib.h>

int min_cost = 999999;
int n;

void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int calc_cost(int** cost, int* jobs){
	int total = 0;
	for(int i=0;i<n;i++){
		total += cost[i][jobs[i]];
	}
	return total;
}

void permute(int** cost, int* jobs, int l){
	if(l == n){
		int total = calc_cost(cost, jobs);
		if(total < min_cost){
			min_cost = total;
		}
		return;
	}
	for(int i=l;i<n;i++){
		swap(&jobs[l], &jobs[i]);
		permute(cost, jobs, l+1);
		swap(&jobs[l], &jobs[i]); // backtrack
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
	printf("Enter number of jobs/workers (max 10): ");
	scanf("%d", &n);
	if(n > 10 || n <= 0){
		printf("Invalid input.\n");
		return 0;
	}

	int** cost = create_matrix(n);
	int* jobs = (int*)calloc(n, sizeof(int));
	for(int i=0;i<n;i++) jobs[i] = i;

	permute(cost, jobs, 0);

	printf("Minimum cost assignment = %d\n", min_cost);

	free_matrix(cost, n);
	free(jobs);
	return 0;
}
