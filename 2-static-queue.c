#define N 10

typedef int element;
typedef struct queue
{
    element data[N];
    int rear, front;
} queue;

queue CreateQueue()
{
    queue q;
    q.front = 0;
    q.rear = -1;
    return q;
}
int EnQueue(queue *q, element e)
{
    if (isFullQueue(*q))
        return 0;
    q->rear = (q->rear + 1) % N;
    q->data[q->rear] = e;
    return 1;
}
int DeQueue(queue *q)
{
    if (isEmptyQueue(*q))
        return 0;
    q->front = (q->front + 1) % N;
    return 1;
}
int isEmptyQueue(queue q)
{
    return q.front = (q.rear + 1) % N;
}
int isFullQueue(queue q)
{
    return q.front = (q.rear + 2) % N;
}
int Front(queue q, element *e)
{
    if (isEmptyQueue(q))
        return 0;
    *e = q.data[q.front];
}