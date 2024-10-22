/*Name:Bratin Mondal
Roll:21CS10016*/
#include <stdio.h>
// function to return minimum of two value
int min(int a, int b)
{
    if (a > b)
        return b;
    return a;
}

int main()
{
    // taking input
    int n;
    printf("Enter sum of total number of people and dracula:\n");
    scanf("%d", &n);
    int a[n];
    printf("Enter the binary sequence of people and dracula (separated by space ):\n");
    int i, j;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int d;
    printf("Enter the distance d:\n");
    scanf("%d", &d);
    // input taking complete
    int count = 0, lflag, rflag, lmin, rmin;
    // we start from the left of the array and for every 1 we try to turn the 0 on its left at a maximum distance within the bound
    // if we don't get such 0 on left we try to turn the nearest 0 on right to turn into 1
    //  every changable 0 we turn to -1 since we want to differentiate between new & old 1
    // lflag and rflag indicates if we get such 0 on left and right respectively
    // lmin indicates 0 at maximum distance on left
    // rmin indicates 0 at minimum distance on right
    // count=answer
    // looping
    for (i = 0; i < n; i++)
    {
        // checking for 1
        if (a[i] == 1)
        {
            lflag = 0;
            rflag = 0;
            lmin = i, rmin = n;
            for (j = i - 1; (i - j) <= d && j >= 0; j--)
            { // checking 0 at max distance on left
                if (a[j] == 0)
                {
                    lflag = 1;
                    lmin = min(i, j);
                }
            }
            if (lflag == 1)
            {
                count += 1;
                a[lmin] = -1;
            }
            else
            { // if no 0 on left we check on right
                for (j = i + 1; (j - i) <= d && j < n; j++)
                {
                    if (a[j] == 0)
                    {
                        rflag = 1;
                        rmin = j;
                        break;
                    }
                }
                if (rflag == 1)
                {
                    count += 1;
                    a[rmin] = -1;
                }
            }
        }
    }
    printf("Total number of captures = %d\n", count); // printing answer
}
