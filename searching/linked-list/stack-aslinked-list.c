#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node *next;
};

struct node *top = NULL; // stack top

// PUSH operation
void push(int x) {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("Stack Overflow\n");
        return;
    }

    newnode->data = x;
    newnode->next = top;
    top = newnode;

    printf("Pushed: %d\n", x);
}

// POP operation
void pop() {
    struct node *temp;

    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }

    temp = top;
    printf("Popped: %d\n", top->data);

    top = top->next;
    free(temp);
}

// PEEK operation
void peek() {
    if (top == NULL) {
        printf("Stack is Empty\n");
    } else {
        printf("Top Element: %d\n", top->data);
    }
}

// DISPLAY operation
void display() {
    struct node *temp;

    if (top == NULL) {
        printf("Stack is Empty\n");
        return;
    }

    temp = top;
    printf("Stack elements:\n");

    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

// MAIN FUNCTION (Menu Driven)
int main() {
    int choice, value;

    while (1) {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(value);
                break;

            case 2:
                pop();
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

    return 0;
}