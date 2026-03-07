#include <stdio.h>

int MAX = 5;
int queue[5];
int front = -1;
int rear = -1;

void enqueue() {

    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
    } 
    else {
        if (front == -1)
            front = 0;

        rear++;

        printf("Enter element: ");
        scanf("%d", &queue[rear]);
    }
}

void dequeue() {

    if (front == -1) {
        printf("Queue Underflow\n");
    } 
    else if (front == rear) {
        printf("Deleted element is %d\n", queue[front]);
        front = -1;
        rear = -1;
    } 
    else {
        printf("Deleted element is %d\n", queue[front]);
        front++;
    }
}

void display() {

    int i;

    if (front == -1) {
        printf("Queue is Empty\n");
    } 
    else {
        printf("Queue elements are:\n");

        for (i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }

        printf("\n");
    }
}

int main() {

    int choice;

    do {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        case 4:
            return 0;

        default:
            printf("Invalid choice\n");
        }

    } while (choice != 4);
}
