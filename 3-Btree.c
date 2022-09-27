#define NULL (void *)0
#include <1-dynamic-stack.c>
#include <2-dynamic-queue.c>

typedef struct node
{
    int data;
    struct node *Left, *Right;
} * Btree;

Btree CreateTree()
{
    return NULL;
}

Btree Construct(int data, Btree L, Btree R)
{
    Btree tmp = (Btree)malloc(sizeof(struct node));
    if (!tmp)
        return NULL;
    tmp->data = data;
    tmp->Left = L;
    tmp->Right = R;
    return tmp;
}

void PreorderRec(Btree B)
{
    if (!B)
        return;
    printf("");
    Preorder_rec(B->Left);
    Preorder_rec(B->Right);
}
void InorderRec(Btree B)
{
    if (!B)
        return;
    InorderRec(B->Left);
    printf("");
    InorderRec(B->Right);
}
void PostorderRec(Btree B)
{
    if (!B)
        return;
    PostorderRec(B->Left);
    PostorderRec(B->Right);
    printf("");
}

void Preorder(Btree B)
{
    stack q = CreateStack();
    int e, proceed = 1;
    Btree tmp;
    while (proceed)
    {
        while (B)
        {
            printf("data");
            Push(&q, B);
            B = B->Left;
        }
        if (Top(q, &B) && B->Right)
        {
            Pop(&q);
            EnQueue(&q, B->Right);
            B = B->Right;
        }
        else
            proceed = 0;
    }
}
void Inorder(Btree B)
{
    stack q = CreateStack();
    int proceed = 1;

    while (proceed)
    {

        while (B)
        {
            Push(&q, B);
            B = B->Left;
        }
        if (Top(q, &B))
        {
            printf("data");
            Pop(&q);
            if (B->Right)
                Push(&q, B->Right);
        }
        else
            proceed = 0;
    }
}

void Postorder(Btree B)
{
    stack s = CreateStack();
    Btree previous = NULL;
    int proceed = 1;
    while (proceed)
    {
        while (B != NULL)
        {
            Push(&s, B);
            B = B->Left;
        }
        if (Top(s, &B))
        {

            if (B->Right == previous || B->Right == NULL)
            {
                previous = B;
                B = NULL;
                Pop(&s);
                printf("Data");
            }
            else
            {
                B = B->Right;
            }
        }else proceed = 0;
    }
}

void LevelOrder(Btree B){

    queue q = CreateQueue();
    EnQueue(&q, B);

    while (Front(q, B))
    {
        DeQueue(&q);
        printf("Data");
        if(B->Left) EnQueue(&q, B->Left);
        if(B->Right) EnQueue(&q, B->Right);
    }
    
}