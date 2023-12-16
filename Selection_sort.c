// Selection Sort
#include<stdio.h>
#include<stdlib.h>

void selection_sort(int a[], int n) {
  int i, j, min, temp;
  for (i = 0; i < n - 1; i++) {
    min = i;
    for (j = i + 1; j < n; j++) {
      if (a[j] < a[min]) {
        min = j;
      }
    }
    if (i != min) {
      temp = a[min];
      a[min] = a[i];
      a[i] = temp;
    }
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

  selection_sort(a,n);

  printf("\nArray after sorting\n");
  for (i = 0; i < n; i++) {
    printf("\nElement %d: %d", i + 1, a[i]);
  }

  free(a);  // Free the allocated memory
  return 0;
}
