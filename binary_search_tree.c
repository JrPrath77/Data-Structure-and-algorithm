// BINARY SEARCH TREE
#include <stdio.h>
#include <stdlib.h>

int n, key;

struct node {
  int data;
  struct node *lchild;
  struct node *rchild;
};

typedef struct node Node;
Node *root = NULL, *p;

Node *create(Node *p, int data) {
  if (p == NULL) {
    p = (Node *)malloc(sizeof(Node));
    p->data = data;
    p->lchild = NULL;
    p->rchild = NULL;
  } else if (data < p->data) {
    p->lchild = create(p->lchild, data);
  } else {
    p->rchild = create(p->rchild, data);
  }
  return p;
}

// Traversal
//L N R
void inorder(Node *p) {
  if (p != NULL) {
    inorder(p->lchild);
    printf("--> %d ", p->data);
    inorder(p->rchild);
  }
}

//N L R
void preorder(Node *p) {
  if (p != NULL) {
    printf("--> %d ", p->data);
    preorder(p->lchild);
    preorder(p->rchild);
  }
}

//L R N
void postorder(Node *p) {
  if (p != NULL) {
    postorder(p->lchild);
    postorder(p->rchild);
    printf("--> %d ", p->data);
  }
}

void search(Node *p, int key) {
  if (p == NULL) {
    printf("\nSearch unsuccessful\n");
  } else if (key == p->data) {
    printf("Search successful, %d is found\n", key);
  } else if (key < p->data) {
    search(p->lchild, key);
  } else if (key > p->data) {
    search(p->rchild, key);
  }
}

int main() {
  int choice;
  do {
    printf("\n1: Creating a node\n2: Inorder Traverse\n3: Preorder "
           "Traverse\n4: Postorder Traverse\n5: Search a node\n6: Exit: ");
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
      printf("\nPreorder traversal: ");
      preorder(root);
      break;

    case 4:
      printf("\nPostorder traversal: ");
      postorder(root);
      break;

    case 5:
      printf("\nEnter the element to search: ");
      scanf("%d", &key);
      search(root, key);
      break;

    case 6: // Exit
      break;

    default:
      printf("Invalid choice!");
    }
  } while (choice != 6);
  return 0;
}
