//Self Implemented Adjacency List 


#include <stdio.h>
#include <stdlib.h>

typedef struct Vertex
{
    int num;
    struct Vertex *next;
} vertex;

vertex **create_graph(int num)
{
    vertex **graph = (vertex **)malloc(num * sizeof(vertex *));
    int i;
    for (i = 0; i < num; i++)
    {
        graph[i] = NULL;
    }
    return graph;
}

void insert(int head, int tail, vertex **graph)
{
    vertex *point = (vertex *)malloc(sizeof(vertex));
    point->num = tail;
    point->next = graph[head];
    graph[head] = point;
}

void print(vertex *point)
{
    vertex *p = point;
    while (p != NULL)
    {
        printf("%d ", p->num);
        p = p->next;
    }
}

void traverse_graph(vertex **graph, int num)
{
    int i;
    for (i = 0; i < num; i++)
    {
        printf("%d -->",i);
        print(graph[i]);
        printf("\n");
    }
}

int main()
{
    int num;
    printf("Enter number of vertices:\n");
    scanf("%d", &num);

    vertex **graph = create_graph(num);

    int edges;
    printf("Enter number of edges:\n");
    scanf("%d", &edges);

    int i;
    int head, tail;
    printf("Enter the edges in the format -- Head of edge , Tail of edge (separated by space):\n");
    for (i = 0; i < edges; i++)
    {
        scanf("%d %d", &head, &tail);
        insert(head, tail, graph);
    }
    traverse_graph(graph,num);
}