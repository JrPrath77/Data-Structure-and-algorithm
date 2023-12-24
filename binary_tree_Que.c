#include <stdio.h>
#include <stdlib.h>

int n;
struct node {
  int data;
  struct node *lchild;
  struct node *rchild;
};  

typedef struct node Node;
Node *root = NULL;

Node *create(Node *p, int data) {
  if (p == NULL) {
    p = (Node *)malloc(sizeof(Node));
    p->data = data;
    p->lchild = p->rchild = NULL;  // Initialize both children to NULL
  } else if (data < p->data) {
    p->lchild = create(p->lchild, data);
  } else {
    p->rchild = create(p->rchild, data);
  }
  return p;
}

void inorder(Node *p) {
  if (p != NULL) {
    inorder(p->lchild);
    printf("--> %d ", p->data);
    inorder(p->rchild);
  }
}

int sum_of_left_leaves(Node *p) {
  if (p == NULL) {
    return 0;
  }

  if (p->lchild != NULL && p->lchild->lchild == NULL && p->lchild->rchild == NULL) {
    // If the current node has a left child that is a leaf, add its value
    return p->lchild->data + sum_of_left_leaves(p->rchild);  // Explore only the right subtree
  } else {
    return sum_of_left_leaves(p->lchild) + sum_of_left_leaves(p->rchild);
  }
}


int main() {
  int choice;
  int total;
  do {
    printf("\n1: Creating a node\n2: Inorder Traverse\n3: Sum of "
           "left childs\n4: Exit: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter the element: ");
        scanf("%d", &n);
        root = create(root, n);
        break;

      case 2:
        printf("\nInorder traversal: ");
        inorder(root);
        break;

      case 3:
        total = sum_of_left_leaves(root);
        printf("Sum of all left leaves in the given binary tree is %d\n", total);
        break;
    
      case 4: // Exit
        break;

      default:
        printf("Invalid choice!\n");
        break;
    }
  } while (choice != 4);

  return 0;
}
