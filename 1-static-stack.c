// stack static implementation
#define N 20
typedef int element;
typedef struct stack
{
    int data[N];
    int top;
} stack;

stack CreateStack()
{
    stack s;
    s.top = -1;
    return s;
}
int isEmptyStack(stack s)
{
    return s.top == -1;
}

int isFullStack(stack s)
{
    return s.top == N - 1;
}

int Top(stack s, element *e)
{
    if (isEmptyStack(s))
        return 0;
    *e = s.data[s.top];
    return 1;
}
int Push(stack *s, element e)
{
    if (isFullStack(*s))
        return 0;
    s->data[++s->top] = e;
    return 1;
}
int Pop(stack *s)
{
    if (isEmptyStack(*s))
        return 0;
    --s->top;
    return 1;
}
