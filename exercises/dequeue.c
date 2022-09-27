#define NULL (void *)0
typedef int element;
typedef struct cell
{
    element data;
    struct cell *next;
} * cell;

typedef struct dequeue
{
    cell *rear, *front;
} dequeue;

dequeue CreateDeQueue()
{
    dequeue q;
    q.front = q.rear = NULL;
    return d;
}

int isEmptyDeQueue(dequeue q)
{
    return (q.front == NULL);
}
int EnQueueFront(dequeue* q, element e)
{
    cell tmp = (cell)malloc(sizeof(struct cell));
    if (!tmp)
        return 0;
    tmp->data = e;
    tmp->next = q->front;
    q->front = tmp;
    return 1;
}