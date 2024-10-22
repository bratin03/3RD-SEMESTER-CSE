/*
    * Author: Bratin Mondal
    * Roll No: 21CS10016

    * Department of Computer Science and Engineering
    * Indian Institute of Technology, Kharagpur
*/

// Matrix Multiplication Problem
#include <iostream>
#include <climits>
using namespace std;

int matrixMultiplication(int N, int arr[])
{
    int dp[N][N];

    // Initialize the diagonal to zero as multiplying one matrix needs 0 operations
    for (int i = 1; i < N; i++)
    {
        dp[i][i] = 0;
    }

    // l is the chain length of matrices being multiplied
    for (int l = 2; l < N; l++)
    {
        for (int i = 1; i <= N - l; i++)
        {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    return dp[1][N - 1];
}

// Rod Cutting Problem
int cutRod(int price[], int n)
{
    int dp[n + 1];
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        int max_val = INT_MIN;
        for (int j = 0; j < i; j++)
        {
            max_val = max(max_val, price[j] + dp[i - j - 1]);
        }
        dp[i] = max_val;
    }
    return dp[n];
}

// Longest Common Subsequence Problem
int LCS(string a, string b)
{
    int size_a = a.length(), size_b = b.length();
    int dp[size_a + 1][size_b + 1];

    for (int i = 0; i <= size_a; i++)
    {
        for (int j = 0; j <= size_b; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Optional: Constructing the LCS string (if needed)
    int index = dp[size_a][size_b];
    string lcs(index, '\0');
    int i = size_a, j = size_b;

    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            lcs[index - 1] = a[i - 1];
            i--;
            j--;
            index--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    cout << "LCS: " << lcs << endl;
    return dp[size_a][size_b];
}

// 0-1 Knapsack Problem
int knapSack(int W, int wt[], int val[], int n)
{
    int dp[n + 1][W + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
            {
                dp[i][w] = 0;
            }
            else if (wt[i - 1] <= w)
            {
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][W];
}

// Driver function
int main()
{
    // Matrix Multiplication
    int arr[] = {1, 2, 3, 4};
    int N = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum number of multiplications: " << matrixMultiplication(N, arr) << endl;

    // Rod Cutting
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(price) / sizeof(price[0]);
    cout << "Maximum profit from rod cutting: " << cutRod(price, n) << endl;

    // Longest Common Subsequence
    string a = "AGGTAB";
    string b = "GXTXAYB";
    cout << "Length of LCS: " << LCS(a, b) << endl;

    // 0-1 Knapsack
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    n = sizeof(val) / sizeof(val[0]);
    cout << "Maximum value in Knapsack: " << knapSack(W, wt, val, n) << endl;

    return 0;
}
