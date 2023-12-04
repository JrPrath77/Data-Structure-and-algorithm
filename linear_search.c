// Linear Search OR Sequential Search
#include<stdio.h>

int main()
{   int n,i,data;

    printf("\nEnter the size of array: -");
    scanf("%d",&n);

     int a[n];

    for(i=0; i<n; i++){
        printf("\nEnter elemnt %d: -",i+1);
        scanf("%d",&a[i]);
    }
    
    printf("\nWhich data you want to find : -");
    scanf("%d",&data);

    for(i=0; i<n; i++){
        if(a[i]==data){
            printf("\n%d found at index %d",data,i);
            break;
        }
    
    if(i==n){
        printf("\nElement not found");
    }
    }


return 0;
}