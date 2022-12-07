#include<stdio.h>
#include<stdlib.h>

int g[8][8]={
    {0,1,0,0,1,0,0,0},
    {0,0,1,0,1,0,0,0},
    {0,0,0,1,0,0,0,0},
    {0,1,0,0,1,0,0,0},
    {0,0,0,1,0,0,0,0},
    {1,0,0,0,1,0,0,0},
    {0,0,0,0,0,1,0,1},
    {0,0,0,0,0,1,1,0}
};
int visited[10]={0,0,0,0,0,0,0,0,0,0};

typedef struct{
    int n;
    struct node *next;
}node;


void DFS(int i)
{
    printf("%d  ",i);
    visited[i]=1;
    for(int j=0;j<8;j++)
    {
        if(g[i][j] && !visited[j])
        {
            DFS(j);
        }
    }
}

int main()
{
    int i,j;
    for(i=0;i<8;i++)
    {
        if(!visited[i])
        DFS(i);
    }
}
