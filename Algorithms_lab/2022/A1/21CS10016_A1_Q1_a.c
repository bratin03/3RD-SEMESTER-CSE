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
  int n;    // number of cities
  int i, j; // loop variables
  printf("Enter the number of cities:");
  scanf("%d", &n);
  int arr[n];
  for (i = 0; i < n; i++) // looping
  {
    printf("Enter %d city population:", i + 1);
    scanf("%d", &arr[i]);
  }

  int max = -1; // initializing max with -1
  for (i = 0; i < n; i++)
  {
    for (j = i + 1; j < n; j++)
    {
      if (arr[j] > arr[i])
      {
        if ((j - i) > max)
          max = j - i; // resetting max on getter larger solution
      }
    }
  }
  if (max < 0)
    printf("None\n"); // no solution found
  else
    printf("Maximum number of hops required: %d\n", max);
  return 0;
}
