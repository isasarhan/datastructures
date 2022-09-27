void BubbleSort(int A[], int N)
{
    int i = 0, j = N - 1;
    int swapped = 1;
    int tmp;
    for (j = N - 1; j >= 0 && swapped; j++)
    {
        swapped = 0;
        for (i = 0; i < j; i++)
        {
            if (A[i] > A[i + 1])
            {
                // swap
                tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
                swapped = 1;
            }
        }
    }
}
void SelectionSort(int A[], int N)
{
    int i, min, j;
    int tmp;
    for (i = 0; i < N; i++)
    {
        min = i;
        for (j = i; j < N; j++)
            if (A[j] < A[min])
                min = j;
        if (min != i)
        {
            tmp = A[i];
            A[i] = A[min];
            A[min] = tmp;
        }
    }
}
void InsertionSort(int A[], int N)
{
    int i, j, v;
    for (i = 1; i < N; i++)
    {
        v = A[i];
        j = i;
        while (A[j - 1] > v && j > 0)
        {
            A[j] = A[j - 1];
            j--;
        }
        A[j] = v;
    }
}
void QuickSort(int A[], int low, int high)
{
    int pivot;
    if (high > low)
    {
        pivot = partition(A, low, high);
        QuickSort(A, low, pivot - 1);
        QuickSort(A, pivot + 1, high);
    }
}
int partition(int A[], int low, int high)
{
    int left, right, pivot_item;
    pivot_item = A[low];
    left = low + 1;
    right = high;
    int tmp;
    while (left <= right)
    {
        while (A[left] < pivot_item && left <= right)
            left++;
        while (A[right] > pivot_item && left <= right)
            right--;
        if (left < right)
        {
            tmp = A[left];
            A[left] = A[right];
            A[right] = tmp;
            left++;
            right--;
        }
    }
    A[low] = A[right];
    A[right] = pivot_item;

    return right;
}

void MergeSort(int A[], int low, int high)
{
    int middle;
    if (low < high)
    {
        middle = (low + high) / 2;
        MergeSort(A, low, middle);
        MergeSort(A, middle + 1, high);
        Fusion(A, low, high, middle);
    }
}
void Fusion(int A[], int lower, int upper, int middle)
{
    int i = lower, j = middle + 1, c[upper - lower + 1];
    int k = 0;
    while (i <= middle && j <= upper)
    {
        if (A[i] < A[j])
            c[k++] = A[i++];
        else
            c[k++] = A[j++];
    }
    while (i <= middle)
        c[k++] = A[i++];
    while (j <= upper)
        c[k++] = A[j++];

    for (i = lower, k = 0; i <= upper; i++, k++)
        A[i] = c[k];
}
