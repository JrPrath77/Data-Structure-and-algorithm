//Merge Sort
#include<stdio.h>
#include<stdlib.h>

void merge(int a[], int low, int mid, int high) {
  int i = low;
  int j = mid + 1; 
  int k = low;
  int b[high -low+ 1]; // Create temporary array to store merged result

  // Merging two sorted arrays
  while (i <= mid && j <= high) {
    if (a[i] < a[j]) {
      b[k] = a[i];
      i++;
    } else {
      b[k] = a[j];
      j++;
    }
    k++;
  }

  // Copy the remaining elements of the first half
  while (i <= mid) {
    b[k] = a[i];
    i++;
    k++;
  }

  // Copy the remaining elements of the second half
  while (j <= high) {
    b[k] = a[j];
    j++;
    k++;
  }

  // Copy the merged elements back to the original array
  for (k = low; k <= high; k++) {
    a[k] = b[k];
  }
}

void merge_sort(int a[], int low, int high) {
  if (low < high) {
    int mid = (low + high) / 2;

    // Sort the first half
    merge_sort(a, low, mid);
    // Sort the second half
    merge_sort(a, mid + 1, high);
    // Merge the sorted halves
    merge(a, low, mid, high);
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

  merge_sort(a, 0, n);

  printf("\nArray after sorting\n");
  for (i = 0; i < n; i++) {
    printf("\nElement %d: %d", i + 1, a[i]);
  }

  free(a);  // Free the allocated memory
  return 0;
}
