#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;
void push(){
    
    if(top == MAX - 1) {
        printf("Stack Overflow\n");
    } 
    else {
        top++;
        printf("enter number");
        scanf("%d \n",stack[top]);
        printf("Element pushed successfully\n");
    }
}

void pop() {
    if(top == MAX-1) {
        printf("Stack Underflow\n");
    } 
    else {
        top--;
        printf("Popped element: %d\n", stack[top]);
    }
}

void show() {
    if(top == -1) {
        printf("Stack is empty\n");
    } 
    else {
        printf("Stack elements are:\n");
        for(int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

int main() {
    int choice;

    while(1) {
        printf("\n--- STACK MENU ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Show\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: show(); break;
            case 4: return 0;
            default: printf("Invalid choice\n");
        }
    }
}