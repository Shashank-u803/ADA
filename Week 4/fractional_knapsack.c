#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int cost;
	int weight;
	float ratio;
} Item;

void sort_items(Item* items, int n){
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-i-1;j++){
			if(items[j].ratio < items[j+1].ratio){
				Item temp = items[j];
				items[j] = items[j+1];
				items[j+1] = temp;
			}
		}
	}
}

float fractional_knapsack(Item* items, int n, int capacity){
	float total_profit = 0.0;
	for(int i=0;i<n;i++){
		if(capacity >= items[i].weight){
			total_profit += items[i].cost;
			capacity -= items[i].weight;
		}else{
			total_profit += (float)items[i].cost * ((float)capacity / items[i].weight);
			break;
		}
	}
	return total_profit;
}

int main(){
	int n, cap;
	printf("Enter number of items: ");
	scanf("%d", &n);

	Item* items = (Item*)calloc(n, sizeof(Item));

	printf("Enter cost and weight of each item:\n");
	for(int i=0;i<n;i++){
		printf("Item %d cost: ", i);
		scanf("%d", &items[i].cost);
		printf("Item %d weight: ", i);
		scanf("%d", &items[i].weight);
		items[i].ratio = (float)items[i].cost / items[i].weight;
	}

	printf("Enter knapsack capacity: ");
	scanf("%d", &cap);

	sort_items(items, n);
	float max_profit = fractional_knapsack(items, n, cap);
	printf("Maximum profit = %.2f\n", max_profit);

	free(items);
	return 0;
}
