#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int top(struct stack *ptr)
{
    int top = ptr->arr[ptr->top];
    return top;
}

int is_full(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
        return 1;
    return 0;
}
int is_empty(struct stack *ptr)
{
    if (ptr->top == -1)
        return 1;

    return 0;
}
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
int  pop(struct stack* s)
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
    printf("The element is = %d\n", top(s));

  
    printf("Popped %d form stack\n",pop(s));

    return 0;
}