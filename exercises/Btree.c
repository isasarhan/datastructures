#include <1-dynamic-stack.c>
#include <2-dynamic-queue.c>
typedef struct node
{
    int data;
    int level;
    struct node *Left, *Right;
} * Btree;

int max_rec(Btree B)
{
    if (!B)
        return -1;
    return max(B->data, max(max_rec(&B->Left), max_rec(&B->Right)))
}
int max_itr_queue(Btree B)
{
    int max = -1;
    queue q = CreateQueue();
    Btree tmp;
    EnQueue(&q, B);
    while (Front(q, &tmp))
    {
        DeQueue(&q);
        if (tmp->data > max)
            max = tmp->data;
        if (tmp->Left)
            EnQueue(&q, tmp->Left);
        if (tmp->Right)
            EnQueue(&q, tmp->Right);
    }
}
int max_itr_stack(Btree B)
{
    int max = -1;
    stack s = CreateStack();
    Btree tmp;
    int proceed = 1;
    while (proceed)
    {
        while (B)
        {
            Push(&s, B);
            B = B->Left;
        }
        if (Top(s, &B))
        {
            Pop(&s);
            if (B->data > max)
                max = B->data;
            if (B->Right)
                Push(&s, B->Right);
        }
        else
            proceed = 0;
    }
}
int Height(Btree B)
{
    if (!B)
        return 0;
    return 1 + max(Height(B->Right), Height(B->Left));
}

int balanced(Btree B)
{
    if (!B)
        return 1;

    return balanced(B->Left) && balanced(B->Right) && abs(Height(B->Left) - Height(B->Right)) <= 1;
}

int width(Btree B)
{
    int level = 0;
    int count = 0;
    int max = 0;
    if (!B)
        return 0;
    queue q = CreateQueue();
    EnQueue(&q, B);
    B->level = 0;
    while (Front(q, &B))
    {
        if (level = B->level)
        {
            count++;
        }
        else
        {
            if (max < count)
                max = count;
            count = 1;
            level = B->level;
        }
        if (B->Left)
        {
            B->Left->level = B->level + 1;
            EnQueue(&q, B->Left);
        }
        if (B->Right)
        {
            B->Right->level = B->level + 1;
            EnQueue(&q, B->Right);
        }
    }
}

void zigzag(Btree B)
{
    stack even, odd;
    even = CreateStack();
    odd = CreateStack();
    int proceed = 1;
    Push(&even, B);
    while (proceed)
    {

        while (Top(even, &B))
        {
            Pop(&even);
            printf("data");
            if (B->Left)
                Push(&odd, B->Left);
            if (B->Right)
                Push(&odd, B->Right);
        }
        while (Top(odd, &B))
        {
            Pop(&odd);
            printf("Data");
            if (B->Right)
                Push(&odd, B->Right);
            if (B->Left)
                Push(&odd, B->Left);
        }
        if (isEmptyStack(even) && isEmptyStack(odd))
            proceed = 0;
    }
}
int deepest(Btree B, int E)
{
    return deepest_h(B, E, 0);
}
int deepest_h(Btree B, int E, int level)
{
    int x;
    if (!B)
        return 0;
    x = max(deepest_h(B->Left, E, level + 1), deepest_h(B->Right, E, level + 1));
    if (B->data == E)
        return max(x, level);
}

int pathWithSum(Btree B, int sum)
{
    if (!B)
        return sum == 0;

    int remain = sum - B->data;

    if (B->Right && B->Left || !B->Right && !B->Left)
        return pathWithSum(B->Right, remain) || pathWithSum(B->Left, remain);

    else if (B->Left)
        return pathWithSum(B->Left, remain);
    else
        return pathWithSum(B->Right, remain);
}