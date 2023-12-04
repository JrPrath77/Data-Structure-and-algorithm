#include <stdio.h>

int Bubble_sort(){
    int i,j;
    int flag;                           //flag=1 means swapping is done  flag=0 means swapping not done
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

int selection_sort(){

}

int insertion_sort(){

}

int main() {
  
  int n,i;

  printf("\nEnter the size of array: -");
  scanf("%d", &n);

  int a[n];

  for (i = 0; i < n; i++) {
    printf("\nEnter elemnt %d: -", i + 1);
    scanf("%d", &a[i]);
  }

  printf("\nArray Before Sorting:-");
  for (i = 0; i < n; i++) {
    printf("\nElemnt %d: -%d", i + 1,a[i]);
  }

Bubble_sort();

printf("Array after sorting\n");
 for (i = 0; i < n; i++) {
    printf("\nElemnt %d: -%d", i + 1,a[i]);
  }
  return 0;
}