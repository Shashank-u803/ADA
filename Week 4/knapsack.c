#include<stdio.h>
#include<stdlib.h>

typedef struct item{
	int weight,profit;
}item;

int max(int a,int b){
	return a>b?a:b;
}

int knapsack(item* items,int capacity,int n){
	int dp[n+1][capacity+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=capacity;j++){
			if(i==0 || j==0){
				dp[i][j]=0;
			}else if(items[i-1].weight>j){
				dp[i][j]=dp[i-1][j];
			}
		else{
dp[i][j]=max(items[i-1].profit + dp[i-1][j-items[i-1].weight],dp[i-1][j]);
		    }
		}
	}
      return dp[n][capacity];
}


int main(){
	int n,w;
	printf("Enter the no.of items:");
	scanf("%d",&n);
	printf("Enter the knapsack capacity:");
	scanf("%d",&w);
	item items[n];
	for(int i=0;i<n;i++){
		printf("Enter item[%d] details (Weight,profit):",i);
		scanf("%d%d",&items[i].weight,&items[i].profit);
	}
	int max_profit = knapsack(items,w,n);
	printf("Max Profit using DP technique:%d\n",max_profit);
	return 0;
}
