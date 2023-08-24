#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node* next;
};
typedef struct Node Node;
Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertAtEnd(Node** head, int data)
{
    Node* newNode = createNode(data);
    if (*head == NULL)
	{
        *head = newNode;
        return;
    }
    Node* current = *head;
    while (current->next != NULL)
	{
        current = current->next;
    }
    current->next = newNode;
}
void printList(Node* head)
{
    Node* current = head;
    while (current != NULL)
	{
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
Node* reverseList(Node* head)
{
    Node* prev = NULL;
    Node* current = head;
    Node* nextNode = NULL;
    while (current != NULL)
	{
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    return prev;
}
void freeList(Node* head)
{
    while (head != NULL)
	{
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}
int main()
{
    Node* head = NULL;
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    insertAtEnd(&head, 4);
    printf("Original list: ");
    printList(head);
    head = reverseList(head);
    printf("Reversed list: ");
    printList(head);
    freeList(head);
    return 0;
}
