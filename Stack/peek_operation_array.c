#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

// O(1)
int peek(struct stack *st, int i)
{
    int arrayidx = st->top - i + 1;
    if (arrayidx < 0)
    {
        printf("Invalid index\n");
        return -1;
    }
    return st->arr[arrayidx];
}

// O(1)
int top(struct stack *ptr)
{
    int top = ptr->arr[ptr->top];
    return top;
}
int bottom(struct stack *ptr)
{

    // O(1)
    if (ptr->top == -1)
    {
        printf("The stack is empty!\n");
        return -1;
    }
    return ptr->arr[0];
}
// O(1)
int is_full(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
        return 1;
    return 0;
}

// O(1)
int is_empty(struct stack *ptr)
{
    if (ptr->top == -1)
        return 1;

    return 0;
}

// O(1)
void push(int data, struct stack *a)
{
    if (is_full(a))
    {
        printf("Stack overflow\n");
        return;
    }
    a->top++;
    a->arr[a->top] = data;
}

// O(1)
int pop(struct stack *s)
{
    if (is_empty(s))
    {
        printf("Stack is underflow!\n");
        return -1;
    }
    int val = s->arr[s->top];
    s->top--;

    return val;
}

// O(n)
void Traverse(int n, struct stack *s)
{
    for (int i = 0; i <= n; i++)
    {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

int main()
{

    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    push(5, s);
    push(10, s);
    push(15, s);
    push(17, s);

    Traverse(s->top, s);

    // for(int j=1;j<=s->top +1;j++)
    // printf("position 1: %d ,value: %d\n",j,peek(s,j));
    printf("%d\n", bottom(s));

    return 0;
}