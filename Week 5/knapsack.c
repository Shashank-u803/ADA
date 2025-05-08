#include <stdio.h>
#include <stdlib.h>

int n, max_w;
int max_profit = 0;

int max(int a, int b){
	return (a > b) ? a : b;
}

// Brute-force: Try all combinations
void knapsack(int* wt, int* val, int i, int curr_w, int curr_p){
	if(i == n){
		if(curr_w <= max_w && curr_p > max_profit){
			max_profit = curr_p;
		}
		return;
	}
	// Exclude item i
	knapsack(wt, val, i+1, curr_w, curr_p);
	// Include item i if weight allows
	if(curr_w + wt[i] <= max_w){
		knapsack(wt, val, i+1, curr_w + wt[i], curr_p + val[i]);
	}
}

int main(){
	printf("Enter number of items: ");
	scanf("%d", &n);

	int* wt = (int*)calloc(n, sizeof(int));
	int* val = (int*)calloc(n, sizeof(int));

	printf("Enter weights of items:\n");
	for(int i=0;i<n;i++){
		printf("wt[%d]: ", i);
		scanf("%d", &wt[i]);
	}

	printf("Enter values of items:\n");
	for(int i=0;i<n;i++){
		printf("val[%d]: ", i);
		scanf("%d", &val[i]);
	}

	printf("Enter maximum capacity of knapsack: ");
	scanf("%d", &max_w);

	knapsack(wt, val, 0, 0, 0);

	printf("Maximum profit = %d\n", max_profit);

	free(wt);
	free(val);
	return 0;
}
