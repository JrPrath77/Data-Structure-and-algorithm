#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
  struct node *prev;
};
struct node *start = NULL, *p, *q, *last = NULL;

void Traversal() {
  int node_no = 1;
  q = start; // Initialize q with start
  // q = last; // to traverse in backward direction
  if (q == NULL)
    printf("Link List Is EMPTY\n");
  else {
    while (q != NULL) {
      printf("\nData of node %d is %d", node_no, q->data);
      q = q->next;
      // q = q->prev; // if you want to traverse in backward direction
      node_no++;
    }
  }
}

void create_at_start() {
  p = (struct node *)malloc(sizeof(struct node));
  printf("\nEnter data of node to be created:");
  scanf("%d", &p->data);

  if (start == NULL) {
    start = p;
    p->next = NULL;
    p->prev = NULL;

  } else {
    p->next = start;
    p->prev = NULL;
    start->prev = p;
    start = p;
  }
  printf("Node is Succesfully Created\n");
}

void create_at_end() {
  p = (struct node *)malloc(sizeof(struct node));
  printf("\nEnter data of node to be created:");
  scanf("%d", &p->data);

  if (start == NULL) {
    start = p;
    p->next = NULL;
    p->prev = NULL;
  }

  else {
    q = start;
    while (q->next != NULL) {
      q = q->next;
    }
    q->next = p;
    p->prev = q;
    p->next = NULL;
    last = p; // update the last node
    // update current last node with adding p node
  }
  printf("Node is Succesfully Created\n");
}

void create_at_location() {
  int location, i = 1;
  p = (struct node *)malloc(sizeof(struct node));
  printf("Enter Location to create Node\n");
  scanf("%d", &location);
  printf("\nEnter data of node to be created:");
  scanf("%d", &p->data);

  // At Start if Start==NULL
  if (start == NULL) {
    if (location == 1) {
      start = p;
      p->next = NULL;
      p->prev = NULL;
      printf("Node is succesfully created at start\n");
    } else {
      printf("Link List Is Empty Enter Valid Location\n");
      free(p);
    }
  } else if (location == 1) // create at start if link list have some elements
  {
    p->next = start;
    p->prev = NULL;
    start = p;
    printf("Node is succesfully created at start\n");

  } else // Create at any location  (except start) ,at the end also.
  {
    q = start;
    while (i < location - 1 && q != NULL) {
      q = q->next;
      i++;
    }
    if (q != NULL) {
      p->next = q->next;
      if (q->next != NULL) {
        q->next->prev = p;
      } // Adjusted previous pointer of (q's next) to newly added node p.
      q->next = p;
      p->prev = q;
      printf("Node is succesfully created at location %d\n", location);
    }

    else {
      printf("Enter Vallid Location\n");
      free(p);
    }
  }
}

void delete_at_start() {
  if (start == NULL)
    printf("Delete can not be performed,Link List is empty\n");
  else if (start->next == NULL) {
    p = start;
    start = NULL;
    printf("%d is deleted", p->data);
    free(p);
  } else {
    p = start;
    start = p->next;
    start->prev = NULL;
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
    q->next = NULL; // Removed last node from link list
    printf("%d is deleted\n", p->data);
    free(p);
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
      if (p->next !=
          NULL) // NULL cant point to prev so p->next taken otherwise p!= taken.
      {
        p->next->prev = q;
      }
      printf("%d is deleted at location %d\n", p->data, location);
      free(p);
    } else {
      printf("Enter Vallid Location");
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
  last = third;
  first->data = 1;
  first->next = second;
  first->prev = NULL;

  second->data = 2;
  second->next = third;
  second->prev = first;

  third->data = 3;
  third->next = NULL;
  third->prev = second;

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
      return 0;
    }
  } while (i != 8);

  return 0;
}
