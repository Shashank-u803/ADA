#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define LEFT -1
#define RIGHT 1

typedef struct{
	int direction,value;
}element;

void init(element items[],int n){
	for(int i=0;i<n;i++){
		items[i].value = i+1;
		items[i].direction = LEFT;
	}
}

void swap(element* a,element* b){
	element temp = *a;
	*a = *b;
	*b = temp;
}


int largest_mobile_integer(element items[],int n,int* adj_index){
	int largest_mi = -1; //index
	int adj;
	for(int i=0;i<n;i++){
		int curr_dir = items[i].direction;
		adj = i + curr_dir; //adjacent index wrt mobile integer
		if(adj>=0 && adj<n){
		    if(items[i].value > items[adj].value){
		      if(largest_mi==-1 || items[i].value > items[largest_mi].value){
			   largest_mi = i;
			}
		}
	 }
	}
	if(largest_mi!=-1){
	  *adj_index = largest_mi + items[largest_mi].direction;
	}
	return largest_mi;
}

void print_permutation(element items[],int n){
	for(int i=0;i<n;i++){
		printf("%d ",items[i].value);
	}
	printf("\n");
}

void reverse_direction(element items[],int n,int index){
	int mi = items[index].value; //mobile integer
	for(int i=0;i<n;i++){
		if(items[i].value>mi){
			items[i].direction*=-1;
		}
	}
}


void johnsonn_trotter(element items[],int n){
	init(items,n);
	print_permutation(items,n);
	int adj,index;
	while(true){
	   //Step 1: find out largest mobile integer
	   index = largest_mobile_integer(items,n,&adj);
	   if(index==-1){ break; }
	  //Step 2: Swap it with it's adjacent
	   swap(&items[index],&items[adj]);
	  //Step 3: Reverse directions of integer > mobile integer
	  //Since index was swapped so adj took the value of index
	   reverse_direction(items,n,adj);
	  //Step 4: Print the permutation obtained
	   print_permutation(items,n);
	 }
}

int main(){
	int n;
	printf("Enter upper bound:");
	scanf("%d",&n);
	element items[n];
	johnsonn_trotter(items,n);
	return 0;
}
