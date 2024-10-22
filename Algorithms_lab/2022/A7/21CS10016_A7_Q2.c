/*
    * Author: Bratin Mondal
    * Roll No: 21CS10016

    * Department of Computer Science and Engineering
    * Indian Institute of Technology, Kharagpur
*/
#include <stdio.h>
#include <stdlib.h>

#define size 100 // defining the capacity of the hash table

// struct to implement hashtable with team id and the number of matches lost by the team
typedef struct node
{
    int id;
    int lost;
} Node;

// check if there already exists a number in an given an array till a given index
int arr_exist(int arr[], int num, int index)
{
    int i;
    for (i = 0; i <= index; i++)
    {
        if (arr[i] == num)
            return 1;
    }
    return 0;
}

// initializing hash table by setting all the indexes to -1 and lost game to 0
void init(Node hasht[])
{
    int i;
    for (i = 0; i < size; i++)
    {
        hasht[i].id = -1;
        hasht[i].lost = 0;
    }
}

// function to insert an element in the hash table using linear probing
void insert(Node hasht[], int id)
{
    int i, index, flag = 0;
    for (i = 0; i < size; i++)
    {
        index = (i + id) % size; // calculating position using linear probing

        // if the id does not exist in the hash table, we insert it and increase the number of lost game
        if (hasht[index].id == -1)
        {
            hasht[index].id = id;
            hasht[index].lost++;
            flag = 1;
            break;
        }

        // if the id already exists in the hash table, we increase the number of lost game for it
        else if (hasht[index].id == id)
        {
            hasht[index].lost++;
            flag = 1;
            break;
        }
    }
    // if hash table is already full,insertion not possible
    if (flag == 0)
        printf("Element cannot be inserted");
}

// function to search an element in the hash table using linear probing
int search(Node hasht[], int key)
{
    int i, index, flag = 0, pos;
    for (i = 0; i < size; i++)
    {
        index = (i + key) % size; // calculating position using linear probing
        if (hasht[index].id == key)
        {
            flag = 1;
            pos = index;
            break;
        }
    }
    if (flag == 1)
        return pos; // position found
    else
        return -1; // position not found,returning -1
}

int main()
{
    int n;
    // reading number of matches played
    printf("Enter number of matches played:\n");
    scanf("%d", &n);

    int arr[2][n]; // 2D array to store the input
                   // row 0 stores winning teams and row 1 stores losing teams

    int i; // loop variable

    // taking input
    printf("Enter the results of the match in the format- winning team id losing team id(separated by space):\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &arr[0][i], &arr[1][i]);
    }

    // creating and initializing the hash table
    Node hasht[size];
    init(hasht);

    int arr2[size]; // array to store the unique winner id
    int j = -1;     // index till which arr2 is filled,initiallly we take j=-1

    // looping through the matches
    // if winning team does not exist in the list arr2 we add it to the list
    // we insert the losing team to hash table
    for (i = 0; i < n; i++)
    {
        if (arr_exist(arr2, arr[0][i], j) == 0)
        {
            arr2[++j] = arr[0][i];
        }

        insert(hasht, arr[1][i]);
    }

    int ans[2][n];          // 2D array to store the answer
                            // row 0 stores teams winning all matches
                            // row 1 stores teams losing exactly one match
    int idx1 = 0, idx2 = 0; // idx1 stores the count of teams winning all matches
                            // idx2 stores the count of teams losing exactly one match

    // searching for the winner teams if they have lost no match. if so we add it to the solution set
    for (i = 0; i <= j; i++)
    {
        if (search(hasht, arr2[i]) == -1)
            ans[0][idx1++] = arr2[i];
    }

    // searching for the loser teams in the hash table if they have lost exactly one match. if so we add it to the solution set
    for (i = 0; i < n; i++)
    {
        int idx = search(hasht, arr[1][i]);
        if (hasht[idx].lost == 1)
            ans[1][idx2++] = arr[1][i];
    }

    // displaying the answer
    printf("\nTeams that have never lost so far:\n");
    for (i = 0; i < idx1; i++)
    {
        printf("%d ", ans[0][i]);
    }

    printf("\nTeams that have lost only one game:\n");
    for (i = 0; i < idx2; i++)
    {
        printf("%d ", ans[1][i]);
    }
}
