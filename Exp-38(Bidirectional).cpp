#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
};
typedef struct Node Node;
Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
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
    newNode->prev = current;
}
void printForward(Node* head)
{
    Node* current = head;
    while (current != NULL)
	{
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
void printBackward(Node* tail)
{
    Node* current = tail;
    while (current != NULL)
	{
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
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
    printf("Forward traversal: ");
    printForward(head);
    Node* tail = head;
    while (tail->next != NULL)
	{
        tail = tail->next;
    }
    printf("Backward traversal: ");
    printBackward(tail);
    freeList(head);
    return 0;
}
