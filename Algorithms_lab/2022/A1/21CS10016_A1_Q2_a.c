/*
    * Author: Bratin Mondal
    * Roll No: 21CS10016

    * Department of Computer Science and Engineering
    * Indian Institute of Technology, Kharagpur
*/
/*Name:Bratin Mondal
Roll:21CS10016*/
#include <stdio.h>
int main()
{
  int m, n; // size of matrix
  printf("Enter number of rows:");
  scanf("%d", &m);
  printf("Enter number of columns:");
  scanf("%d", &n);
  int matrix[m][n];
  int i, j, k;
  for (i = 0; i < m; i++)
  {
    printf("Enter the elements of the %d row(seperated by space):", i + 1);
    for (j = 0; j < n; j++)
    {
      scanf("%d", &matrix[i][j]);
    }
  } // scanning the matrix
  for (i = 0; i < m; i++)
  {
    for (j = 0; j < n; j++)
    {
      if (matrix[i][j] == 0) // checking for 0
      {                      // setting the corresponding row & column to -1
        for (k = 0; k < m; k++)
        {
          matrix[k][j] = -1;
        }
        for (k = 0; k < n; k++)
        {
          matrix[i][k] = -1;
        }
      }
    }
  }
  for (i = 0; i < m; i++)
  {
    for (j = 0; j < n; j++)
    { // resetiing the matrix by replacing -1 with 0
      if (matrix[i][j] == -1)
        matrix[i][j] = 0;
    }
  }
  printf("The new matrix:\n");
  for (i = 0; i < m; i++)
  {
    for (j = 0; j < n; j++)
    {
      printf("%2d", matrix[i][j]);
    }
    printf("\n");
  }
  return 0;
}
