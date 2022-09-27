#define N 10

typedef char element;
typedef element hash[N];
typedef struct HashTable
{
    int T1[N];
    int T2[N];
} HashTable;

int HashFunction(element k, int size)
{
    return ((int)k % size);
}
void CreateHash(hash h)
{
    int i;
    for (i = 0; i < N; i++)
    {
        hash[i] = '0';
    }
}
int H1(int key)
{
    return key % N;
}
int H2(int key)
{
    return (key / N) % N;
}

// Hopscotch Hashing - Linear probing
int belongLP(hash h, element e, int neighbor)
{
    int vh = HashFunction(e);
    if (h[vh] == e)
        return 1;

    while (neighbor - 1 > 0)
    {
        vh = (vh + 1) % N;
        if (h[vh] == e)
            return 1;
        neighbor--;
    }
    return 0;
}
int insert(hash h, element e, int neighbor)
{
    int i = 0;
    int vh = HashFunction(e);
    if (h[vh] == '0')
    {
        h[vh] = e;
        return 1;
    }
    element tmp;
    int proceed = 1;
    while (proceed)
    {
        while (i < neighbor - 1)
        {
            if (h[(vh + i) % N] == '0')
            {
                h[(vh + i) % N] = e;
                return 1;
            }
            i++;
        }
    }
}
// Coalesced Hashing
typedef char eleemnt1[N];
typedef struct cell
{
    eleemnt1 data;
    int link;
} entry;
typedef entry hashTable[N];
int hash_function(char *s)
{
    return ((int)*s) % N;
}
void CreateTable(hashTable h)
{
    int i = 0;
    for (i = 0; i < N; i++)
    {
        h[i].link = -2;
    }
}
int empty(hashTable h, int i)
{
    return h[i].link == -2;
}
int add_coalesced(hashTable h, int m, char *c, int p)
{
    int r;
    int v = hash_function(c);
    if (empty(h, v))
    {
        strcpy(h[v].data, c);
        h[v].link = -1;
        return 1;
    }
    while (h[v].link != -1 && strcmp(h[v].data, e) != 0)
        v = h[v].link;
    if (!strcmp(h[v].data, e))
        return 0;
    r = m - 1;
    while (r >= p && !empty(h, r))
        r--;

    if (r < p)
        return 0;
    strcpy(h[r].data, e);
    h[r].link = -1;
    h[v].link = r;
    return 1;
}

int search_coalesced(hashTable h, char *c)
{
    int v = hash_function(c);
    if (strcmp(h[v].data, e) == 0)
        return 1;
    while (h[v].link != -1 && strcmp(h[v].data, e) != 0)
        v = h[v].link;
    if (strcmp(h[v].data, e) == 0)
        return 1;
    return 0;
}

int delete_coalesced(hashTable h, int m, char *c, int p)
{
    int v = hash_function(c);
    int x;

    if (empty(h, c))
        return 0;
    if (strcmp(h[v].data, e) == 0)
    {
        if (h[v].link == -1)
            h[v].link = -2;
        else
        {
            x = h[v].link;
            h[v] = h[x];
            h[x].link = -2;
        }
        return 1;
    }
    while (h[v].link != -1 && strcmp(h[v].data, e) == 0)
    {
        x = v;
        v = h[v].link;
    }
    if (strcmp(h[v].data, e) != 0)
        return 0;

    h[x].link = h[v].link;
    h[v].link = -2;
    return 1;
}
// Double Hashing
int belongDH(HashTable h, element e, int size)
{
    int key1 = H1(e);
    int key2 = H2(e);

    return h.T1[key1] == e || h.T2[key2] == e;
}
int deleteDH(HashTable *h, element e)
{
    int key1 = H1(e);
    int key2 = H2(e);

    if (h->T1[key1] != -1 && h->T1[key1] == e)
    {
        h->T1[key1] = -1;
    }
    else if (h->T2[key2] != -1 && h->T2[key2] == e)
    {
        h->T2[key2] = -1;
    }
    else
        return 0;

    return 1;
}
int insertDH(HashTable *h, element e, int size)
{
    int v1, v2;
    int i = 0;
    int tmp, tmp2;
    v1 = H1[e];

    if (h->T1[v1] == -1)
    {
        h->T1[v1] = e;
        return 1;
    }
    tmp = h->T1[h1];
    h->T1[h1] = e;
    while (i < N * 2)
    {
        if (h->T2[h2[tmp]] == -1)
        {
            h->T2[h2(tmp)] = tmp;
            return 1;
        }
        else
        {
            tmp2 = h->T2[h2[tmp]];
            h->T2[h2[tmp]] = tmp;
            tmp = tmp2;
        }
        if (h->T1[H1[tmp]] == -1)
        {
            h->T1[H1(tmp)] = tmp;
            return 1;
        }
        else
        {
            tmp2 = h->T1[h1(tmp)];
            h->T1[h1(tmp)] = tmp;
            tmp = tmp2;
        }
        i++;
    }
}
// Quadratic Probing
//----------------------------------------
int insertQP(hash h, element e, int size)
{
    int step = 0;
    int vhash = HashFunction(e, size);
    while (step < size / 2)
    {
        if (h[(vhash + step * step) % size] == '0')
        {
            h[(vhash + step * step) % size] = e;
            return 1;
        }

        step++;
    }
    return 0;
}

int searchQP(hash h, element e, int size)
{

    int vhash = HashFunction(e, size);
    int step = 0;

    while (step < size / 2)
    {
        if (h[(vhash + step * step) % size] == e)
            return 1;

        step++;
    }
    return 0;
}

int deleteQP(hash h, element e, int size)
{
    int vhash = HashFunction(e, size);
    int prev, old;
    int step = 0;

    while (step < size / 2)
    {
        if (h[(vhash + step * step) % size] == e)
        {
            prev = (vhash + step * step) % size;
            step++;
            while (step < size / 2)
            {
                if (h[(vhash + step * step) % size] != '0' && HashFunction(h[(vhash + step * step)], size) == vhash)
                {
                    if (old == (vhash + step * step) % size)
                        break;
                    h[prev] = h[(vhash + step * step) % size];
                    h[(vhash + step * step) % size] = '0';
                    prev = [(vhash + step * step) % size;
                }

                step++;
            }
            return 1;
        }
    }
    return 0;
}

typedef struct node
{
    int data;
    struct node *next;
} *list;


