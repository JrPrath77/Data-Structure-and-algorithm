// Singly Link List using two external reference pointer
#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
};
struct node *start = NULL, *p, *q, *last = NULL;

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

void create_at_start() {
  p = (struct node *)malloc(sizeof(struct node));
  printf("\nEnter data of node to be created:");
  scanf("%d", &p->data);

  if (start == NULL) {
    start = p;
    last = p;
    p->next = NULL;
  } else {
    p->next = start;
    start = p;
  }
  printf("Node is Successfully Created\n");
}

void create_at_end() {
  p = (struct node *)malloc(sizeof(struct node));
  printf("\nEnter data of node to be created:");
  scanf("%d", &p->data);

  p->next = NULL;
  if (start == NULL) {
    start = p;
    last = p;
  } else {
    last->next = p;
    last = p;
    // update current last node with adding p node
  }
  printf("Node is Successfully Created\n");
}

void create_at_location() {
  int location, i = 1;
  p = (struct node *)malloc(sizeof(struct node));
  printf("Enter Location to create Node\n");
  scanf("%d", &location);
  printf("\nEnter data of node to be created:");
  scanf("%d", &p->data);

  // At Start if Start==NuLL
  if (start == NULL) {
    if (location == 1) {
      start = p;
      p->next = NULL;
      last = p;
      printf("Node is successfully created at start\n");
    } else {
      printf("Link List Is Empty Enter Valid Location\n");
      free(p);
    }
  } else if (location == 1) // create at start if link list have some elements
  {
    p->next = start;
    start = p;
    printf("Node is successfully created at start\n");

  } else // Create at any location (except start) at the end also
  {
    q = start;
    while (i < location - 1 && q != NULL) {
      q = q->next;
      i++;
    }
    if (q != NULL) {
      p->next = q->next;
      q->next = p;
      printf("Node is successfully created at location %d\n", location);
    }

    else {
      printf("Enter Vallid Location\n");
      free(p);
    }
  }
}

void delete_at_start() {
  // Link List is empty
  if (start == NULL)
    printf("Delete can not be performed,Link List is empty\n");
  // Link list have only one element
  else if (start->next == NULL) {
    start = NULL;
    last = NULL;
    printf("%d is deleted\n", p->data);
  }
  // Link List have 2 or more elements
  else {
    p = start;
    start = p->next;
    printf("%d is deleted", p->data);
    free(p);
  }
}

void delete_at_end() {
  // LL is empty
  if (start == NULL)
    printf("Link List is empty delete cannot be performed\n");
  // LL having one element
  else if (start->next == NULL) {
    p = start;
    start = NULL;
    last = NULL;
    printf("%d is deleted at end\n", p->data);
    free(p);
  }
  // Link List having more than one element
  else {
    p = start;
    while (p->next != NULL) {
      q = p;
      p = p->next;
    }
    q->next = NULL;
    printf("%d is deleted\n", p->data);
    free(p);
    last =q; // update the last pointer when last node is deleted
  }
}

void delete_at_location() {
  int location, i;
  printf("Which Location's node fo you want to delete\n");
  scanf("%d", &location);

  // LL is empty
  if (start == NULL)
    printf("Link List is empty delete cannot be performed\n");
  // LL having only one element
  else if (location == 1) {
    p = start;
    start = NULL;
    last = NULL;
    printf("%d is deleted at location %d\n", p->data, location);
    free(p);
  }
  // LL having more than one element (logic work at end also)
  else if (location > 1) {
    i = 1;
    p = start;
    // setting p at given location
    while (i < location && p != NULL) {
      q = p;
      p = p->next;
      i++;
    }
    // deleting node
    if (p != NULL) {
      q->next = p->next;
      printf("%d is deleted at location %d\n", p->data, location);
      free(p);
    } else {
      printf("Enter Valid Location");
    }
  }
}

int main() {
  struct node *first, *second, *third;
  int i;

  // Allocate memory for nodes in link list
  first = (struct node *)malloc(sizeof(struct node));
  second = (struct node *)malloc(sizeof(struct node));
  third = (struct node *)malloc(sizeof(struct node));

  // linking nodes
  start = first;
  first->data = 1;
  first->next = second;

  second->data = 2;
  second->next = third;

  third->data = 3;
  third->next = NULL;

  // Initialize last pointer to last node in LINK LIST
  last = third;

  // Choices for user
  do {
    printf("\nEnter Choice:\n 1.Create At Start\n 2.Create At End \n 3.Create "
           "At Given Location\n 4.Delete At Start\n 5.Delete At End \n "
           "6.Delete At Given Location\n 7.Traverse\n 8.Exit\n");
    scanf("%d", &i);

    switch (i) {
    case 1:
      create_at_start();
      break;
    case 2:
      create_at_end();
      break;
    case 3:
      create_at_location();
      break;
    case 4:
      delete_at_start();
      break;
    case 5:
      delete_at_end();
      break;
    case 6:
      delete_at_location();
      break;
    case 7:
      Traversal();
      break;
    case 8:
      break;
    default:
      printf("Invalid Input\n");
      break;
    }
  } while (i != 8);

  return 0;
}
