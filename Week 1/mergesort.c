#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<windows.h>

void merge(int a[], int low, int mid, int high) {
    int *c = (int*)malloc( (high-low+1)*sizeof(int) );
    int i = low, j = mid+1, k = 0;
    while (i <=mid && j <=high) {
        if (a[i] <= a[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = a[j++];
        }
    }
    while (i <=mid) {
        c[k++] = a[i++];
    }
    while (j <=high) {
        c[k++] = a[j++];
    }
    for(i=0;i<high-low+1;i++){
	a[low+i]=c[i];
    }
    free(c);
}

void mergesort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergesort(a, low, mid);
        mergesort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}


int main() {
    int n, i;
    LARGE_INTEGER frequency, start, end;
    QueryPerformanceFrequency(&frequency);
    printf("Enter the no. of elements: ");
    scanf("%d", &n);
    int a[n]; 
    srand((unsigned int)time(NULL));
    printf("Randomly assigned %d values between 1 to 1000!\n",n);
    for(int i=0;i<n;i++){ 
          a[i] = (rand()%1000) + 1;
          printf("a[%d]:%d\n",i,a[i]); 
    }
    QueryPerformanceCounter(&start);
    mergesort(a,0,n-1);
    QueryPerformanceCounter(&end);
    double time_taken = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\nExcecution time: %f seconds\n", time_taken);

    return 0;
}
