#define N 20
#define NULL (void *)0

typedef int element;
typedef struct cell
{
    int data;
    struct cell *next;
};
typedef struct queue
{
    struct cell *front, *rear;
} queue;

queue CreateQueue()
{
    queue q;
    q.front = q.rear = NULL;
    return q;
}

int isEmptyQueue(queue q)
{
    return q.front == NULL;
}
int EnQueue(queue *q, element e)
{
    struct cell *tmp;
    tmp = (struct cell *)malloc(sizeof(struct cell));
    if (tmp == NULL)
        return 0;
    tmp->data = e;
    tmp->next = NULL;
    if (q->rear == NULL)
    {
        q->rear = tmp;
    }
    else
    {
        q->rear->next = tmp;
        q->rear = q->rear->next;
    }
}
int DeQueue(queue *q)
{
    if (isEmptyQueue(*q))
        return 0;
    struct cell *tmp = q->front;
    q->front = q->front->next;
    free(tmp);
}
int Front(queue q, element *e){
    if(isEmptyQueue(q))return 0;

    *e = q.front->data;
    return 1;
}