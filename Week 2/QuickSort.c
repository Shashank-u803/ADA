#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *arr, int low, int high) {
    int i = low + 1, j = high, pivot = arr[low];

    while (i <= j) {
        while (arr[i] <= pivot && i <= high) i++;
        while (arr[j] > pivot && j >= low) j--;
        if (i < j) swap(&arr[i], &arr[j]);
    }

    swap(&arr[j], &arr[low]);
    return j;
}

void quicksort(int *arr, int low, int high) {
    if (low < high) {
        int pivot_pos = partition(arr, low, high);
        quicksort(arr, low, pivot_pos - 1);
        quicksort(arr, pivot_pos + 1, high);
    }
}

int main() {
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);
    int arr[n];

    printf("Randomly assigned %d values between 1 to 1000!\n", n);
    for (int i = 0; i < n; i++) {
        arr[i] = (rand() % 1000) + 1;  
        printf("arr[%d]: %d\n", i, arr[i]);
    }

    // Windows high-resolution timing
    LARGE_INTEGER frequency, start, end;
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);

    quicksort(arr, 0, n - 1);

    QueryPerformanceCounter(&end);
    double time_taken = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

    printf("Array after sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nExecution time: %f sec\n", time_taken);
    return 0;
}
