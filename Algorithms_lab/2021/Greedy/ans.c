/*
    * Author: Bratin Mondal
    * Roll No: 21CS10016

    * Department of Computer Science and Engineering
    * Indian Institute of Technology, Kharagpur
*/
#include <stdio.h>

int search_min(int time[], int k)
{
    int min = time[0], index = 0;
    int i;
    for (i = 0; i < k; i++)
    {
        if (time[i] < min)
        {
            min = time[i];
            index = i;
        }
    }
    return index;
}

void merge(int A[], int mid, int low, int high)
{
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] > A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for (int i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}

void mergeSort(int A[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(A, low, mid);
        mergeSort(A, mid + 1, high);
        merge(A, mid, low, high);
    }
}

void schedule_orders_a(int n, int k, int arr[], int index[], int seq[k][100], int cur, int time[])
{
    if (cur == n)
    {
        return;
    }
    int min = search_min(time, k);
    seq[min][index[min]] = arr[cur];
    time[min] += arr[cur];
    cur++;
    index[min]++;

    schedule_orders_a(n, k, arr, index, seq, cur, time);
}
void schedule_orders_b(int n, int k, int arr[], int index[], int seq[k][100], int cur, int time[])
{
    mergeSort(arr, 0, n - 1);
    schedule_orders_a(n, k, arr, index, seq, cur, time);
}
void schedule_orders_c(int n, int k, int arr[], int index[], int seq[k][100], int cur, int time[])
{
    schedule_orders_b(n, k, arr, index, seq, 0, time);
    int i, j, temp;
    for (i = 0; i < k; i++)
    {
        for (j = 0; j <= (index[i] - 1) / 2; j++)
        {
            temp = seq[i][j];
            seq[i][j] = seq[i][index[i] - 1 - j];
            seq[i][index[i] - 1 - j] = temp;
        }
    }
}

void display_order(int k, int index[], int seq[k][100])
{
    int j, i;
    for (i = 0; i < k; i++)
    {
        printf("Counter Number %d: ", i + 1);
        for (j = 0; j < index[i]; j++)
        {
            printf("%d ", seq[i][j]);
        }
        printf("\n");
    }
}

int closing_time(int time[], int k)
{
    int max = time[0];
    int i;
    for (i = 0; i < k; i++)
    {
        if (time[i] > max)
        {
            max = time[i];
        }
    }
    return max;
}
int waiting_time(int k, int index[], int seq[k][100])
{
    int i, j, time = 0;
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < index[i]; j++)
        {
            time += (seq[i][j]) * (index[i] - j - 1);
        }
    }
    return time;
}

int main()
{
    int n, k;
    printf("Enter N:");
    scanf("%d", &n);
    printf("Enter K:");
    scanf("%d", &k);
    int arr[n];
    int i;
    printf("Enter the processing times (separated by space)\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int index[k];
    int time[k];
    for (int i = 0; i < k; i++)
    {
        index[i] = 0;
        time[i] = 0;
    }
    int seq[k][100];
    schedule_orders_a(n, k, arr, index, seq, 0, time);
    display_order(k, index, seq);
    printf("\nClosing time:%d \n", closing_time(time, k));
    printf("\nWaiting time:%d \n", waiting_time(k, index, seq));
    for (int i = 0; i < k; i++)
    {
        index[i] = 0;
        time[i] = 0;
    }
    schedule_orders_b(n, k, arr, index, seq, 0, time);
    display_order(k, index, seq);
    printf("\nClosing time:%d \n", closing_time(time, k));
    printf("\nWaiting time:%d \n", waiting_time(k, index, seq));
    for (int i = 0; i < k; i++)
    {
        index[i] = 0;
        time[i] = 0;
    }
    schedule_orders_c(n, k, arr, index, seq, 0, time);
    display_order(k, index, seq);
    printf("\nClosing time:%d \n", closing_time(time, k));
    printf("\nWaiting time:%d \n", waiting_time(k, index, seq));
}