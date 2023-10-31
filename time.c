//time comlexity for insertion sort
#include <stdio.h>
#include <time.h>
void insertionSort(int arr[], int n) {
  for (int i = 1; i < n; i++) {
    int key = arr[i];
    int j = i - 1;
    while (key < arr[j] && j >= 0) {
      arr[j + 1] = arr[j];
      --j;
    }
    arr[j + 1] = key;
  }
}
void printArray(int array[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}
int main() {
    clock_t start, end;
    double cpu_time_used;
    start = clock(); 
    int n;
    printf("Enter the size of array:");
    scanf("%d",&n);
    int arr[n];
    for(int i=0; i<n; i++){
        printf("Enter the %d element:\t",i);
        scanf("%d" ,&arr[i]);
    }
    insertionSort(arr,n);
    printf("Sorted array in ascending oder:\t");
    printArray(arr,n);

    end = clock(); 
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Time taken: %f seconds\n", cpu_time_used);

 return 0;
}