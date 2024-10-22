#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double compute_iterative(int n)
{
    double current, previous, next;
    previous = 0;
    current = 1;
    if (n == 0)
    {
        return previous;
    }
    else if (n == 1)
    {
        return current;
    }
    else
    {
        int i;
        for (i = 2; i <= n; i++)
        {
            next = 2 * current + previous;
            previous = current;
            current = next;
        }
        return current;
    }
}
double compute_recursive(int n)
{
    double n1 = n;
    if (n1 < 2)
        return n1;
    return 2 * compute_recursive(n1 - 1) + compute_recursive(n1 - 2);
}

double power(double x, int n)
{
    if (n == 0)
        return 1;
    else if (n % 2)
    {
        return x * power(x, n / 2) * power(x, n / 2);
    }
    else
        return power(x, n / 2) * power(x, n / 2);
}

double compute_formula(int n)
{
    double n1 = n, ans;
    ans = (power((1 + sqrt(2)), n) - power((1 - sqrt(2)), n)) / (2 * sqrt(2));
    return ans;
}

void power_matrix(double *a11, double *a12, double *a21, double *a22, int n)
{
    double b11, b22, b12, b21;
    if (n == 0)
    {
        *a11 = 2;
        *a12 = 1;
        *a21 = 1;
        *a22 = 0;
    }
    else
    {
        b11 = (*a11) * (*a11) + (*a12) * (*a21);
        b12 = (*a11) * (*a12) + (*a12) * (*a22);
        b21 = (*a21) * (*a11) + (*a22) * (*a21);
        b22 = (*a21) * (*a12) + (*a22) * (*a22);
        power_matrix(&b11, &b12, &b21, &b22, n / 2);
        if (n % 2 == 0)
            *a11 = b11, *a12 = b12, *a21 = b21, *a22 = b22;
        else
        {
            double c11, c12, c21, c22;
            c11 = (*a11) * (b11) + (*a12) * (b21);
            c12 = (*a11) * (b12) + (*a12) * (b22);
            c21 = (*a21) * (b11) + (*a22) * (b21);
            c22 = (*a21) * (b12) + (*a22) * (b22);
            *a11 = c11;
            *a12 = c12;
            *a21 = c21;
            *a22 = c22;
        }
    }
}

double compute_matrix(int n)
{
    double a11, a12, a21, a22;
    a11 = 2.0, a12 = 1.0, a21 = 1.0, a22 = 0.0;
    power_matrix(&a11, &a12, &a21, &a22, n);
    return a12;
}

int main()
{

    int n;
    double x;
    printf("Enter n:");
    scanf("%d", &n);
    double time_spent = 0.0;
    clock_t end, begin;
    begin = clock();
    x = compute_iterative(n);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("I_%d (computed using iterative method)=%f\n", n, x);
    printf("Time taken in iterative method = %lf seconds\n", time_spent);
    begin = clock();
    x = compute_recursive(n);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("I_%d (computed using recursive method)=%f\n", n, x);
    printf("Time taken in recursive method = %lf seconds\n", time_spent);
    begin = clock();
    x = compute_formula(n);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("I_%d (computed using formula)=%f\n", n, x);
    printf("Time taken in formula = %lf seconds\n", time_spent);
    begin = clock();
    x = compute_matrix(n);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("I_%d (computed using matrix multiplication)=%f\n", n, x);
    printf("Time taken in matrix multiplication = %lf seconds\n", time_spent);
}