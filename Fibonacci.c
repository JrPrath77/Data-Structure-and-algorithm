// Fibonacci Series Using Recurssion
#include<stdio.h>

int fibonacci(int a)
{
    if(a<=0)
    return 0;
    else if(a==1)
    return 1;
    else
    return fibonacci(a-1)+fibonacci(a-2);
}

int main()
{
    int a,i;
    printf("Enter Number To Find Fibonacci Series\n");
    scanf("%d",&a);
    fibonacci(a);
    printf("Fibonacci series:\n");
    for(i=0; i<a; i++)
    {
    printf("%d\t",fibonacci(i));
    }
    return 0;
}