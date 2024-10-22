/*Name:Bratin Mondal
Roll:21CS10016*/
#include <stdio.h>
#include <string.h>

int main()
{ // taking input
   int n, m;
   printf("Enter the number of assignments(n):\n");
   scanf("%d", &n);
   printf("Enter the total number of hours left:\n");
   scanf("%d", &m);
   int i, j, hours[n], key1;
   printf("Enter the number of hours to solve each assignement:(separated by space)\n");
   for (i = 0; i < n; i++)
   {
      scanf("%d", &hours[i]);
   } // taking input done
   // sorting the input
   for (i = 1; i <= n - 1; i++)
   {
      key1 = hours[i];
      j = i - 1;
      while (j >= 0 && hours[j] > key1)
      {
         hours[j + 1] = hours[j];
         j--;
      }
      hours[j + 1] = key1;
   }
   int ans = 0;
   i = 0;
   // adding assignments until the time limit is crossed or all the assignements are added
   while (ans < m && i < n)
   {
      ans += hours[i];
      i++;
   }
   if (ans > m)
   {
      ans -= hours[i - 1];
   }
   printf("Minimum Effort Needed : %d\n", ans);
}
