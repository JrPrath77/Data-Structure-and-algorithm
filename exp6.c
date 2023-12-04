#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

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

int searchLL(struct node *LL1, struct node *LL2) {
    while (LL2 != NULL) {
        struct node *temp1 = LL1;
        struct node *temp2 = LL2;
        while (temp1 != NULL && temp2 != NULL && temp1->data == temp2->data) {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        if (temp1 == NULL) {
            return 1; // Found
        }
        LL2 = LL2->next;
    }
    return 0; // Not found
}

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

int main() {
    struct node *start1 = NULL, *start2 = NULL;
    int no_nodes_in_LL1, no_nodes_in_LL2;

    Enter_data(&start1, &no_nodes_in_LL1);
    Enter_data(&start2, &no_nodes_in_LL2);

    printf("\nFirst Linked List:");
    displayLL(start1);
    printf("\n");

    printf("\nSecond Linked List:");
    displayLL(start2);
    printf("\n");

    if (searchLL(start1, start2)) {
        printf("\nFirst Link List Found In second link List\n");
    } else {
        printf("\nFirst Link List Not Found In second link List\n");
    }

    return 0;
}
