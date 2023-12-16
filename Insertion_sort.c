// Insertion Sort
#include<stdio.h>
#include<stdlib.h>

void insertion_sort(int a[], int n) {
  int i, j, temp;
  for (i = 1; i < n; i++) {
    temp = a[i];
    j = i - 1;

    while (temp < a[j] && j >= 0) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = temp;
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

 insertion_sort(a,n);

  printf("\nArray after sorting\n");
  for (i = 0; i < n; i++) {
    printf("\nElement %d: %d", i + 1, a[i]);
  }

  free(a);  // Free the allocated memory
  return 0;
}
