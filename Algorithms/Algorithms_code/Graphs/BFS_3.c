/*
    * Author: Bratin Mondal
    * Roll No: 21CS10016

    * Department of Computer Science and Engineering
    * Indian Institute of Technology, Kharagpur
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int n;
    struct node *next;
} node;

typedef struct
{
    int size;
    int f;
    int r;
    int *a;
} queue;

int isEmpty(queue *q)
{
    if (q->f == q->r)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enQ(queue *q, int n)
{
    q->r++;
    q->a[q->r] = n;
}

int deQ(queue *q)
{
    q->f++;
    int ret = q->a[q->f];
    return ret;
}

int main()
{
    queue Q;
    Q.size = 100;
    Q.f = Q.r = 0;
    Q.a = (int *)malloc(Q.size * sizeof(int));
    int i, j;
    int g[10][10] = {
        {0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 1, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 1, 0, 0},
        {0, 0, 0, 1, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0}};
    int visited[10];
    for (i = 0; i < 10; i++)
    {
        visited[i] = 0;
    }
    i = 0;
    visited[i] = 1;
    printf("%d  ", i);
    enQ(&Q, i);
    while (!isEmpty(&Q))
    {
        int x = deQ(&Q);
        for (j = 0; j < 10; j++)
        {
            if (g[x][j] == 1 && visited[j] == 0)
            {
                printf("%d  ", j);
                enQ(&Q, j);
                visited[j] = 1;
            }
        }
    }
}