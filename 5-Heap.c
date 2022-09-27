#define N 20
typedef struct Heap
{
    int *array;
    int capacity;
    int count;
    int heap_type;
} * Heap;

Heap CreateHeap(int size, int heap_type)
{
    Heap h;
    h->array = (int *)malloc(sizeof(int) * size);
    h->capacity = size;
    h->length = 0;
    h->heap_type = heap_type;
}
int Parent(Heap h, int i)
{
    if (i <= 0 || i >= h->count)
        return -1;
    return (i - 1) / 2;
}
int LeftChild(Heap h, int i)
{
    int left = (2 * i) + 1;
    if (left > h->count)
        return -1;
    return left;
}
int RightChild(Heap h, int i)
{
    int right = (2 * i) + 2;
    if (right > h->count)
        return -1;
    return right;
}
int GetMaximum(Heap h)
{
    if (h->count == 0)
        return -1;
    return h->array[0];
}
void percolateDown(Heap *h, int i)
{
    int l, r, max;
    int tmp;
    l = LeftChild(*h, i);
    r = RightChild(*h, i);

    if (l != -1 && (*h)->array[i] < (*h)->array[l])
        max = l;
    else
        max = i;
    if (r != -1 && (*h)->array[max] < (*h)->array[r])
        max = r;

    if (max != i)
    {
        tmp = (*h)->array[max];
        (*h)->array[max] = (*h)->array[i];
        (*h)->array[i] = tmp;

        percolateDown((h), max);
    }
}
int DeleteMax(Heap *h)
{
    int data;
    if ((*h)->count == 0)
        return -1;
    data = (*h)->array[0];
    (*h)->array[0] = (*h)->array[(*h)->count - 1];
    (*h)->count--;
    percolateDown(h, 0);
    return data;
}
int InsertHeap(Heap *h, int data)
{
    int *array, i;
    if ((*h)->count == (*h)->capacity)
        ResizeHeap(h);
    (*h)->count++;
    i = (*h)->count - 1;
    while (i > 0 && data > (*h)->array[(i - 1) / 2])
    {
        (*h)->array[i] = (*h)->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    (*h)->array[i] = data;
}
int ResizeHeap(Heap *h)
{
    int *old_array = (*h)->array;
    int i;
    (*h)->array = (int *)malloc(sizeof(int) * (*h)->capacity * 2);
    if (!(*h)->array)
        return -1;
    for (i = 0; i < (*h)->count; i++)
    {
        (*h)->array[i] = old_array[i];
    }
    free(old_array);
}
int DestroyHeap(Heap *h)
{
    if ((*h) == NULL)
        free((*h)->array);
    free(h);
    h = NULL;
}
void BuildHeap(Heap *h, int A[], int n)
{
    int i;
    if ((*h) == NULL)
        return;
    while (n > (*h)->capacity)
        ResizeHeap(h);
    for (i = 0; i < n; i++)
        (*h)->array[i] = A[i];
    (*h)->count = n;
    for (i = (n - 1) / 2; i >= 0; i--)
        percolateDown(h, i);
}
void Heapsort(int A[], int n)
{
    int tmp;
    Heap h = CreateHeap(n, 1);
    BuildHeap(&h, A, n);
    int old_count = n;
    for (i = 0; i < n; i++)
    {
        tmp = h->array[i];
        h->array[i] = h->array[h->count - 1];
        h->array[h->count - 1] = tmp;
        h->count--;
        percolateDown(h, 0);
    }
    h->count = old_count;
}