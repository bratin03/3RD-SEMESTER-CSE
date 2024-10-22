/*
    * Author: Bratin Mondal
    * Roll No: 21CS10016

    * Department of Computer Science and Engineering
    * Indian Institute of Technology, Kharagpur
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int exhsearch(int i, int u, int v, int L, int A[], int n)
{
    if (i == n || A[i] > max(L - u, L - v))
        return i;
    else
    {
        if (A[i] <= L - u && A[i] <= L - v)
            return max(exhsearch(i + 1, u + A[i], v, L, A, n), exhsearch(i + 1, u, v + A[i], L, A, n));
        else if (A[i] <= L - u)
            return exhsearch(i + 1, u + A[i], v, L, A, n);
        else
            return exhsearch(i + 1, u, v + A[i], L, A, n);
    }
}

struct node
{
    int i;
    int u;
    int v;
    struct node *next;
};

int hash_func(int i, int u, int v, int s)
{
    return (7 * i + 3 * u + 5 * v) % s;
}

void init(struct node *hasht[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        hasht[i] = NULL;
}

int search(struct node *hasht[], int i, int u, int v, int s)
{
    int key = hash_func(i, u, v, s);
    struct node *temp = hasht[key];
    while (temp)
    {
        if (temp->i == i && temp->u == u && temp->v == v)
            return 1;
        temp = temp->next;
    }
    return 0;
}

void insert(struct node *hasht[], int i, int u, int v, int s)
{
    if (search(hasht, i, u, v, s))
    {
        // create a newnode with value
        struct node *newNode = malloc(sizeof(struct node));
        newNode->i = i;
        newNode->u = u;
        newNode->v = v;
        newNode->next = NULL;

        // calculate hash key
        int key = hash_func(i, u, v, s);

        // check if chain[key] is empty
        if (hasht[key] == NULL)
            hasht[key] = newNode;
        // collision
        else
        {
            // add the node at the end of chain[key].
            struct node *temp = hasht[key];
            while (temp->next)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }
}

int hashsearch(int i, int u, int v, int L, int A[], int n, struct node *hasht[], int s)
{
    int k1 = -1, k2 = -1;
    if (i == n)
        return i;
    if (search(hasht, i, u, v, s) == 0)
        insert(hasht, i, u, v, s);
    if (u + A[i] <= L && search(hasht, i + 1, u + A[i], v, s) == 0)
        k1 = hashsearch(i + 1, u + A[i], v, L, A, n, hasht, s);
    if (v + A[i] <= L && search(hasht, i + 1, u, v + A[i], s) == 0)
        k2 = hashsearch(i + 1, u, v + A[i], L, A, n, hasht, s);
    if (k1 == -1 && k2 == -1)
        return i;
    return max(k1, k2);
}

int main()
{
    int L, n;
    printf("Enter L:\n");
    scanf("%d", &L);
    printf("Enter n:\n");
    scanf("%d", &n);
    int i, arr[n];
    printf("Enter the lengths(separated by space):\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    clock_t c1, c2;
    double runtime;

    c1 = clock();

    printf("Exhaustive Search:\nk=%d\n", exhsearch(0, 0, 0, L, arr, n));

    c2 = clock();

    runtime = (double)(c2 - c1) / (double)CLOCKS_PER_SEC;
    printf("Running time = %lf seconds\n", runtime);

    c1 = clock();
    int s = n * L;
    struct node *hasht[s];
    init(hasht, s);
    printf("Hash Search:\nk=%d\n", hashsearch(0, 0, 0, L, arr, n, hasht, s));

    c2 = clock();

    runtime = (double)(c2 - c1) / (double)CLOCKS_PER_SEC;
    printf("Running time = %lf seconds\n", runtime);
}
