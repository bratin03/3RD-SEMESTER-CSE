/*
    * Author: Bratin Mondal
    * Roll No: 21CS10016

    * Department of Computer Science and Engineering
    * Indian Institute of Technology, Kharagpur
*/
#include <stdio.h>
void print(int arr[], int p, int arr2[])
{
    int i, sum = 0, sum2 = 0, j = 0;
    for (i = 0; i < p; i++)
    {
        printf("%d: %d  ", i + 1, arr[i]);
        sum += arr[i];
    }
    while (arr2[j] != -2)
    {
        sum2 += arr[arr2[j]];
        j++;
    }
    printf("Total vote for coalition: %d", sum2);

    printf("\n");
}

void vote_dist(int l, int r, int v, int p, int arr[], int co[])
{
    if (v == 0)
    {
        print(arr, p, co);
        return;
    }
    int arr2[p], i;
    for (i = 0; i < p; i++)
    {
        arr2[i] = arr[i];
    }
    if (l < p - 1)
    {
        vote_dist(l + 1, r, v, p, arr, co);
    }
    arr2[l] += 1;
    vote_dist(l, r, v - 1, p, arr2, co);
}

int main()
{
    int v, p, x;
    printf("Enter v:");
    scanf("%d", &v);
    printf("Enter p:");
    scanf("%d", &p);
    int a[p], b[p], i;
    for (i = 0; i < p; i++)
    {
        a[i] = 0;
    }
    i = -1;
    do
    {
        i++;
        printf("Enter Coalition Member:(-1 to end)");
        scanf("%d", &x);
        b[i] = x - 1;
    } while (x != -1);
    vote_dist(0, p - 1, v, p, a, b);
}