/*
    * Author: Bratin Mondal
    * Roll No: 21CS10016

    * Department of Computer Science and Engineering
    * Indian Institute of Technology, Kharagpur
*/
/*Name:Bratin Mondal
Roll:21CS10016*/

#include <stdio.h>

// function to return max of 3 numbers
int three_max(int a, int b, int c)
{
  int max = a;
  if (b > max)
    max = b;
  if (c > max)
    max = c;
  return max;
}
// max function
int max(int a, int b)
{
  if (a > b)
    return a;
  return b;
}

int main()
{ // taking input
  int n;
  printf("Enter the number of days: ");
  scanf("%d", &n);
  int day1[n], day2[n];
  int i;
  printf("Enter the download size restrictions of the first website (in GB):(separated by space)");
  for (i = 0; i < n; i++)
  {
    scanf("%d", &day1[i]);
  }
  printf("Enter the download size restrictions of the second website (in GB):(separated by space)");
  for (i = 0; i < n; i++)
  {
    scanf("%d", &day2[i]);
  }
  // taking input done

  // dp matrix
  // row represents the day at which we are currently
  // column 0 represents the case of no downloading
  // column 1 represents the case of downloading through 1
  // column 2 represents the case of downloading through 2

  int dp[n][3];

  // initializing the base cases

  dp[0][0] = 0;       // no download on day 1
  dp[0][1] = day1[0]; // download through 1 on day 1
  dp[0][2] = day2[0]; // download through 2 on day 1

  for (i = 1; i < n; i++)
  {
    // while calculating on a day if we do no download on that day or download through 1 , the any of the earlier possibility is valid so we take max of the possibilities of day before
    // if we are downloading through 2 then the only possibility is no download on previous day
    dp[i][0] = three_max(dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]);
    dp[i][1] = three_max(dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]) + day1[i];
    dp[i][2] = day2[i] + dp[i - 1][0];
  }

  printf("\nMaximum possible download size is %d GB\n", max(dp[n - 1][1], dp[n - 1][2])); // the last row of dp gives us the possibilites for the maximum download. we choose the maximum element of between the 2nd & 3rd column of the last row since no download on last day is not optimal.
  return 0;
}
