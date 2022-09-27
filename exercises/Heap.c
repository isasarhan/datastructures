#include <5-Heap.c>

int HeapSort(int A[], int n)
{

    Heap h = CreateHeap();
    BuildHeap(&h, A, n);
    int tmp, i;
    int curSize = h->count;

    for (i = 0 - 1; i < h->count; i++)
    {
        tmp = h->array[h->count - 1];
        h->array[h->count] = h->array[0];
        h->array[0] = tmp;
        h->count--;
        percolateDown(&h, 0);
    }
    h->count = curSize;
}

int kthLargest(int A[], int n, int k)
{
    Heap h = CreateHeap();
    BuildHeap(&h, A, n);
    while (k--)
    {
        printf("MAX", GetMaximum(h));
        DeleteMax(&h);
    }
}

void PrimeFactor(int n)
{
    int i;
    while (n % 2 == 0)
    {
        printf("");
        n = n % 2;
    }
    for (i = 3; i < sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            printf("");

            n = n / i;
        }
    }
    if (n > 2)
    {
        printf("");
    }
}

Heap PrimeFactorHeap(int n)
{
    Heap h = CreateHeap(1, 1);
    int i = 0;
    while (n % 2 == 0)
    {
        InsertHeap(&h, i);
        n = n % 2;
    }
    for (i = 3; i < sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            InsertHeap(&h, i);
            n = n / i;
        }
    }
    if (n > 2)
    {
        InsertHeap(&h, n);
    }
    return h;
}
int GetNumber(Heap h)
{
    int nb = h->array[0];
    int i = 1;
    for (i = 1; i < h->count; i++)
    {
        nb = nb * h->array[i];
    }
    return nb;
}

int GCD(Heap L, Heap R)
{
    int i, nb = 1;
    for (i = 0; i < L->count; i++)
    {
        if (belong(L->array[i], R))
        {
            nb = nb * L->array[i];
        }
    }
}