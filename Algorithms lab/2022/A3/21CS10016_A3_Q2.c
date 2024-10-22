/*Name:Bratin Mondal
Roll:21CS10016*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    printf("Enter the number of sweet varieties:\n"); // taking number of sweet as input
    scanf("%d", &n);
    int *time = (int *)malloc(n * sizeof(int)), *cost = (int *)malloc(n * sizeof(int)), *index = (int *)malloc(n * sizeof(int)), *take_key = (int *)malloc(n * sizeof(int));
    // time indicates the latest time to deliver
    // cost indicates the cost of an element
    // index indicates the index of the food item
    // take_key indicates for a sweet if we have taken(1) or not(0) in the process in our final answer

    // taking input
    int i, j;
    printf("Enter the latest time to deliver each item (separated by space ):");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &time[i]);
    }
    printf("Enter the cost (in Rupees) of preparing each item (separated by space ):");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &cost[i]);
    }
    // setting index
    // setting take_key for all to 0
    for (i = 0; i < n; i++)
    {
        index[i] = i + 1;
        take_key[i] = 0;
    }
    // sorting the array time and also making the subsequence changes to other arrays
    int key1, key2, key3;
    for (i = 1; i <= n - 1; i++)
    {
        key1 = time[i];
        key2 = cost[i];
        key3 = index[i];

        j = i - 1;
        // Loop for each pass
        while (j >= 0 && time[j] > key1)
        {
            time[j + 1] = time[j];
            cost[j + 1] = cost[j];
            index[j + 1] = index[j];
            j--;
        }
        time[j + 1] = key1;
        cost[j + 1] = key2;
        index[j + 1] = key3;
    }

    int result[n], count = 0, final_cost = 0; // variables for final answer

    // we start from the right most element's highest time and check for every 1 hour the possibilties we have to schedule in that 1 hour
    // among the possibilities we schedule the one with least cost or leave vacant if no possibility

    int time_key, flag, min_cost_index, min_cost;
    for (time_key = time[n - 1]; time_key > 0; time_key--)
    {
        flag = 0;
        min_cost_index = n;
        min_cost = 100000000;
        for (j = n - 1; j >= 0 && time[j] >= time_key; j--)
        {
            if (take_key[j] == 0)
            {
                flag = 1;
                if (cost[j] < min_cost)
                {
                    min_cost = cost[j];
                    min_cost_index = j;
                }
            }
        }
        if (flag == 1)
        {
            take_key[min_cost_index] = 1;
            result[count++] = index[min_cost_index];
            final_cost += cost[min_cost_index];
        }
    }

    printf("The optimal choice of sweet ietms are: ");
    // since we have executed the selection process from end
    // the array should be displayed reverse
    for (i = count - 1; i >= 0; i--)
    {
        printf("%d ", result[i]);
    }
    printf("\nThe total cost of preparing the items: Rs %d\n", final_cost);
    return 0;
}
