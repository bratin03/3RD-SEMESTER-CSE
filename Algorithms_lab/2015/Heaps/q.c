/*
    * Author: Bratin Mondal
    * Roll No: 21CS10016

    * Department of Computer Science and Engineering
    * Indian Institute of Technology, Kharagpur
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int priority;
    int min;
} Node;

int size = 0;
int capacity = 1000;

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
    return (n <= size && n >= 1);
}
int min(int a, int b)
{
    if (a > b)
        return b;
    return a;
}

void swap(Node *xp, Node *yp)
{
    Node temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void shiftUp(Node H[], int n)
{
    while (HasParent(n) && (H[Parent(n)].priority < H[n].priority))
    {
        swap(&H[Parent(n)], &H[n]);
        n = Parent(n);
    }
}
void adjustMin(Node H[], int i)
{
    while (i > 0)
    {
        if (IsNode(RightChild(i)))
        {
            H[i].min = min(H[LeftChild(i)].min, H[RightChild(i)].min);
        }
        else if (IsNode(LeftChild(i)))
            H[i].min = H[LeftChild(i)].min;
        else
            H[i].min = H[i].priority;
        i = Parent(i);
    }
}

void insert(Node H[], int new)
{
    if (size == capacity)
    {
        printf("Priority queue full.\n");
        exit(0);
    }
    H[size + 1].priority = new;
    H[size + 1].min = new;
    size++;
    shiftUp(H, size);
    adjustMin(H, size);
}

void shiftDown(Node H[], int n)
{

    while (IsNode(LeftChild(n)))
    {
        int child = LeftChild(n);
        if (IsNode(RightChild(n)) && (H[RightChild(n)].priority > H[LeftChild(n)].priority))
            child = RightChild(n);
        if (H[n].priority < H[child].priority)
            swap(&H[n], &H[child]);
        else
            break;
        n = child;
    }
}

void initMin(Node H[])
{
    int i;
    for (i = size / 2 + 1; i <= size; i++)
    {
        H[i].min = H[i].priority;
    }
    for (i = size / 2; i >= 1; i--)
    {
        if (IsNode(RightChild(i)))
        {
            H[i].min = min(H[LeftChild(i)].min, H[RightChild(i)].min);
        }
        else
            H[i].min = H[LeftChild(i)].min;
    }
}

int deleteMax(Node H[])
{
    if (size == 0)
    {
        printf("Empty priority queue.\n");
        exit(0);
    }
    int num = H[Root()].priority;
    H[Root()] = H[size];
    size--;
    shiftDown(H, Root());
    initMin(H);

    return num;
}
int deleteMin(Node H[])
{
    int i = 1;
    while (i <= size / 2)
    {
        if (H[i].min == H[LeftChild(i)].min)
            i = LeftChild(i);
        else
            i = RightChild(i);
    }
    int num = H[i].priority;
    swap(&H[i], &H[size]);
    size--;
    adjustMin(H, i);
    adjustMin(H, Parent(size + 1));
    return num;
}

void initHeap(int Q[], int n, Node H[])
{
    int i;
    for (i = 1; i <= n; i++)
    {
        H[i].priority = Q[i - 1];
    }
    size = n;
    for (i = size / 2; i >= 1; i--)
    {
        shiftDown(H, i);
    }
}
void show(Node H[])
{
    int i;
    for (i = 1; i <= size; i++)
    {
        printf("%d, %d  ", H[i].priority, H[i].min);
        printf("(");
        if (IsNode(LeftChild(i)))
        {
            printf("%d, %d ", H[LeftChild(i)].priority, H[LeftChild(i)].min);
        }
        else
            printf(" _ ");
        printf(":");
        if (IsNode(RightChild(i)))
        {
            printf("%d, %d ", H[RightChild(i)].priority, H[RightChild(i)].min);
        }
        else
            printf(" _ ");
        printf(")\n");
    }
}

int main()
{
    int ninit, i;
    printf("Enter number of ninits:\n");
    scanf("%d", &ninit);
    int ninits[ninit];
    printf("Enter the ninits:\n");
    for (i = 0; i < ninit; i++)
    {
        scanf("%d", &ninits[i]);
    }
    Node H[capacity + 1];
    initHeap(ninits, ninit, H);
    initMin(H);
    show(H);
    int nin;
    printf("Enter number of nins:\n");
    scanf("%d", &nin);
    int nins[nin];
    printf("Enter the nins:\n");
    for (i = 0; i < nin; i++)
    {
        scanf("%d", &nins[i]);
    }
    for (i = 0; i < nin; i++)
    {
        insert(H, nins[i]);
    }
    show(H);
    int ndelmax;
    printf("Number of elements to delete:\n");
    scanf("%d", &ndelmax);
    printf("Max deletion:\n");
    for (i = 0; i < ndelmax; i++)
    {
        printf("%d ", deleteMax(H));
    }
    printf("\n");
    show(H);
    int ndelmin;
    printf("Number of elements to delete:\n");
    scanf("%d", &ndelmin);
    printf("Min deletion\n");
    for (i = 0; i < ndelmin; i++)
    {
        printf("%d ", deleteMin(H));
    }
    printf("\n");
    show(H);
}
