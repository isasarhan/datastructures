#define NULL (void *)0
typedef int element;

typedef struct cell
{
    element data;
    struct cell *next;
} * stack;

stack CreateStack()
{
    return NULL;
}
stack isEmptyStack(stack s)
{
    return (s == NULL);
}
int Push(stack *s, element e)
{
    stack tmp = (stack) malloc(sizeof(struct cell));
    if(!tmp) return 0;
    (tmp)->data = e;
    (tmp)->next = *s;
    (*s) = tmp;
    return 1;
}
int Pop(stack *s){
    if(isEmptyStack(*s)) return 0;
    stack tmp = *s;
    (*s) = (*s)->next;
    free(tmp);
    return 1;

}
int Top(stack s, element *e)
{
    if (isEmptyStack(s))
        return 0;
    *e = s->data;
    return 1;
}
