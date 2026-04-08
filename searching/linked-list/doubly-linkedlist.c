#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertFront(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = head;
    if (head != NULL) head->prev = newNode;
    return newNode;
}

struct Node* insertEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) return newNode;
    struct Node* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

struct Node* deleteNode(struct Node* head, int value) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != value)
        temp = temp->next;
    if (temp == NULL) return head;
    if (temp->prev != NULL) temp->prev->next = temp->next;
    else head = temp->next;
    if (temp->next != NULL) temp->next->prev = temp->prev;
    free(temp);
    return head;
}

void displayForward(struct Node* head) {
    printf("Forward:  ");
    while (head != NULL) { printf("%d ", head->data); head = head->next; }
    printf("\n");
}

void displayBackward(struct Node* head) {
    if (head == NULL) return;
    while (head->next != NULL) head = head->next;
    printf("Backward: ");
    while (head != NULL) { printf("%d ", head->data); head = head->prev; }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    head = insertEnd(head, 10);
    head = insertEnd(head, 25);
    head = insertEnd(head, 40);
    head = insertFront(head, 5);
    displayForward(head);    // 5 10 25 40
    displayBackward(head);   // 40 25 10 5
    head = deleteNode(head, 25);
    displayForward(head);    // 5 10 40
    return 0;
}