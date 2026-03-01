#include <stdio.h>
#include <stdlib.h>

struct node
{
    int item;
    struct node *next;
};

typedef struct node NODE;

NODE *start = NULL;

// Insert at Beginning
void insertAtBeginning()
{
    NODE *ptr = (NODE *)malloc(sizeof(NODE));

    printf("\nEnter the item: ");
    scanf("%d", &ptr->item);

    ptr->next = start;
    start = ptr;

    printf("\nInserted successfully!\n");
}

// Insert at Last
void insertAtLast()
{
    NODE *ptr = (NODE *)malloc(sizeof(NODE));
    NODE *loc;

    printf("\nEnter the item: ");
    scanf("%d", &ptr->item);

    ptr->next = NULL;

    if (start == NULL)
    {
        start = ptr;
    }
    else
    {
        loc = start;
        while (loc->next != NULL)
        {
            loc = loc->next;
        }
        loc->next = ptr;
    }

    printf("\nInserted successfully!\n");
}

// Show List
void show()
{
    NODE *ptr = start;

    if (start == NULL)
    {
        printf("\nList is empty!\n");
    }
    else
    {
        printf("\nLinked List:\n");
        while (ptr != NULL)
        {
            printf("%d -> ", ptr->item);
            ptr = ptr->next;
        }
        printf("NULL\n");
    }
}

// Insert at Position
void insertAtPosition()
{
    NODE *ptr = (NODE *)malloc(sizeof(NODE));
    NODE *loc;
    int pos, count = 1;

    printf("\nEnter position: ");
    scanf("%d", &pos);

    printf("Enter item: ");
    scanf("%d", &ptr->item);

    if (pos == 1)
    {
        ptr->next = start;
        start = ptr;
        printf("\nInserted successfully!\n");
        return;
    }

    loc = start;

    while (loc != NULL && count < pos - 1)
    {
        loc = loc->next;
        count++;
    }

    if (loc == NULL)
    {
        printf("\nInvalid position!\n");
        free(ptr);
    }
    else
    {
        ptr->next = loc->next;
        loc->next = ptr;
        printf("\nInserted successfully!\n");
    }
}

// Delete at Beginning
void deleteAtBeginning()
{
    NODE *ptr;

    if (start == NULL)
    {
        printf("\nList is empty!\n");
    }
    else
    {
        ptr = start;
        start = ptr->next;
        free(ptr);
        printf("\nDeleted successfully!\n");
    }
}

// Delete at Last
void deleteAtLast()
{
    NODE *ptr = start;
    NODE *loc = NULL;

    if (start == NULL)
    {
        printf("\nList is empty!\n");
    }
    else if (start->next == NULL)
    {
        free(start);
        start = NULL;
        printf("\nDeleted successfully!\n");
    }
    else
    {
        while (ptr->next != NULL)
        {
            loc = ptr;
            ptr = ptr->next;
        }

        loc->next = NULL;
        free(ptr);
        printf("\nDeleted successfully!\n");
    }
}

// Delete at Position
void deleteAtPosition()
{
    NODE *ptr = start;
    NODE *loc = NULL;
    int pos, count = 1;

    if (start == NULL)
    {
        printf("\nList is empty!\n");
        return;
    }

    printf("\nEnter position: ");
    scanf("%d", &pos);

    if (pos == 1)
    {
        start = ptr->next;
        free(ptr);
        printf("\nDeleted successfully!\n");
        return;
    }

    while (ptr != NULL && count < pos)
    {
        loc = ptr;
        ptr = ptr->next;
        count++;
    }

    if (ptr == NULL)
    {
        printf("\nInvalid position!\n");
    }
    else
    {
        loc->next = ptr->next;
        free(ptr);
        printf("\nDeleted successfully!\n");
    }
}

int main()
{
    int choice;

    do
    {
        printf("1. Insert At Beginning\n");
        printf("2. Insert At Last\n");
        printf("3. Show List\n");
        printf("4. Insert At Position\n");
        printf("5. Delete At Beginning\n");
        printf("6. Delete At Last\n");
        printf("7. Delete At Position\n");
        printf("8. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insertAtBeginning();
            break;
        case 2:
            insertAtLast();
            break;
        case 3:
            show();
            break;
        case 4:
            insertAtPosition();
            break;
        case 5:
            deleteAtBeginning();
            break;
        case 6:
            deleteAtLast();
            break;
        case 7:
            deleteAtPosition();
            break;
        case 8:
            printf("\nProgram Ended.\n");
            break;
        default:
            printf("\nInvalid Choice!\n");
        }

    } while (choice != 8);

    return 0;
}