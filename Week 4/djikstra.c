#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int** create_graph(int n){
	int** cost = (int**)calloc(n,sizeof(int*));
	for(int i=0;i<n;i++){
		cost[i]=(int*)calloc(n,sizeof(int));
	}
	printf("Enter the Cost matrix values (999 if no direct edge)\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("cost[%d][%d]:",i,j);
			scanf("%d",&cost[i][j]);
		}
	}
	return cost;
}

int* djikstra(int** cost,int n,int source){
	int min,u;
	bool visited[n];
	int *sd = (int*)calloc(n,sizeof(int));
	//initialise visited and shortest distance array
	for(int j=0;j<n;j++){
		if(j==source){
			visited[j]=true;
			sd[j]=0;
		}else{
			visited[j]=false;
			sd[j]=cost[source][j];
		}
	}
	//Execute the algorithm
	for(int k=1;k<n;k++){
		min=999;
		//find out the unvisited edge with least updated distance from source
		for(int i=0;i<n;i++){
			if(!visited[i] && sd[i]<min){
				min=sd[i];
				u=i;
			}
		}
		visited[u]=true;
		//perform relaxation
		for(int j=0;j<n;j++){
			if(!visited[j]){
				if(sd[u] + cost[u][j] < sd[j]){
				       sd[j] = sd[u] + cost[u][j];
				}
		 	}
		}
	}

	return sd;
}

void print_distance(int *d,int n,int source){
	printf("Least distances from %d to other vertices are:\n",source);
	for(int i=0;i<n;i++){
		printf("%d--->%d: %d\n",source,i,d[i]);
	}
}

void free_graph(int** cost,int n){
	for(int i=0;i<n;i++){
	    free(cost[i]);
	}
	free(cost);
}

int main(){
	int n;
	printf("Enter no of nodes:");
	scanf("%d",&n);
	int** cost = create_graph(n);
start:
	int source;
	printf("Enter the source node:");
	scanf("%d",&source);
	if(source>=n || source<0) goto start;

	int* shortest_distance = djikstra(cost,n,source);
	print_distance(shortest_distance,n,source);
	free_graph(cost,n);
	free(shortest_distance);
	return 0;
}
