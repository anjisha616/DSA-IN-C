#include <stdio.h>

int MAX = 5;
int cqueue[5];
int front = -1;
int rear = -1;

void cenqueue() {

    if (front == (rear + 1) % MAX) {
        printf("Queue FULL\n");
    } 
    else {

        if (front == -1) {
            front = 0;
        }

        rear = (rear + 1) % MAX;

        printf("Enter number: ");
        scanf("%d", &cqueue[rear]);

        printf("Success\n");
    }
}

void cdequeue() {

    if (front == -1) {
        printf("Queue Empty\n");
    } 
    else if (front == rear) {

        printf("Deleted element: %d\n", cqueue[front]);

        front = -1;
        rear = -1;
    } 
    else {

        printf("Deleted element: %d\n", cqueue[front]);

        front = (front + 1) % MAX;
    }
}

void display() {

    int i;

    if (front == -1) {
        printf("Queue is empty\n");
    } 
    else {

        i = front;

        while (i != rear) {
            printf("%d ", cqueue[i]);
            i = (i + 1) % MAX;
        }

        printf("%d", cqueue[rear]);
    }

    printf("\n");
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
            cenqueue();
            break;

        case 2:
            cdequeue();
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