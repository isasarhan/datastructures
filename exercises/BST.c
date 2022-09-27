#define NULL (void *)0
#include <1-dynamic-stack.c>
#include <2-dynamic-queue.c>

typedef struct BST
{
    int data;
    struct BST *Left, *Right;
} * BST;

int belongBST_itr(BST B, int value)
{
    while (B)
    {
        if (value == B->data)
            return 1;
        else
        {
            if (value > B->data)
                B = B->Right;
            else
                B = B->Left;
        }
    }
    return 0;
}

int isBST_rec(BST B)
{
    if (!B)
        return 1;
    if (B->data > max(B->Left) && B->data < min(B->Right))
        return isBST_rec(B->Left) && isBST_rec(B->Right);
}
int isBST_Inorder(BST B, BST prev)
{
    if (!B)
        return 0;

    isBST_Inorder(B->Left, B);
    if (B->data > prev->data)
        return 0;
    isBST_Inorder(B->Right, B);
}

int FindMax(BST B)
{
    int l, r, res;
    if (!B)
        return -1;

    l = FindMax(B->Left);
    r = FindMax(B->Right);
    res = B->data;

    if (l > B->data)
        res = l;
    if (r > B->data)
        res = r;

    return res;
}
int sam_elements_itr(BST B1, BST B2)
{
    stack s1 = CreateStack();
    stack s2 = CreateStack();
    int done1 = 0, done2 = 0;
    int proceed = 1;
    int v1, v2;
    while (proceed)
    {
        while (!done1)
        {
            while (B1)
            {
                Push(&s1, B1);
                B1 = B1->Left;
            }
            if (Top(s1, &B1))
            {
                v = B1->data;
                Pop(&s1);
                B1 = B1->Right;
                break;
            }
            else
                done1 = 1;
        }
        while (!done2)
        {
            while (B2)
            {
                Push(&s2, B2);
                B2 = B2->Left;
            }
            if (Top(s2, &B2))
            {
                Pop(&s2);
                v2 = B2->data;
                B2 = B2->Right;
                break;
            }
            else
                done2 = 1;
        }
        if (v1 != v2)
            return 0;
        if (done1 && done2)
            return 1;
        done1 = 0;
        done2 = 0;
    }
}
int belongr(BST B, int v)
{
    if (!B)
        return 0;
    if (B->data == v)
        return 1;
    return belongr(B->Left, v) || belongr(B->Right, v);
}
int belong(BST B, BST T)
{
    if (!B)
        return 0;
    if (!T)
        return 1;

    if (belongr(B, T->data))
        return belong(B, T->Left) && belong(B, T->Right);
}
int same(BST B, BST T)
{
    if (!B || !T)
        return 1;

    return belong(B, T) && belong(T, B);
}

int belong_itr(BST B, int e)
{
    if (!B)
        return 0;

    queue q = CreateQueue();
    EnQueue(&q, B);
    while (Front(q, &B))
    {
        DeQueue(&q);
        if (B->data == e)
            return 1;
        if (B->Left)
            EnQueue(&q, B->Left);

        if (B->Right)
            EnQueue(&q, B->Right);
    }
    return 0;
}

int targetSum(BST B, int target) >
{
    int sum;
    stack l = CreateStack();
    stack r = CreateStack();
    int proceed = 1;
    BST left = B;
    BST right = B->Right;
    while (proceed)
    {
        while (left)
        {
            Push(&l, left);
            left = left->Left;
        }
        while (right)
        {
            Push(&r, right);
            right = right->Right;
        }
        if (Top(l, left) && Top(r, right))
        {
            sum = left->data + right->Right;
            if (sum == target)
                return 1;
            if (sum < target)
            {
                Pop(&l);
                left = left->Right;
                right = NULL;
            }
            else
            {
                Pop(&r);
                right = right->Left;
                left = NULL;
            }
        }
    }
}