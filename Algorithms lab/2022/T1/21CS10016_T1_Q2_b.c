/*Name:Bratin Mondal
Roll:21CS10016*/
#include <stdio.h>
#include <string.h>

int main()
{ // taking input
    int n, m;
    printf("Enter the number of assignments(n):\n");
    scanf("%d", &n);
    printf("Enter the total number of hours left:\n");
    scanf("%d", &m);
    int i, j, p, hours[n], points[n], P = 0, M0, M1;
    printf("Enter the number of points of each assignement:(separated by space)\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &points[i]);
        P += points[i];
    }
    printf("Enter the number of hours to solve each assignement:(separated by space)\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &hours[i]);
    }
    // taking input done
    int infinity = 100000; // infinity
    int T[n + 1][P + 1];
    // setting the base case of dp table
    for (i = 0; i <= P; i++)
    {
        T[0][i] = infinity;
    }
    for (i = 0; i <= n; i++)
    {
        T[i][0] = 0;
    }
    // base case filled

    // creating the dp table as per the strategy given in question
    for (i = 1; i <= n; i++)
    {
        for (p = 1; p <= P; p++)
        {
            if (p < points[i - 1]) // not inclding the i-th assignment
            {
                T[i][p] = T[i - 1][p];
            }
            else
            {
                M0 = T[i - 1][p];
                M1 = hours[i - 1] + T[i - 1][p - points[i - 1]];
                if (M1 > m || M0 < M1)
                {
                    T[i][p] = M0; // not inclding the i-th assignment
                }
                else
                    T[i][p] = M1; // inclding the i-th assignment
            }
        }
    }

    i = P;
    while (T[n][i] >= infinity)
    {
        i--;
    } // searching for max i for which Time is finite

    printf("Maximum Points:%d\nMinimum Effort:%d\n", i, T[n][i]);
}
