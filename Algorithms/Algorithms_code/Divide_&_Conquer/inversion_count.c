/*
	* Author: Bratin Mondal
	* Roll No: 21CS10016

	* Department of Computer Science and Engineering
	* Indian Institute of Technology, Kharagpur
*/
/*Inversion Count for an array indicates – how far (or close) the array is from being sorted. If the array is already sorted, then the inversion count is 0, but if the array is sorted in the reverse order, the inversion count is the maximum.

Formally speaking, two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j*/

// C program to Count
// Inversions in an array
// using Merge Sort
#include <stdio.h>
#include <stdlib.h>

int _mergeSort(int arr[], int temp[], int left, int right);
int merge(int arr[], int temp[], int left, int mid,
		  int right);

/* This function sorts the input array and returns the
number of inversions in the array */
int mergeSort(int arr[], int array_size)
{
	int *temp = (int *)malloc(sizeof(int) * array_size);
	return _mergeSort(arr, temp, 0, array_size - 1);
}

/* An auxiliary recursive function
that sorts the input
array and returns the number
of inversions in the array.
*/
int _mergeSort(int arr[], int temp[], int left, int right)
{
	int mid, inv_count = 0;
	if (right > left)
	{
		/* Divide the array into two parts and call
	_mergeSortAndCountInv() for each of the parts */
		mid = (right + left) / 2;

		/* Inversion count will be the sum of inversions in
		left-part, right-part and number of inversions in
		merging */
		inv_count += _mergeSort(arr, temp, left, mid);
		inv_count += _mergeSort(arr, temp, mid + 1, right);

		/*Merge the two parts*/
		inv_count += merge(arr, temp, left, mid + 1, right);
	}
	return inv_count;
}

/* This function merges two sorted
arrays and returns inversion
count in the arrays.*/
int merge(int arr[], int temp[], int left, int mid,
		  int right)
{
	int i, j, k;
	int inv_count = 0;

	i = left; /* i is index for left subarray*/
	j = mid;  /* j is index for right subarray*/
	k = left; /* k is index for resultant merged subarray*/
	while ((i <= mid - 1) && (j <= right))
	{
		if (arr[i] <= arr[j])
		{
			temp[k++] = arr[i++];
		}
		else
		{
			temp[k++] = arr[j++];

			/*this is tricky -- see above
			 * explanation/diagram for merge()*/
			inv_count = inv_count + (mid - i);
		}
	}

	/* Copy the remaining elements of left subarray
(if there are any) to temp*/
	while (i <= mid - 1)
		temp[k++] = arr[i++];

	/* Copy the remaining elements of right subarray
(if there are any) to temp*/
	while (j <= right)
		temp[k++] = arr[j++];

	/*Copy back the merged elements to original array*/
	for (i = left; i <= right; i++)
		arr[i] = temp[i];

	return inv_count;
}

/* Driver code*/
int main(int argv, char **args)
{
	int arr[] = {1, 20, 6, 4, 5};
	printf(" Number of inversions are %d \n",
		   mergeSort(arr, 5));
	getchar();
	return 0;
}
