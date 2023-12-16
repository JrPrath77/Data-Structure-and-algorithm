#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node *next;
};
struct node *start = NULL, *p, *q;

// Enqueue
void create_at_end() {
  p = (struct node *)malloc(sizeof(struct node));
  printf("\nEnter data of node to be created:");
  scanf("%d", &p->data);

  p->next = NULL;
  if (start == NULL) {
    start = p;
  }

  else {
    q = start;
    while (q->next != NULL) {
      q = q->next;
    }
    q->next = p;
    // update current last node with adding p node
  }
  printf("Node is Succesfully Created\n");
}

//Dequeue
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

void peek() {
   if (start == NULL) {
        printf("Stack Is empty\n");
    } else {
        // Set p to the top of the stack
        p = start;
        printf("Top of stack is %d\n", p->data);
    }
}

int main() {
    int choice, a;

    do {
        printf("\nEnter Choice: -\n");
        printf("1.Enqueue\n2.Dequeue\n3.Traverse\n4.Peek\n5.Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create_at_end();
                break;

            case 2:
                delete_at_start();
                break;

            case 3:
                Traversal();
                break;

            case 4:
                peek();
                break;

            case 5:
                break;

            default:
                printf("Enter a valid choice\n");
        }

    } while (choice != 5);

    return 0;
}
