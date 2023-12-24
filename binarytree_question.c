#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct node {
  int data;
  struct node *lchild;
  struct node *rchild;
  struct node *parent;
};

typedef struct node Node;
Node *root = NULL;

Node *create(Node *p, int data, Node *parent) {
  if (p == NULL) {
    p = (Node *)malloc(sizeof(Node));
    p->data = data;
    p->lchild = NULL;
    p->rchild = NULL;
    p->parent = parent;
  } else if (data < p->data) {
    p->lchild = create(p->lchild, data, p);
  } else {
    p->rchild = create(p->rchild, data, p);
  }
  return p;
}

Node *findNode(Node *p, int value) {
  if (p == NULL || p->data == value) {
    return p;
  }

  Node *foundNode = findNode(p->lchild, value);
  if (foundNode) {
    return foundNode;
  }

  return findNode(p->rchild, value);
}

void inorder(Node *p) {
  if (p != NULL) {
    inorder(p->lchild);
    printf("--> %d ", p->data);
    inorder(p->rchild);
  }
}

void leftLeavesSumRec(Node *root, bool isLeft, int *sum) {
  if (!root) return;

  if (!root->lchild && !root->rchild && isLeft) *sum += root->data;

  leftLeavesSumRec(root->lchild, true, sum);
  leftLeavesSumRec(root->rchild, false, sum);
}

int leftLeavesSum(Node *root) {
  int sum = 0;
  leftLeavesSumRec(root, false, &sum);
  return sum;
}

int main() {
  int choice;
  int total;
  int n;
  do {
    printf("\n1: Creating a node\n2: Inorder Traverse\n3: Sum of left childs\n4: Exit: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter the element: ");
        scanf("%d", &n);
        if (root == NULL) {
          root = create(root, n, NULL);
        } else {
          printf("Enter the value of the parent node: ");
          int parentValue;
          scanf("%d", &parentValue);

          Node *parentNode = findNode(root, parentValue);
          if (parentNode) {
            if (n < parentNode->data) {
              parentNode->lchild = create(parentNode->lchild, n, parentNode);
            } else {
              parentNode->rchild = create(parentNode->rchild, n, parentNode);
            }
          } else {
            printf("Parent node not found.\n");
          }
        }
        break;

      case 2:
        printf("\nTraversal: ");
        inorder(root);
        break;

      case 3:
        total = leftLeavesSum(root);
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
