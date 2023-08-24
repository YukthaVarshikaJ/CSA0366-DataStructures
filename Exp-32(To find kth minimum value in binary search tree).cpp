#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
void kthMinimumUtil(struct Node* root, int k, int* count, int* result)
{
    if (root == NULL || *count >= k)
        return;
    kthMinimumUtil(root->left, k, count, result);
    (*count)++;
    if (*count == k) 
	{
        *result = root->data;
        return;
    }
    kthMinimumUtil(root->right, k, count, result);
}
int kthMinimum(struct Node* root, int k)
{
    int count = 0;
    int result = -1;
    kthMinimumUtil(root, k, &count, &result);
    return result;
}
int main()
{
    struct Node* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(6);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    root->right->left = newNode(5);
    root->right->right = newNode(7);
    int k = 3;
    printf("The %dth minimum value is: %d\n", k, kthMinimum(root, k));
    return 0;
}
