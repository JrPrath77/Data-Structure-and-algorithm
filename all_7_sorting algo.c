#include<stdio.h>

void bubble_sort(int *a){
int i,j,temp;
for(i=0; i<size-1; i++){
    for(j=0; j<size-i-1; j++){
        if(a[j]>a[j+1]){
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
        }

    }
}
}

void selection_sort(int a[],int n){
    int i,j,min,temp;
    for(i=0; i<n-1; i++){
        min=i;
        for(j=i+1; j<n; j++){
            if(a[j]<a[min]){
            min=j;
            }
        }
            if(i!=min){
            temp=a[min];
            a[min]=a[i];
            a[i]=temp;
            
        }
    }
}

void insertion_sort(int a[],int n){
    int i,j,temp;
    for(i=1; i<n; i++){
        temp=a[i];
        j=i-1;
        
        while(temp<a[j] && j>=0){
            a[j+1]=a[j];
            j--;
            a[j+1]=temp;
        }
    }
}

void selection_sort(){
    
}

void quick_sort(){
    
}

void merge_sort(){
    
}

void radix_sort(){
    
}
int main(){
    
int i,j,temp;
int n,choice;

printf("Enter total number of elements\n");
scanf("%d",&n);

int a[n];

printf("Enter unsorted elements \n");
for(i=0; i<n; i++){
    scanf("%d",&a[i]);
}

printf("\nArray before sorting:\n");
for(i=0; i<n; i++){
    printf("%d\t",a[i]);
}


printf("\n1.Bubble Sort\n2.Selection Sort\n3.Insertion Sort\n4.Quick Sort\n5.Merge Sort\n6.Radix Sort\n");
printf("Enter choice:");
scanf("%d",&choice);

switch(){
    case 1: bubble_sort();
            break;
    case 2: selection_sort(a,n);
            break;
    case 3: insertion_sort(a,n);
            break;
    case 4: quick_sort();
            break;
    case 5: merge_sort(a,n);
            break;
    case 6: radix_sort();
            break;
    default:
        printf("Enter Valid Input\n");
            
}
                                         
printf("\nArray after sorting:\n");
for(i=0; i<n; i++){
    printf("%d\t",a[i]);
}

return 0;
}