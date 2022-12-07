#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double hirec(int n)
{
    double h_cur = 1, l_cur = 0, h_prev = 1, l_prev = 0;
    int i;
    for (i = 0; i < n; i++)
    {
        h_cur = 2 * h_prev + l_prev;
        l_cur = h_prev + l_prev;
        h_prev = h_cur;
        l_prev = l_cur;
    }
    return h_cur;
}

double lorec(int n)
{
    double h_cur = 1, l_cur = 0, h_prev = 1, l_prev = 0;
    int i;
    for (i = 0; i < n; i++)
    {
        h_cur = 2 * h_prev + l_prev;
        l_cur = h_prev + l_prev;
        h_prev = h_cur;
        l_prev = l_cur;
    }
    return l_cur;
}

double *hilorec(int n)
{
    double *a = (double *)malloc(2 * sizeof(double));
    double h_cur = 1, l_cur = 0, h_prev = 1, l_prev = 0;
    int i;
    for (i = 0; i < n; i++)
    {
        h_cur = 2 * h_prev + l_prev;
        l_cur = h_prev + l_prev;
        h_prev = h_cur;
        l_prev = l_cur;
    }

    a[0] = h_cur;
    a[1] = l_cur;
    return a;
}

double *hiloformula(int n)
{
    double *a = (double *)malloc(2 * sizeof(double));
    a[0] = ((5 + sqrt(5)) / 10) * pow((3 - sqrt(5)) / 2, n + 1) + ((5 - sqrt(5)) / 10) * pow((3 + sqrt(5)) / 2, n + 1);
    a[1] = ((-5 - 3 * sqrt(5)) / 10) * pow((3 - sqrt(5)) / 2, n + 1) + ((-5 + 3 * sqrt(5)) / 10) * pow((3 + sqrt(5)) / 2, n + 1);
    return a;
}

int main()
{
    int n;
    double h, l, *a;
    printf("Enter n:\n");
    scanf("%d", &n);
    printf("Method 0:\n");
    h = hirec(n);
    l = lorec(n);
    printf("hi(%d)=%f, lo(%d)=%f \n", n, h, n, l);
    a = hilorec(n);
    h = a[0];
    l = a[1];
    printf("Method 1:\n");
    printf("hi(%d)=%f, lo(%d)=%f \n", n, h, n, l);
    a = hiloformula(n);
    h = a[0];
    l = a[1];
    printf("Method 2:\n");
    printf("hi(%d)=%f, lo(%d)=%f \n", n, h, n, l);
}
