#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node *next;
};
struct node *start = NULL, *p, *q;

//PUSH
void create_at_start() {
  p = (struct node *)malloc(sizeof(struct node));
  printf("\nEnter data of node to be created:");
  scanf("%d", &p->data);

  if (start == NULL) {
    start = p;
    p->next = NULL;
  } else {
    p->next = start;
    start = p;
  }
  printf("Node is Succesfully Created\n");
}

//POP
void delete_at_start() {
  if (start == NULL)
    printf("Delete can not be perfprmed,Link List is empty\n");
  else {
    p = start;
    start = p->next;
    printf("%d is deleted", p->data);
    free(p);
  }
}

void Traversal() {
  int node_no = 1;
  q = start; // Initialize q with start
  if (q == NULL)
    printf("Link List Is EMPTY\n");
  while (q != NULL) {
    printf("\nData of node %d is %d", node_no, q->data);
    q = q->next;
    node_no++;
  }
}

void Top_of_stack() {
    if (start == NULL) {
        printf("Stack Is empty\n");
    } else {
        // Set p to the top of the stack
        p = start;
        printf("Top of stack is %d\n", p->data);
    }
}

int main(){

	int choice;
	while(choice!=5){	
	printf("\nEnter choice:\n 1.Traverse\n 2.Push\n 3.Pop\n 4.Top of stack\n 5.Exit\n");	
	scanf("%d",&choice);
	
	switch(choice){
	case 1: Traversal();
	 break;
	case 2: create_at_start();
	 break;
	case 3: delete_at_start();
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
