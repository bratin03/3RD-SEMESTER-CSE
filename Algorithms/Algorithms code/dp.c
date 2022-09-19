//Matrix Multiplication
/* Given a sequence of matrices, find the most efficient way to multiply these matrices together. The efficient way is the one that involves the least number of multiplications.

The dimensions of the matrices are given in an array arr[] of size N (such that N = number of matrices + 1) where the ith matrix has the dimensions (arr[i-1] x arr[i]).*/

    int matrixMultiplication(int N, int arr[])
    {
         int dp[N-1][N-1];
        for(int i=0;i<N-1;i++)
        {dp[i][i]=0;}
        for(int l=2;l<N;l++)
        {
            for(int i=0;i<=N-l;i++)
            {
                int j=i+l-1;
                dp[i][j]=INT_MAX;
                for(int k=i;k<j;k++)
                {
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+arr[i]*arr[k+1]*arr[j+1]);
                }
            }
            
        }
    return dp[0][N-2];}

//Rod Cutting
/*Given a rod of length N inches and an array of prices, price[]. pricei denotes the value of a piece of length i. Determine the maximum value obtainable by cutting up the rod and selling the pieces.*/

    int cutRod(int price[], int n) {
        long long int dp[n+1][n+1];
        for(int i=0;i<=n;i++)
        {
            dp[0][i]=0;
        }
        for(int j=0;j<=n;j++)
        {
            for(int i=1;i<=n;i++)
            {
                if(i<=j){dp[i][j]=max(dp[i-1][j],price[i-1]+dp[i][j-i]);}
                else dp[i][j]=dp[i-1][j];
            }
        }
    return dp[n][n];}

//Longest Common Subsequence

int size_a=strlen(a),size_b=strlen(b);//length of string
 int dp[size_a+1][size_b+1];//dp table to find lcs
 int i,j;
 for(i=0;i<=size_a;i++)
 {
  for(j=0;j<=size_b;j++)
  {
   if(i==0||j==0){dp[i][j]=0;}//first row and first column of dp table is 0
   else if(a[i-1]==b[j-1]){
    dp[i][j]=dp[i-1][j-1]+1;//increasing the length of the lcs by 1 whether the elements of string are equal
   }
   else{
    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);//otherwise taking the max of the 2 possibilities from 2 smaller subproblems
 }}}

 i=size_a;
 j=size_b;
 while(i>0 && j>0){
  if(a[i-1]==b[j-1]){
   lcs[key-1]=a[i-1];
   i--;
   j--;
   key--;
   index_a[key]=i;//saving the index for a
   index_b[key]=j;//saving the index for b
   }
  else if(dp[i-1][j]>dp[i][j-1])
   i--;
  else 
   j--;
  }