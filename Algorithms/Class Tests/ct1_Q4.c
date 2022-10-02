#include <stdio.h>

int solve(int a[],int l,int r)
{
    if(l>=r)
    {
    int temp=a[l];
    a[l]=1;
    return temp;
    }
    int mid=(l+r)/2;
    int ls=solve(a,l,mid);
    int rs=solve(a,mid+1,r);
    int i;
    for(i=l;i<=mid;i++)
    a[i]*=rs;
    for(i=mid+1;i<=r;i++)
    a[i]*=ls;
    return ls*rs;
    
}

int main()
{int i;
int arr[6]={1,2,3,4,5,6};
    for(i=0;i<=5;i++)
    printf("%d\n",arr[i]);
    int a=solve(arr,0,5);
        for(i=0;i<=5;i++)
    printf("%d\n",arr[i]);
    
    printf("%d  \n",a);
}
