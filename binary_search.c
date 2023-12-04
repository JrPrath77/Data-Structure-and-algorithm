// Binary search(pre-condition Array should be sorted)
#include <stdio.h>

int Binary_search(int a[], int n, int data) {

  int l = 0; // l-left r-right
  int r = n - 1;
  int mid;

  while (l <= r) {
    mid = (l + r) / 2;

    if (data == a[mid]) {
      return mid;
    } else if (data < a[mid]) {
      r = mid - 1;
    } else if (data > a[mid]) {
      l = mid + 1;
    }
  }
  return -1;
}

int main() {

  int i, n, data, result;

  printf("\nEnter size of array: -");
  scanf("%d", &n);

  int a[n];

  printf("\nEnter sorted array:");

  for (i = 0; i < n; i++) {
    printf("\nEnter element %d:", i + 1);
    scanf("%d", &a[i]);
  }

  printf("Enter element you want to find:");
  scanf("%d", &data);

  result = Binary_search(a, n, data);

  if (result == -1) {
    printf("\nElement Not Found");
  } else {
    printf("Elment %d found at index %d", data, result);
  }

  return 0;
}