/*
    * Author: Bratin Mondal
    * Roll No: 21CS10016

    * Department of Computer Science and Engineering
    * Indian Institute of Technology, Kharagpur
*/
#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

// initializing hash table with -1(NULL)
void init(int hasht[])
{
      int i;
      for (i = 0; i < TABLE_SIZE; i++)
      {
            hasht[i] = -1;
      }
}

// inserting in hash table using linear probing
void insert(int htable[TABLE_SIZE], int ele)
{
      int i, index, flag = 0;
      for (i = 0; i < TABLE_SIZE; i++)
      {
            index = (i + ele) % TABLE_SIZE;
            if (htable[index] == -1)
            {
                  htable[index] = ele;
                  flag = 1;
                  break;
            }
      }
}

// searching and deleting an element from hash table using linear probing
int search(int htable[TABLE_SIZE], int key)
{
      int i, index, flag = 0, pos;
      for (i = 0; i < TABLE_SIZE; i++)
      {
            index = (i + key) % TABLE_SIZE;
            if (htable[index] == key)
            {
                  flag = 1;
                  pos = index;
                  htable[index] = -1;
                  break;
            }
      }
      if (flag == 1)
            return pos;
      else
            return -1;
}

int main()
{
      // taking input
      int n, i;

      printf("Enter n:\n");
      scanf("%d", &n);

      int a[n], b[n];

      printf("Enter the elements of A:(separated by space)\n");
      for (i = 0; i < n; i++)
      {
            scanf("%d", &a[i]);
      }
      printf("Enter the elements of B:(separated by space)\n");

      for (i = 0; i < n; i++)
      {
            scanf("%d", &b[i]);
      }

      // initializing hash table
      int htable[TABLE_SIZE];
      init(htable);

      // inserting elements of A in hash table
      for (i = 0; i < n; i++)
      {
            insert(htable, a[i]);
      }

      // for each element of B we check if it exists in the hash table
      // if it exists we delete it from hash table
      // if it doesn't we exit and return false as answer
      int check_key, flag = 1;
      for (i = 0; i < n; i++)
      {
            check_key = search(htable, b[i]);

            if (check_key == -1)
            {
                  flag = 0;
                  break;
            }
      }

      // displaying answer
      if (flag)
            printf("A & B are equal.\n");
      else
            printf("A & B are not equal.\n");
}
