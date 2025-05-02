#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void swap(int *a ,int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void init(int arr[],int n){
	int range = 1000;
	//fills array with random values in [1,1000]
	for(int i=0;i<n;i++){
		arr[i] = (rand()%range) + 1;
	}
}

void Bubble_sort(int arr[],int n){
	for(int i=1;i<n;i++){
	   for(int j=0;j<n-i;j++){
	   	if(arr[j]>arr[j+1]){
	     		swap(&arr[j],&arr[j+1]);
		}
	   }
        }
}

int main(){
	int n;
	printf("Enter Array size:");
	scanf("%d",&n);
	int a[n];
	init(a,n);
	printf("Array before Sorting:\n\n");
	for(int i=0;i<n;i++){ printf("%d ",a[i]); }
	printf("\n\n");
	clock_t start,end;
	start = clock();
	Bubble_sort(a,n);
	end = clock();
	float exec_time = ((float)(end - start))/CLOCKS_PER_SEC;
	printf("Array after Sorting:\n\n");
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n\nExecution time:%f sec\n",exec_time);
	return 0;
}
