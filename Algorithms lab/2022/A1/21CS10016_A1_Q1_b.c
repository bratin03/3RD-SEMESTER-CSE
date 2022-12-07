/*Name:Bratin Mondal
Roll:21CS10016*/
#include <stdio.h>

int max(int a, int b)
{
  if (a > b)
    return a;
  return b;
}

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

  int aux_arr[n];              // auxiliary array to store the maximum element till current position from the right side
  aux_arr[n - 1] = arr[n - 1]; // setting the last element
  for (i = n - 2; i >= 0; i--)
  {
    aux_arr[i] = max(arr[i], aux_arr[i + 1]); // setting the other elements
  }
  int max_dist = -1;
  i = 0;
  j = 0;
  while (i < n && j < n)
  {
    if (aux_arr[j] >= arr[i])
    {
      max_dist = max(j - i, max_dist); // resetting max on getter larger solution
      j++;
    } // increamenting j for checking for next element on auxillary area
    else
      i++;
  } // increamenting i for checking for next element on main area
  if (max_dist <= 0)
    printf("None\n"); // no solution found
  else
    printf("Maximum number of hops required: %d\n", max_dist);
  return 0;
}
