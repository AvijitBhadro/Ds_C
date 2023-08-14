#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *nxt;
};

struct Node *CreateNewNode(int data)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->nxt = NULL;
    newnode->data = data;

    return newnode;
}
int is_empty(struct Node *top)
{
    if (top == NULL)
        return 1;
    return 0;
}
int is_full()
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    if (n == NULL)
    {
        free(n);
        return 1;
    }

    return 0;
}
struct Node *push(int value, struct Node *top)
{
    struct Node *newnode = CreateNewNode(value);

    if (is_full())
    {
        printf("Stack overflow\n");
        free(newnode);
        return NULL;
    }
    if (top == NULL)
    {
        top = newnode;
        return top;
    }
    struct Node *a = top;
    newnode->nxt = a;
    top = newnode;
    return top;
}
struct Node *pop(struct Node *top)
{
    // if (top == NULL)
    // {
    //     printf("Stack underflow\n");
    //     return NULL;
    // }
    struct Node *n = top;
    top = top->nxt;
    int x = n->data;
    printf("%d\n",x);
    free(n);
    return top;
}


void stacktraversal(struct Node *top)
{
    struct Node *a = top;
    if (a == NULL)
        return;
    while (a != NULL)
    {
        printf("%d ", a->data);
        a = a->nxt;
    }
}

int main()
{
    struct Node *top;
    top = push(10, top);
    top = push(13, top);
    top = push(15, top);
    top = push(20, top);
    top = push(25, top);
    stacktraversal(top);
    top = pop(top);
    stacktraversal(top);
    return 0;
}