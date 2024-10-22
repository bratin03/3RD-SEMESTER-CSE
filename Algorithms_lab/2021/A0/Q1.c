/*
    * Author: Bratin Mondal
    * Roll No: 21CS10016

    * Department of Computer Science and Engineering
    * Indian Institute of Technology, Kharagpur
*/
#include <stdio.h>
#include <stdlib.h>
void init(int *a, int *d, int n)
{
    a = (int *)malloc(n * sizeof(int));
    d = (int *)malloc(n * sizeof(int));
    int i;
    for (i = 0; i < n; i++)
    {
        a[i] = i + 1;
        if (i == 0)
            d[i] = 0;
        else
            d[i] = -1;
    }
}
int Index(int *a, int n)
{
    int i, count = 0;
    for (i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
            count += (i + 1);
    }
    return count;
}

int key(int *d, int n)
{
    int i;
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            return 1;
    }
    return 0;
}

void display(int *a, int n)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

int genNext(int *a, int *d, int n, int invCount)
{
    int i = 0, max = -1, max_index = -1, temp;
    for (i = 0; i < n; i++)
    {
        if (d[i] != 0)
        {
            if (a[i] > max)
            {
                max = a[i];
                max_index = i;
            }
        }
    }
    if (d[max_index] == -1)
    {
        invCount++;
        temp = a[i];
        a[i] = a[i - 1];
        a[i - 1] = temp;
        temp = d[i];
        a[i] = d[i - 1];
        d[i - 1] = temp;

        if (i == 1)
        {
            d[i - 1] = 0;
        }
    }
    if (d[max_index] == +1)
    {
        invCount--;
        temp = a[i];
        a[i] = a[i + 1];
        a[i + 1] = temp;
        temp = a[i];
        a[i] = a[i - 1];
        a[i - 1] = temp;
        if (i == n - 2)
        {
            d[i + 1] = 0;
        }
    }

    for (i = 0; i < n; i++)
    {
        if (d[i] > max)
        {
            d[i] *= -1;
        }
    }
}

int main()
{
    int n;
    printf("Enter n:");
    scanf("%d", &n);
    int *a, *d;
    init(a, d, n);
    int invCount = 0;
    display(a, n);
    printf("%d %d\n", invCount, Index(a, n));
    while (key(d, n))
    {
        invCount = genNext(a, d, n, invCount);
        display(a, n);
        printf("%d %d\n", invCount, Index(a, n));
    }
}