#include <stdio.h>
#include <stdlib.h>
struct Queue
{
    int* array;
    int front, rear, size;
};
struct Queue* createQueue(int size)
{
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->array = (int*)malloc(size * sizeof(int));
    queue->front = queue->rear = -1;
    queue->size = size;
    return queue;
}
int isEmpty(struct Queue* queue) {
    return queue->front == -1;
}
void enqueue(struct Queue* queue, int item)
{
    if (queue->rear == queue->size - 1)
	{
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(queue))
	{
        queue->front = queue->rear = 0;
    } else {
        queue->rear++;
    }
    queue->array[queue->rear] = item;
}
int dequeue(struct Queue* queue)
{
    if (isEmpty(queue))
	{
        printf("Queue is empty\n");
        return -1;
    }
    int item = queue->array[queue->front];
    if (queue->front == queue->rear)
	{
        queue->front = queue->rear = -1;
    } else
	{
        queue->front++;
    }
    return item;
}
struct Stack
{
    struct Queue* q1;
    struct Queue* q2;
};
struct Stack* createStack(int size)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->q1 = createQueue(size);
    stack->q2 = createQueue(size);
    return stack;
}
void push(struct Stack* stack, int item) {
    enqueue(stack->q1, item);
}
int pop(struct Stack* stack)
{
    if (isEmpty(stack->q1))
	{
        printf("Stack is empty\n");
        return -1;
    }
    while (stack->q1->front != stack->q1->rear)
	{
        enqueue(stack->q2, dequeue(stack->q1));
    }
    int item = dequeue(stack->q1);
    struct Queue* temp = stack->q1;
    stack->q1 = stack->q2;
    stack->q2 = temp;
    return item;
}
int main() 
{
    struct Stack* stack = createStack(5);
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    printf("Popped: %d\n", pop(stack));
    printf("Popped: %d\n", pop(stack));
    push(stack, 4);
    printf("Popped: %d\n", pop(stack));
    printf("Popped: %d\n", pop(stack));
    return 0;
}
