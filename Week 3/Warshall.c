#include<stdio.h>
#include<stdlib.h>

int** read_data(int* n){
	printf("Enter no.of vertices:");
	scanf("%d",n);
	int **matrix = (int**)calloc(*n,sizeof(int*));
	for(int i=0;i<*n;i++){
		matrix[i]=(int*)calloc(*n,sizeof(int));
	}
	printf("Enter the values for cost adjacency matrix:\n");
	for(int i=0;i<*n;i++){
		for(int j=0;j<*n;j++){
			printf("cost[%d][%d]:",i,j);
			scanf("%d",&matrix[i][j]);
		}
	}
	return matrix;
}


void warshall(int** adj,int n){
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(adj[i][k]==1 && adj[k][j]==1){
					adj[i][j]=1;
				}
			}
		}
	}
}

void print_data(int** matrix,int n){
	printf("Updated matrix:\n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int n;
	int** adjacency = read_data(&n);
	printf("Before warshall's algo the adjacency matrix is:\n");
	print_data(adjacency,n);
	printf("adjacency matrix after warshall's algo is\n");
	warshall(adjacency,n);
	print_data(adjacency,n);
	return 0;
}
