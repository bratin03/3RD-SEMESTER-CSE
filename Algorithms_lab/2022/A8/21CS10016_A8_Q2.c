/*
    * Author: Bratin Mondal
    * Roll No: 21CS10016

    * Department of Computer Science and Engineering
    * Indian Institute of Technology, Kharagpur
*/
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
    // taking input
    int number;
    printf("Enter number of Gardens:\n");
    scanf("%d", &number);

    vertex **graph = create_graph(number);

    int edges;
    printf("Enter number of edges:\n");
    scanf("%d", &edges);

    int i;
    int head, tail;
    printf("Enter the edges in the format -- one end of the edge , other end of the edge (separated by space):\n");
    for (i = 0; i < edges; i++)
    {
        scanf("%d %d", &head, &tail);
        insert_undirected(head, tail, graph);
    }

    // taking input completed

    // visited array keeps track if we have visited a node in our process already or not (0 for not visited , 1 for not visited)
    // colour array keeps track of the colour that we have currently assigned to a node

    int visited[number + 1];
    int colour[number + 1];

    // we initialize visited with 0 and colour with 1
    for (i = 1; i <= number; i++)
    {
        visited[i] = 0;
        colour[i] = 1;
    }

    int key1, key2, key3, key4; // these variables keyi indicates if any of the neighbours contain the i-th colour(1 if doesn't contain & 0 if contains)

    vertex *p; // pointer to get hold of adjacency list

    // we iterate through all the vertex
    // turn the keys to 1 initially
    // check for its neighbours which are already visited
    // if it contains the i-th colour we turn down keyi
    // after checking the neighbours we check out which colour can be assigned to the current node and give priority to colour with lesser index
    // i.e colour 1 > colour 2 > colour 3 > colour 4

    for (i = 1; i <= number; i++)
    {
        visited[i] = 1;
        key1 = 1;
        key2 = 1;
        key3 = 1;
        key4 = 1;
        p = graph[i];
        while (p != NULL)
        {
            if (visited[p->num])
            {
                if (colour[p->num] == 1)
                    key1 = 0;
                else if (colour[p->num] == 2)
                    key2 = 0;
                else if (colour[p->num] == 3)
                    key3 = 0;
                else if (colour[p->num] == 4)
                    key4 = 0;
            }
            p = p->next;
        }

        if (key1)
            colour[i] = 1;
        else if (key2)
            colour[i] = 2;
        else if (key3)
            colour[i] = 3;
        else if (key4)
            colour[i] = 4;
    }
    int mychoice[number + 1];

    printf("Assigned Colours:\n");
    for (i = 1; i <= number; i++)
    {
        mychoice[i] = colour[i];
        printf("%d ", mychoice[i]);
    }
}
