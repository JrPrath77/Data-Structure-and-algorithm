//Bubble Sort
#include <stdio.h>
#include <stdlib.h>

int Bubble_sort(int a[],int n){
    int i,j;
    int flag; 
    int temp;                          //flag=1 means swapping is done  flag=0 means swapping not done
    for(i=0; i<n-1; i++){               //in Loop(i) n-1 in first loop because in bubble sort n-1 iterations are there
        flag=0;
        for(j=0; j<n-i-1; j++){        //in loop (j) is used to make comparisons; n-i-1 is used because last elemnt will be already sorted
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;

                flag=1;
            }
        }
        if(flag==0)
            break;
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

  Bubble_sort(a, n);

  printf("\nArray after sorting\n");
  for (i = 0; i < n; i++) {
    printf("\nElement %d: %d", i + 1, a[i]);
  }

  free(a);  // Free the allocated memory
  return 0;
}
