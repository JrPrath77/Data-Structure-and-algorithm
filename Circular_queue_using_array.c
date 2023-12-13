#include<stdio.h>
# define N 5  // macro definition; you can change the size of the array from here.

int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x) {
    if(front==-1 && rear==-1){
        front=rear=0;
        queue[rear]=x;
        printf("%d is enqueued\n",queue[rear]);
    }
    else if((rear+1)%N==front){
        printf("Queue overflow\n");
    }
    else{
        rear=(rear+1)%N;
        queue[rear]=x;
        printf("%d is enqueued\n",queue[rear]);
    }
}

void dequeue() {
   if(front==-1 && rear==-1){
    printf("Queue Underflow\n");
   }
   else if(front==rear){
    printf("%d is dequeued\n",queue[front]);
    front=rear=-1;
   }
   else{
    printf("%d is dequeued\n",queue[front]);
    front=(front+1)%N;
   }

}

void display() {
    int i=front;

    if(front==-1 && rear==-1){
        printf("Queue is empty\n");
    }
    else{
        printf("Queue is: ");
        while(i!=rear){
            printf("%d\t",queue[i]);
            i=(i+1)%N;
        }
        printf("%d",queue[rear]);
    }
}

void peek() {
    printf("%d is the peek element\n", queue[front]);
}

int main() {
    int choice, a;

    do {
        printf("\nEnter Choice: -\n");
        printf("1.Enqueue\n2.Dequeue\n3.Traverse\n4.Peek\n5.Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Data:");
                scanf("%d", &a);
                enqueue(a);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
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
