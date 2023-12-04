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
  else {
    do {
      printf("\nData of node %d is %d", node_no, q->data);
      q = q->next;
      node_no++;
    } while (q!= start);
  }
}

void create_at_start() {
  p = (struct node *)malloc(sizeof(struct node));
  printf("\nEnter data of node to be created:");
  scanf("%d", &p->data);

  if (start == NULL) {
    start = p;
    p->next = p;
    last = start; // or //last=p;

  } else {
    p->next = start;
    start = p;
    last->next = start;
  }
  printf("Node is Succesfully Created\n");
}

void create_at_end() {
  p = (struct node *)malloc(sizeof(struct node));
  printf("\nEnter data of node to be created:");
  scanf("%d", &p->data);

  if (start == NULL) {
    start = p;
    p->next = p;
    last = start;
  }

  else {
    last->next = p;
    p->next = start;
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
      p->next = p;
      last = p; // or //last=start
      printf("Node is succesfully created at start\n");
    } else {
      printf("Link List Is Empty Enter Valid Location\n");
      free(p);
    }
  } else if (location == 1) // create at start if link list have some elements
  {
    p->next = start;
    start = p;
    last->next = p;
    printf("Node is succesfully created at start\n");

  } else // Create at any location  // Will not work at end and start.
  {
    q = start;
    while (i < location - 1 && q != last) {
      q = q->next;
      i++;
    }
    if (q != last) {
      p->next = q->next;
      q->next = p;
      printf("Node is succesfully created at location %d\n", location);
    }
    // to create at end
    else if (i == location - 1 && q == last) {
      last->next = p;
      last = p;
      p->next = start;
    } else {
      printf("Enter Vallid Location\n");
      free(p);
    }
  }
}

void delete_at_start() {
  if (start == NULL)
    printf("Delete can not be performed,Link List is empty\n");
  else if (start->next == start) {
    p = start;
    start = NULL;
    last = NULL;
    printf("%d is deleted", p->data);
    free(p);
  } else {
    p = start;
    start = p->next;
    last->next = start;
    printf("%d is deleted", p->data);
    free(p);
  }
}

void delete_at_end() {
  // LL is empty
  if (start == NULL)
    printf("Link List is empty delete cannot be performed\n");
  // LL having one element
  else if (start->next == start) {
    p = start;
    start = NULL;
    last = NULL;
    printf("%d is deleted at end\n", p->data);
    free(p);
  }
  // Link List having more than one element
  else {
    p = start;
    while (p->next != start) {
      q = p;
      p = p->next;
    }
    q->next = start; // Removed last node from link list
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
    if (start->next == start) {
      start = NULL;
      last = NULL;
    } else {
      start = start->next;
      last->next = start;
    }
    printf("%d is deleted at location %d\n", p->data, location);
    free(p);
  }
  // LL having more than one element // will not work at end (last)
  else if (location > 1) {
    i = 1;
    p = start;
    // setting p at given location
    while (i < location && p != last) {
      q = p;
      p = p->next;
      i++;
    }
    // deleting node
    if (p != last) {
      q->next = p->next;
      printf("%d is deleted at location %d\n", p->data, location);
      free(p);
    }
    // Now we have already set our p at location and if location is at end that
    // means location=i;
    // deleting node
    else if (location == i) {
      p = last;
      q->next = start;
      last = q; // update the last pointer
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

  second->data = 2;
  second->next = third;

  third->data = 3;
  third->next = first;

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
