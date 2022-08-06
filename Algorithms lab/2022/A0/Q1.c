#include <stdio.h>
#include <stdlib.h>

int min(int a,int b){
if(a>b)return b;
return a;}

int solve(int a[],int b[],int n){
int key1=a[0],key2=b[0],exc1=0,exc2=0;
int i,ans1,ans2;
int flag1=1,flag2=1;
for(i=1;i<n;i++)
{{if(key1==a[i]||key1==b[i]){
if(key1==b[i]&&key1!=a[i])exc1++;
}
else flag1=0;
}
{if(key2==a[i]||key2==b[i]){
if(key2==a[i]&&key2!=b[i])exc2++;
}
else flag2=0;
}}
ans1=min(exc1,n-exc1);
ans2=min(exc2,n-exc2);
if(flag1==0&&flag2==0)
{return-1;}
else{
if(flag1==1&&flag2==1)
return(min(ans1,ans2));
else if(flag1==1&&flag2==0)
return ans1;
return ans2;


}
}

int main()
{
int n;
printf("Enter number of dice:");
scanf("%d",&n);
int c[n],d[n];
int i;
for(i=0;i<n;i++)
{printf("Enter number at %d position in 1st row:",i+1);
scanf("%d",&c[i]);
}
for(i=0;i<n;i++)
{printf("Enter number at %d position in 2nd row:",i+1);
scanf("%d",&d[i]);
}
printf("answer=%d\n",solve(c,d,n));

return 0;}

