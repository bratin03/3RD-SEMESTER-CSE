#include <stdio.h>
#include <stdlib.h>
int **build_heap(int n)
{
    int **arr = (int **)malloc((n + 2) * sizeof(int *)), i;
    for (i = 1; i <= n + 1; i++)
        arr[i] = (int *)malloc(3 * sizeof(int));

    return arr;
}

int size = 0;

int Root()
{
    return 1;
}

int Parent(int n)
{
    return n / 2;
}

int LeftChild(int n)
{
    return 2 * n;
}

int RightChild(int n)
{
    return 2 * n + 1;
}

int HasParent(int n)
{
    return n != Root();
}

int IsNode(int n)
{
    return n <= size;
}

int getMin(int **H)
{
    if (size == 0)
    {
        printf("Empty priority queue.\n");
        exit(0);
    }

    return H[Root()][2];
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void shiftUp(int **H, int n)
{
    while (HasParent(n) && (H[Parent(n)][2] > H[n][2]))
    {
        swap(&H[Parent(n)][0], &H[n][0]);
        swap(&H[Parent(n)][1], &H[n][1]);
        swap(&H[Parent(n)][2], &H[n][2]);
        n = Parent(n);
    }
}

void insert(int **H, int a, int b)
{
    // if(size==CAPACITY)
    // {
    //     printf("Priority queue full.\n");
    //     exit(0);
    // }
    H[size + 1][0] = a;
    H[size + 1][1] = b;
    H[size + 1][2] = a * a * a + b * b * b;
    size++;
    shiftUp(H, size);
}

void shiftDown(int **H, int n)
{

    while (IsNode(LeftChild(n)))
    {
        int child = LeftChild(n);
        if (IsNode(RightChild(n)) && (H[RightChild(n)][2] < H[LeftChild(n)][2]))
            child = RightChild(n);
        if (H[n][2] > H[child][2])
        {
            swap(&H[n][0], &H[child][0]);
            swap(&H[n][1], &H[child][1]);
            swap(&H[n][2], &H[child][2]);
        }

        else
            break;
        n = child;
    }
}

void remove_min(int **H, int *x, int *y)
{
    // if(size==0)
    // {
    //     printf("Empty priority queue.\n");
    //     exit(0);
    // }
    *x = H[Root()][0];
    *y = H[Root()][1];

    H[Root()][0] = H[size][0];
    H[Root()][1] = H[size][1];
    H[Root()][2] = H[size][2];
    size--;
    shiftDown(H, Root());
}

void solve(int n)
{

    int **h = build_heap(n);
    int i;
    for (i = 0; i <= n; i++)
    {
        insert(h, i, 0);
    }
    int x1 = -1, y1 = -1, x, y, curr_num = -1;
    while (size > 0)
    {
        remove_min(h, &x, &y);
        if (x1 * x1 * x1 + y1 * y1 * y1 == x * x * x + y * y * y && (x != y1) && x * x * x + y * y * y != curr_num)
        {
            printf("%d (%d %d) (%d %d)\n", x * x * x + y * y * y, x1, y1, x, y);
            curr_num = x * x * x + y * y * y;
        }
        if (y < n)
            insert(h, x, y + 1);
        x1 = x;
        y1 = y;
    }
}

int main()
{
    int n;
    printf("Enter N:\n");
    scanf("%d", &n);
    int x = 0;
    while (x * x * x < n)
    {
        x++;
    }
    x--;
    solve(x);
}