/*
    * Author: Bratin Mondal
    * Roll No: 21CS10016

    * Department of Computer Science and Engineering
    * Indian Institute of Technology, Kharagpur
*/
/*Name:Bratin Mondal
Roll:21CS10016*/
#include <stdio.h>

// struct to store switch
struct data
{
    int key;
    int num;
    char key_arr[4];
};

// displaying the answers
void show_ans(char arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%c", arr[i]);
    }

    printf("%c", ' ');
}

// recursive function
void solve(int arr[], int n, int i, char ans[], struct data data_arr[])
{
    if (i == n)
        show_ans(ans, n); // the digit is formed when i=n and we show it
    else
    {
        int j;
        for (j = 0; j < data_arr[arr[i] - 1].num; j++)
        {
            ans[i] = data_arr[arr[i] - 1].key_arr[j]; // else we send the ans to take the next digit
            solve(arr, n, i + 1, ans, data_arr);      // recursive call
        }
    }
}

int main()
{
    int n; // taking user input
    printf("How many switche(s) to press?");
    scanf("%d", &n);
    int arr[n], i;
    // storing the keys
    struct data data_arr[8];
    data_arr[0].key = 1;
    data_arr[0].num = 3;
    data_arr[0].key_arr[0] = 'A';
    data_arr[0].key_arr[1] = 'B';
    data_arr[0].key_arr[2] = 'C';

    data_arr[1].key = 2;
    data_arr[1].num = 3;
    data_arr[1].key_arr[0] = 'O';
    data_arr[1].key_arr[1] = 'N';
    data_arr[1].key_arr[2] = 'M';

    data_arr[2].key = 3;
    data_arr[2].num = 3;
    data_arr[2].key_arr[0] = 'I';
    data_arr[2].key_arr[1] = 'H';
    data_arr[2].key_arr[2] = 'G';

    data_arr[3].key = 4;
    data_arr[3].num = 4;
    data_arr[3].key_arr[0] = 'J';
    data_arr[3].key_arr[1] = 'L';
    data_arr[3].key_arr[2] = 'K';
    data_arr[3].key_arr[3] = 'Z';

    data_arr[4].key = 5;
    data_arr[4].num = 3;
    data_arr[4].key_arr[0] = 'D';
    data_arr[4].key_arr[1] = 'F';
    data_arr[4].key_arr[2] = 'E';

    data_arr[5].key = 6;
    data_arr[5].num = 3;
    data_arr[5].key_arr[0] = 'W';
    data_arr[5].key_arr[1] = 'Y';
    data_arr[5].key_arr[2] = 'X';

    data_arr[6].key = 7;
    data_arr[6].num = 4;
    data_arr[6].key_arr[0] = 'T';
    data_arr[6].key_arr[1] = 'U';
    data_arr[6].key_arr[2] = 'V';
    data_arr[6].key_arr[3] = 'S';

    data_arr[7].key = 8;
    data_arr[7].num = 3;
    data_arr[7].key_arr[0] = 'R';
    data_arr[7].key_arr[1] = 'Q';
    data_arr[7].key_arr[2] = 'P';
    // taking the switch sequence
    for (i = 0; i < n; i++)
    {
        printf("Enter the %d switch:", i + 1);
        scanf("%d", &arr[i]);
    }
    char ans[n];                          // array to store ans
    printf("All possible messages are:"); // displaying answers
    solve(arr, n, 0, ans, data_arr);
}
