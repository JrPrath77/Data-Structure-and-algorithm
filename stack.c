#include<stdio.h>
#include<stdlib.h>

int a[5],top=-1;

void push(){

	if(top==4)
	printf("\n Stack Overflow\n");
	else{
	top=top+1;
	printf("\nEnter %d element of stack :",top+1);
	scanf("%d",&a[top]);	
	}
     }

void pop(){

	if(top==-1)
	printf("\n Stack Underflow\n");
	else{
	printf("\n%d is popped\n",a[top]);
	top=top-1;
	}
     }

void Traverse_Stack(){
	int i;
	if(top==-1)
	printf("\nStack Is Empty\n");
	else{
	for(i=0;i<=top;i++){
	printf("\nElement %d is %d",i+1,a[i]);	
	}
	}
	printf("\n");
}

void Top_of_stack(){
	if(top==-1)
	printf("\nStack Is empty\n");
	else
	printf("Top of stack is %d",a[top]);
}

int main(){

	int choice;
	while(choice!=5){	
	printf("\nEnter choice:\n 1.Traverse\n 2.Push\n 3.Pop\n 4.Top of stack\n 5.Exit\n");	
	scanf("%d",&choice);
	
	switch(choice){
	case 1: Traverse_Stack();
	 break;
	case 2: push();
	 break;
	case 3: pop();
	 break;
	case 4:Top_of_stack(); 
	 break;
	case 5: //Exit
	 break;
	default:
 		printf("Enter Valid Input\n");
		break;
	}
	}
	return 0;
}
