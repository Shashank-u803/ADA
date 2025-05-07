#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

//build a max-heap
void heapify(int* arr,int n,int i){
	int l = 2*i + 1, r = 2*i + 2;
	int largest = i;

	if(l<n && arr[l]>arr[largest]){
		largest = l;
	}
	
	if(r<n && arr[r]>arr[largest]){
		largest = r;
	}

	if(largest!=i){
		swap(&arr[largest],&arr[i]);
		//heapify the affected portion
		heapify(arr,n,largest);
	}
}


void heapsort(int* arr,int n){
	
	//swap the root with last element of heap
	//heapify the new heap

	for(int i=n/2-1;i>=0;i--){
		heapify(arr,n,i);
	}
	
       for(int i=n-1;i>0;i--){
       		swap(&arr[0],&arr[i]);
 		heapify(arr,i,0);
	}

}


void print_array(int* arr,int n){
	for(int i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}


int main(){
	int n;
	printf("Enter array size:");
	scanf("%d",&n);
	int arr[n];
	printf("Array before sorting:\n");
	for(int i=0;i<n;i++){
		arr[i]=(rand()%100) + 1;
	}
	print_array(arr,n);
	printf("Array after sorting:\n");
	clock_t start,end;
	start = clock();
	heapsort(arr,n);
	end = clock();
	print_array(arr,n);
	printf("Execution time:%f sec\n",((float)end-start)/CLOCKS_PER_SEC);
	return 0;
}	
