/*
    * Author: Bratin Mondal
    * Roll No: 21CS10016

    * Department of Computer Science and Engineering
    * Indian Institute of Technology, Kharagpur
*/

#include <stdio.h>

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

void print(int maxHops)
{
    printf("Maximum number of hops required: ");
    if (maxHops == 0)
        printf("None\n");
    else
        printf("%d\n", maxHops);
}

int main()
{
    int n, i, j;
    scanf("%d", &n);

    int W[n];
    for (i = 0; i < n; i++)
        scanf("%d", &W[i]);

    /*
        Check all pairs of (i, j) such that i < j
        Time Complexity: O(n^2)
    */

    int maxHops = 0;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (W[i] < W[j])
                maxHops = max(maxHops, (j - i));
        }
    }

    print(maxHops);

    return 0;
}