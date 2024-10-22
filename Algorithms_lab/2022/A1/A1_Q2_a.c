/*
    * Author: Bratin Mondal
    * Roll No: 21CS10016

    * Department of Computer Science and Engineering
    * Indian Institute of Technology, Kharagpur
*/


#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, m, n, k;

    // Taking the input for m and n
    printf("Enter m:");
    scanf("%d", &m);
    printf("Enter n:");
    scanf("%d", &n);

    int a[m][n];

    // Taking the input for array
    printf("Enter the array:\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    // Converting the 0's to -1 in array
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a[i][j] == 0)
                a[i][j] = -1;
        }
    }

    // Changing the rows and columns to 0 wherever -1 exists
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a[i][j] == -1)
            {
                for (k = 0; k < m; k++)
                {
                    a[k][j] = 0;
                }
                for (k = 0; k < m; k++)
                {
                    a[i][k] = 0;
                }
            }
        }
    }

    // Printing the final array
    printf("\nOutput is:\n");
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}
