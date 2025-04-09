#include<stdio.h>
#include<stdlib.h>
int min(int a,int b){
	return a<b?a:b;
}

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

void floyd(int **matrix,int n){
      for(int k=0;k<n;k++){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
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
	int** cost = read_data(&n);
	printf("Before floyd the adjacency matrix is:\n");
	print_data(cost,n);
	printf("Cost matrix after floyd's algo is\n");
	floyd(cost,n);
	print_data(cost,n);
	return 0;
}
