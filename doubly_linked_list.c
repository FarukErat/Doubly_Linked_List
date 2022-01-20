#include <stdio.h>
#include <stdlib.h>

// building node
typedef struct node
{
    int value;
    struct node *next;
    struct node *previous;
} Node;

// building list for nodes
typedef struct list
{
    Node *firstNode;
    Node *lastNode;
    int memberNumber;
} List;


// definitions for printing
enum howToPrint
{
    FORWARD = 0,
    BACKWARD = 1
};

void initialize(List *list);
void clear(List *list);
void append(List *list, int member);
void pop(List *list, int index);
void printList(List *list, int isBackward);
void printMenu();

int main()
{
    List list;
    initialize(&list);

    int value;
    unsigned int choice, index;
    
    printf("\n----------\n  [Menu]   \n----------\n");

    while (1)
    {
        printMenu();
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            clear(&list);
            printf("The program has ended.");
            exit(EXIT_SUCCESS);
            break;
        case 1:
            printf("Enter a number to append: ");
            scanf("%d", &value);
            append(&list, value);
            break;
        case 2:
            printf("\nEnter the index to remove an element: ");
            scanf("%d", &index);
            pop(&list, index);
            break;
        case 3:
            printList(&list, FORWARD);
            break;
        case 4:
            printList(&list, BACKWARD);
            break;
        default:
            printf("Invalid choice!\nEnter a valid one");
            break;
        }
    }
    return EXIT_SUCCESS;
}

void initialize(List *list)
{
    list->firstNode = (Node *)malloc(sizeof(Node));
    list->firstNode->previous = NULL;
    list->firstNode->next = NULL;
    list->lastNode = list->firstNode;
    list->memberNumber = 0;
}

void append(List *list, int newElement)
{
    if (list->memberNumber == 0)
    {
        list->firstNode->value = newElement;
        list->memberNumber++;
        return;
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = newElement;

    list->lastNode->next = newNode;
    newNode->previous = list->lastNode;
    list->lastNode = newNode;
    list->lastNode->next = NULL;
    list->memberNumber++;
}

void pop(List *list, int index)
{
    if (list->memberNumber == 0 || index > list->memberNumber)
    {
        printf("\nInvalid value!");
        return;
    }

    if (list->memberNumber == 1)
    {
        list->memberNumber--;
        printf("\nThe number has been removed");
        return;
    }

    Node *ptr = NULL;

    if (index == 1)
    {
        ptr = list->firstNode;
        list->firstNode = list->firstNode->next;
        list->firstNode->previous = NULL;
        list->memberNumber--;
        free(ptr);
        return;
    }

    if (index == list->memberNumber)
    {
        ptr = list->lastNode;
        list->lastNode = list->lastNode->previous;
        list->lastNode->next = NULL;
        list->memberNumber--;
        free(ptr);
        return;
    }

    int i = 1;
    ptr = list->firstNode;
    while (i < index - 1 && ptr->next != NULL)
    {
        ptr = ptr->next;
        i++;
    }

    Node *nodeToRemove = ptr->next;
    nodeToRemove->previous->next = nodeToRemove->next;
    nodeToRemove->next->previous = nodeToRemove->previous;
    free(nodeToRemove);
    list->memberNumber--;
    printf("\nThe number has been removed");
}

void printList(List *list, int isBackward)
{
    if (list->memberNumber == 0)
    {
        printf("\nThe list is empty!");
        return;
    }

    Node *ptr;
    if (isBackward)
    {
        ptr = list->lastNode;
        printf("%d\n", ptr->value);
        while (ptr->previous != NULL)
        {
            ptr = ptr->previous;
            printf("%d\n", ptr->value);
        }
    }
    else
    {
        ptr = list->firstNode;
        printf("%d\n", ptr->value);
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
            printf("%d\n", ptr->value);
        }
    }
}

void clear(List *list)
{
    Node *ptr = list->firstNode;
    Node *nodeToRemove;

    while (ptr->next != NULL)
    {
        nodeToRemove = ptr;
        ptr = ptr->next;
        free(nodeToRemove);
    }
    free(ptr);
}

void printMenu()
{
    printf("\n1. add a value\n");
    printf("2. remove a value\n");
    printf("3. print the list forward\n");
    printf("4. print the list backward\n");
    printf("0. EXIT\n");
    printf("Enter your choice: ");
}