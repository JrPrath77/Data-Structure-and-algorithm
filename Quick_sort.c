// Quick Sort
#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void quick_sort(int a[], int low, int high) {
  /* a[] -->array to be sorted
     i-->low
     j--> high
     */
  int i = low, j = high;
  int pivot = a[(low + high) / 2]; // taking middle element as pivot element ; so
                                  // their is no need to swap pivot elemetnt

  // partition
  while (i <= j) {

    while (a[i] < pivot) {
      i++;
    }
    while (a[j] > pivot) {
      j--;
    }
    if(i<=j){
    swap(&a[i], &a[j]);
    i++;
    j--;
    }
  }

  // recursively sort the partitions
  if (low < j) {
    quick_sort(a, low, j);
  }
  if (i < high) {
    quick_sort(a, i, high);
  }
}


int main() {
  int n, i;

  printf("\nEnter the size of the array: ");
  scanf("%d", &n);

  int *a = (int*)malloc(n * sizeof(int));  // Allocate memory for the array

  if (a == NULL) {  // Check for successful memory allocation
    printf("Memory allocation failed. Exiting...");
    return 1;
  }

  for (i = 0; i < n; i++) {
    printf("\nEnter element %d: ", i + 1);
    scanf("%d", &a[i]);
  }

  printf("\nArray Before Sorting:-");
  for (i = 0; i < n; i++) {
    printf("\nElement %d: %d", i + 1, a[i]);
  }

  quick_sort(a,0,n);

  printf("\nArray after sorting\n");
  for (i = 0; i < n; i++) {
    printf("\nElement %d: %d", i + 1, a[i]);
  }

  free(a);  // Free the allocated memory
  return 0;
}
