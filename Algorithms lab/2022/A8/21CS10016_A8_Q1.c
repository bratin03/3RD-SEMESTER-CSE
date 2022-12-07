#include <stdio.h>
#include <stdlib.h>

// struct to store the adjacency list of a vertex with given index
// the linked list starting at a given index stores the adjacency list of the vertex at that index

typedef struct Vertex
{
    int num;
    struct Vertex *next;
} vertex;

// creates n nodes in the graph
// the adjacency list is initialized to 0
// we use 1-based indexing
// the pointer at index 0 is not used in this 1-based implementation

vertex **create_graph(int num)
{
    vertex **graph = (vertex **)malloc((num + 1) * sizeof(vertex *));
    int i;
    for (i = 1; i <= num; i++)
    {
        graph[i] = NULL;
    }
    return graph;
}

// insert directed edge
// given the head and tail of edge, inserts the tail to the begining of the adjacency list of head

void insert_directed(int head, int tail, vertex **graph)
{
    vertex *point = (vertex *)malloc(sizeof(vertex));
    point->num = tail;
    point->next = graph[head];
    graph[head] = point;
}

// insert undirected edge
// given the head and tail of edge, inserts the tail to the begining of the adjacency list of head and vice-versa

void insert_undirected(int head, int tail, vertex **graph)
{
    vertex *point = (vertex *)malloc(sizeof(vertex));
    vertex *point2 = (vertex *)malloc(sizeof(vertex));
    point->num = tail;
    point->next = graph[head];
    point2->num = head;
    point2->next = graph[tail];
    graph[head] = point;
    graph[tail] = point2;
}

int main()
{
    // creating the sample graph

    vertex **graph = create_graph(6);
    insert_undirected(1, 2, graph);
    insert_undirected(2, 3, graph);
    insert_undirected(3, 4, graph);
    insert_undirected(6, 3, graph);
    insert_undirected(1, 6, graph);
    insert_undirected(6, 5, graph);
    insert_undirected(5, 3, graph);

    // create a duplicate graph with no edge initailly
    vertex **graph2 = create_graph(6);

    // visited array keeps track if we have visited a node in our BFS already or not (0 for not visited , 1 for not visited)
    // parent array keeps track of the parent of a parent node in our final answer going through which we will be able to reach the sink
    int visited[7];
    int parent[7];

    int i; // loop variable

    // initializing visited of all elements to 0
    for (i = 1; i < 6; i++)
    {
        visited[i] = 0;
    }

    vertex *p; // pointer to get hold of adjacency list

    // using a queue for BFS,j keeps track of the begining index of the queue and k keeps track of the index where next element is to be inserted
    // curr keeps track if the poped out element

    int queue[6], j = 0, k = 0, curr;

    // we insert the node 1 to the queue,visit it and set its parent to itself
    queue[k++] = 1;
    visited[1] = 1;
    parent[1] = 1;

    // while the queue is not empty, we pop out the frontmost element, check out its neighbour
    // if a neighbour is not already visited, we visit it, create a directed edge from it to its parent in our answer graph and set its parent the poped out vertex and push it to the queue
    while (j < k)
    {
        curr = queue[j];
        j++;
        p = graph[curr];
        while (p != NULL)
        {
            if (!visited[p->num])
            {
                queue[k++] = p->num;
                visited[p->num] = 1;
                parent[p->num] = curr;
                insert_directed(p->num, curr, graph2);
            }
            p = p->next;
        }
    }

    // for all the nodes except our sink node 1, we keep checking out the parent recursively until we reach to the sink and print the path

    for (i = 2; i <= 6; i++)
    {
        printf("Path from vertex %d to sink Node 1: ", i);
        j = i;
        while (j != 1)
        {
            printf("%d -> ", j);
            j = parent[j];
        }
        printf("1\n");
    }
}
