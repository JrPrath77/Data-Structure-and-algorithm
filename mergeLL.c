#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};

void creatingLL(struct node **start, int data); // function declaration

// Function to display the linked list
void displayLL(struct node *start) {
  struct node *q = start;
  int node_no = 1;
  if (q == NULL)
    printf("Link List Is EMPTY\n");
  while (q != NULL) {
    printf("\nData of node %d is %d", node_no, q->data);
    q = q->next;
    node_no++;
  }
}

// Function to input data into linked lists
void Enter_data(struct node **start, int *no_nodes_in_LL) {
  int data;
  printf("\nEnter Number of Nodes To Be Created In Link List: ");
  scanf("%d", no_nodes_in_LL);
  // Invalid input
  if (*no_nodes_in_LL <= 0) {
    printf("Invalid input. Please enter a positive integer.\n");
    return;
  }

  for (int i = 0; i < *no_nodes_in_LL; i++) {
    printf("Enter data of the element %d: ", i + 1);
    scanf("%d", &data);
    creatingLL(start, data); // Pass the address of start to the function
  }
}

// Function to create a linked list
void creatingLL(struct node **start, int data) {
  struct node *p = (struct node *)malloc(sizeof(struct node));
  p->data = data;
  p->next = NULL;
  if (*start == NULL) {
    *start = p;
  } else {
    struct node *temp = *start;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = p;
  }
}

// Function to merge two linked lists alternatively
struct node *merge(struct node *start1, struct node *start2) {
  struct node *p1 = start1;
  struct node *p2 = start2;
  struct node *start3 = NULL;
  struct node *p3 = NULL;

  while (p1 != NULL && p2 != NULL) {
    if (start3 == NULL) {
      start3 = p1;
      p3 = start3;
      p1 = p1->next;
      p3->next = p2;
      p2 = p2->next;
      p3 = p3->next;
    } else {
      p3->next = p1;
      p1 = p1->next;
      p3 = p3->next;
      p3->next = p2;
      p2 = p2->next;
      p3 = p3->next;
    }
  }

  if (p1 != NULL) {
    p3->next = p1;
  }

  if (p2 != NULL) {
    p3->next = p2;
  }

  return start3;
}

int main() {
  struct node *start1 = NULL, *start2 = NULL, *newstart = NULL;
  int no_nodes_in_LL1, no_nodes_in_LL2;

  Enter_data(&start1, &no_nodes_in_LL1);
  Enter_data(&start2, &no_nodes_in_LL2);

  printf("\nFirst Linked List:");
  displayLL(start1);
  printf("\n");

  printf("\nSecond Linked List:");
  displayLL(start2);
  printf("\n");

  newstart = merge(start1, start2);

  printf("\nMerged Linked List:");
  displayLL(newstart);
  printf("\n");

  return 0;
}
