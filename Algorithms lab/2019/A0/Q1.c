#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next1;
    struct Node *next2;
};

struct Node *search(struct Node *r, int value)
{
    struct Node *p;
    p = r;
    while (p != NULL)
    {
        if (p->data == value)
            return p;
        p = p->next1;
    }
    return p;
}

struct Node *createlist1(int n, int a)
{
    struct Node *head = NULL, *p, *prev;
    int i;
    for (i = a; i <= n; i = i + a)
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = i;
        p->next1 = NULL;
        p->next2 = NULL;
        if (head == NULL)
            head = p;
        else
            prev->next1 = p;
        prev = p;
    }
    return head;
}
struct Node *createlist2(int n, int a, int b, struct Node *A)
{
    struct Node *head = NULL, *p, *prev, *A1 = A;
    int i;
    for (i = b; i <= n; i = i + b)
    {
        if (i % a == 0)
        {
            while (A1 != NULL)
            {
                if (A1->data == i)
                    break;
                A1 = A1->next1;
            }
            p = A1;
            p->next2 = NULL;
        }
        else
        {
            p = (struct Node *)malloc(sizeof(struct Node));
            p->data = i;
            p->next1 = NULL;
            p->next2 = NULL;
        }
        if (head == NULL)
            head = p;
        else
            prev->next2 = p;
        prev = p;
    }
    return head;
}

void printlist(struct Node *ptr, int key)
{
    if (key == 1)
    {

        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next1;
        }
        printf("\n");
    }
    if (key == 2)
    {

        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next2;
        }
        printf("\n");
    }
}

void prnboth(struct Node *A, struct Node *B)
{
    struct Node *key1 = A, *key2 = B;
    while (key1 != NULL || key2 != NULL)
    {
        if (key1 != NULL && key2 != NULL)
        {
            if (key1->data == key2->data)
            {
                printf("%d ", key1->data);
                key1 = key1->next1;
                key2 = key2->next2;
            }
            else if (key1->data < key2->data)
            {
                printf("%d ", key1->data);
                key1 = key1->next1;
            }
            else
            {
                printf("%d ", key2->data);
                key2 = key2->next2;
            }
        }
        else if (key1 == NULL)
        {
            printf("%d ", key2->data);
            key2 = key2->next2;
        }
        else if (key2 == NULL)
        {
            printf("%d ", key1->data);
            key1 = key1->next1;
        }
    }
    printf("\n");
}

int main()
{
    int n, a, b;
    printf("Enter n:\n");
    scanf("%d", &n);
    printf("Enter a:\n");
    scanf("%d", &a);
    printf("Enter b:\n");
    scanf("%d", &b);
    struct Node *A, *B;
    A = createlist1(n, a);
    B = createlist2(n, a, b, A);
    printlist(A, 1);
    printlist(B, 2);
    prnboth(A, B);
}
