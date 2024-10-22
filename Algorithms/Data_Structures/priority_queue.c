/*
    * Author: Bratin Mondal
    * Roll No: 21CS10016

    * Department of Computer Science and Engineering
    * Indian Institute of Technology, Kharagpur
*/
#ifndef __cplusplus
typedef enum
{
    false,
    true
} bool;
#endif

#include <stdio.h>
typedef struct node
{
    int data;

    // Lower values indicate
    // higher priority
    int priority;

    struct node *next;

} Node;

Node *newNode(int d, int p)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = d;
    temp->priority = p;
    temp->next = NULL;

    return temp;
}

bool isEmpty(struct node *head)
{
    return head == NULL;
}

int getmin(struct node *head)
{
    if (isEmpty(head))
    {
        printf("Empty priority queue.\n");
        exit(0);
    }

    return head->data;
}

Node *pop(Node *head)
{
    if (isEmpty(head))
    {
        printf("Empty priority queue.\n");
        exit(0);
    }
    Node *temp = head;
    head = head->next;
    free(temp);

    return head;
}

Node *push(Node *head, int newnum, int priority)
{
    Node *nNode = newNode(newnum, priority);
    if (head->priority > priority)
    {
        nNode->next = head;
        return nNode;
    }
    else
    {
        Node *start = head;
        Node *startprev = head;

        while (priority > start->priority)
        {
            if (start->next != NULL)
            {
                startprev = start;
                start = start->next;
            }
            else
            {
                start->next = nNode;
                return head;
            }
        }
        nNode->next = startprev->next;
        startprev->next = nNode;
    }
}