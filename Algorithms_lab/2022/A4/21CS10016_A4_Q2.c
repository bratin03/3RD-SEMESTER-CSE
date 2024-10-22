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

// max function
int max(int a, int b)
{
  if (a > b)
    return a;
  return b;
}

int main()
{ // taking input
  char a[100], b[100];
  printf("Enter the first string:");
  scanf("%s", a);
  printf("Enter the second string:");
  scanf("%s", b);
  // taking input done
  int size_a = strlen(a), size_b = strlen(b); // length of string
  int dp[size_a + 1][size_b + 1];             // dp table to find lcs
  int i, j;
  for (i = 0; i <= size_a; i++)
  {
    for (j = 0; j <= size_b; j++)
    {
      if (i == 0 || j == 0)
      {
        dp[i][j] = 0;
      } // first row and first column of dp table is 0
      else if (a[i - 1] == b[j - 1])
      {
        dp[i][j] = dp[i - 1][j - 1] + 1; // increasing the length of the lcs by 1 whether the elements of string are equal
      }
      else
      {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // otherwise taking the max of the 2 possibilities from 2 smaller subproblems
      }
    }
  }

  int key = dp[size_a][size_b], length_lcs = key, length_scs = size_a + size_b - key; // key=length_lcs . In scs the lcs characters are common from both the string.
  // so they are common and once apperance is enough to suffice both the string. So length of scs = length of a + length of b -length of lcs

  char scs[length_scs + 1], lcs[length_lcs + 1]; // string for lcs and scs
  int index_a[key], index_b[key];                // stores the index values for the strings a & b in which the characters in lcs appear
  lcs[key] = '\0';                               // for making it string
  scs[length_scs] = '\0';                        // for making it string

  // special case
  if (length_lcs == 0)
  {
    i = 0;
    j = 0;
    int curr = 0;
    while (i < size_a)
    {
      scs[curr++] = a[i++];
    }
    while (j < size_b)
    {
      scs[curr++] = b[j++];
    }
    printf("\nThe SCS length is %d\n", length_scs);
    printf("SCS string is:%s\n", scs);
    return 0;
  }

  // we aim to find the lcs and also the corresponding characters in a & b
  // we start from the right most and bottom most part of the dp table
  // if the elements in both string match we add it to lcs
  // else we check the left and upper element in dp table and depending on their values we either go up or left

  i = size_a;
  j = size_b;
  while (i > 0 && j > 0)
  {
    if (a[i - 1] == b[j - 1])
    {
      lcs[key - 1] = a[i - 1];
      i--;
      j--;
      key--;
      index_a[key] = i; // saving the index for a
      index_b[key] = j; // saving the index for b
    }
    else if (dp[i - 1][j] > dp[i][j - 1])
      i--;
    else
      j--;
  }

  // now we start from the left of the string
  // we keep adding the values in a & b to scs until we encounter an element which is part of lcs
  // on encoutering an element which is part of lcs we add it once only
  i = 0;
  j = 0;
  key = 0;
  int curr = 0;
  while (i < size_a && j < size_b)
  {
    while (i != index_a[key])
    {
      scs[curr++] = a[i++];
    }
    while (j != index_b[key])
    {
      scs[curr++] = b[j++];
    }
    scs[curr++] = a[i];
    key++;
    i++;
    j++;
  }

  // now we add the rest of the elements
  while (i < size_a)
  {
    scs[curr++] = a[i++];
  }
  while (j < size_b)
  {
    scs[curr++] = b[j++];
  }

  // displaying answer
  printf("\nThe SCS length is %d\n", length_scs);
  printf("SCS string is:%s\n", scs);
  return 0;
}
