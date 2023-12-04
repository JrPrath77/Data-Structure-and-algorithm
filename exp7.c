#include<stdio.h>

int a[50],top=-1;
int pop(){

	if(top==-1)
	printf("\n Stack Underflow\n");
	else{
	return a[top--];
	}
}

void push(int new_tos){

	if(top==49)
	printf("\n Stack Overflow\n");
	else{
	top=top+1;
	a[top]= new_tos;
	}
}


int main()
{   char postfix[50],operator;
    int result;
    printf("Enter Postfix Expression:\n");
    scanf("%s",postfix);
    
    for(int i=0;postfix[i]!='\0';i++) {
        if(postfix[i] >= '0' && postfix[i] <= '9') {
            push(postfix[i]-'0');
        }
        else {
            int b = pop();
            int a = pop();
            switch(postfix[i]){
                case '+' :
                    result=a+b;
                    break;
                case '-' :
                    result=a-b;
                    break;
                case '*' :
                    result=a*b;
                    break;
                case '/' :
                    result=a/b;
                    break;
            }
            push(result);
        }
    }
    
    result=pop();
    printf("Result: %d\n",result);
    return 0;
}
