// Priority Queue
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5  // size of queue

typedef struct {
    int data;
    int priority;
} Element;

typedef struct {
    Element elements[MAX_SIZE];
    int front, rear;
    int priorityType;  // 1 for Highest Number highest priority, 2 for Lowest Number highest priority
} PriorityQueue;

// Function to initialize the priority queue
void initializeQueue(PriorityQueue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the priority queue is empty
int isEmpty(PriorityQueue *queue) {
    return (queue->front == -1 && queue->rear == -1);
}

// Function to check if the priority queue is full
int isFull(PriorityQueue *queue) {
    return (queue->rear == MAX_SIZE - 1);
}

// Function to enqueue an element with priority
void enqueue(PriorityQueue *queue, int data, int priority) {
    if (isFull(queue)) {
        printf("Priority Queue is full. Cannot enqueue.\n");
        return;
    }

    Element newElement;
    newElement.data = data;
    newElement.priority = priority;

    // If the queue is empty
    if (isEmpty(queue)) {
        queue->front = 0;
        
        queue->rear = 0;
        queue->elements[0] = newElement;
    } else {
        int i;
        // Find the correct position to insert based on priority
        for (i = queue->rear; i >= 0; i--) {
            if ((queue->priorityType == 1 && newElement.priority > queue->elements[i].priority) ||
                (queue->priorityType == 2 && newElement.priority < queue->elements[i].priority)) {
                // Shift elements to make space for the new element
                queue->elements[i + 1] = queue->elements[i];
            } else {
                break;
            }
        }
        // Insert the new element
        queue->elements[i + 1] = newElement;
        // Update rear index
        queue->rear++;
    }

    printf("Enqueued: %d with Priority: %d\n", data, priority);
}

// Function to dequeue the element with the highest priority
void dequeue(PriorityQueue *queue) {
    if (isEmpty(queue)) {
        printf("Priority Queue is empty. Cannot dequeue.\n");
        return;
    }

    Element dequeuedElement = queue->elements[queue->front];

    // If there is only one element in the queue
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        // Move the front index to the next element
        queue->front++;
    }

    printf("Dequeued: %d with Priority: %d\n", dequeuedElement.data, dequeuedElement.priority);
}

// Function to peek at the element that is going to be dequeued
void peek(PriorityQueue *queue) {
    if (isEmpty(queue)) {
        printf("Priority Queue is empty. Cannot peek.\n");
        return;
    }

    Element peekedElement = queue->elements[queue->front];

    printf("Peek Element: %d with Priority: %d\n", peekedElement.data, peekedElement.priority);
}

// Function to display the elements in the priority queue
void display(PriorityQueue *queue) {
    if (isEmpty(queue)) {
        printf("Priority Queue is empty.\n");
        return;
    }

    printf("Priority Queue Elements: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("(%d, %d) ", queue->elements[i].data, queue->elements[i].priority);
    }
    printf("\n");
}

int main() {
    PriorityQueue queue;
    initializeQueue(&queue);

    printf("Select Priority Type:\n");
    printf("1. Highest Number highest priority\n");
    printf("2. Lowest Number highest priority\n");
    printf("Enter your choice: ");
    scanf("%d", &queue.priorityType);

    int choice;
    do {
        printf("\nOperations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int data, priority;
                printf("Enter data and priority: ");
                scanf("%d %d", &data, &priority);
                enqueue(&queue, data, priority);
                break;
            }
            case 2:
                dequeue(&queue);
                break;
            case 3:
                display(&queue);
                break;
            case 4:
                peek(&queue);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 5);

    return 0;
}
