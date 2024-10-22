/*
    * Author: Bratin Mondal
    * Roll No: 21CS10016

    * Department of Computer Science and Engineering
    * Indian Institute of Technology, Kharagpur
*/
/*Name:Bratin Mondal
Roll:21CS10016*/
#include <stdio.h>
#include <string.h>

int partition(int A[], int l, int r)
{
  int pivot = A[l];
  int i = l + 1; // left indices
  int j = r;     // right indices
  int temp;
  do
  { // looking for elements greater than pivot on left
    while (A[i] <= pivot)
    {
      i++;
    }
    // looking for elements lesser than pivot on right
    while (A[j] > pivot)
    {
      j--;
    }
    // making the swap
    if (i < j)
    {
      temp = A[i];
      A[i] = A[j];
      A[j] = temp;
    }
  } while (i < j);
  // swapping the pivot to bring it to its optimal position
  temp = A[l];
  A[l] = A[j];
  A[j] = temp;
  return j;
}

void quickSort(int A[], int low, int high)
{
  int Index; // pivot position after partition

  if (low < high)
  {
    Index = partition(A, low, high);
    quickSort(A, low, Index);      // sort left part
    quickSort(A, Index + 1, high); // sort right part
  }
}

int main()
{
  int n, i;
  // taking input
  printf("Enter the number of elements:\n");
  scanf("%d", &n);
  int arr[n];
  printf("Enter the elements:(separated by space)\n");
  for (i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }
  // input taking done
  quickSort(arr, 0, n - 1); // sorting
  printf("Sorted Sequence:\n");
  for (i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
}
