#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *next;
};

// Front and Rear pointers
struct node *front = NULL;
struct node *rear = NULL;

// ENQUEUE operation
void enqueue(int x) {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("Queue Overflow\n");
        return;
    }

    newnode->data = x;
    newnode->next = NULL;

    if (front == NULL && rear == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }

    printf("Enqueued: %d\n", x);
}

// DEQUEUE operation
void dequeue() {
    struct node *temp;

    if (front == NULL) {
        printf("Queue Underflow\n");
        return;
    }

    temp = front;
    printf("Dequeued: %d\n", front->data);

    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
}

// PEEK operation
void peek() {
    if (front == NULL) {
        printf("Queue is Empty\n");
    } else {
        printf("Front Element: %d\n", front->data);
    }
}

// DISPLAY operation
void display() {
    struct node *temp;

    if (front == NULL) {
        printf("Queue is Empty\n");
        return;
    }

    temp = front;
    printf("Queue elements:\n");

    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

// MAIN FUNCTION (Menu Driven)
int main() {
    int choice, value;

    while (1) {
        printf("\n--- QUEUE MENU ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

   
}