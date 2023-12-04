// Fibonacci Using recurssion
#include<stdio.h>

int factorial(int a)
{
    if(a==0 || a==1)
     return 1;
    
    return a*factorial(a-1);
}


int main()
{
    int a;
    printf("Enter Number to find factorial\n");
    scanf("%d",&a);

    printf("Factorial of given number is %d",factorial(a));
    return 0;
}