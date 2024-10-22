/*
    * Author: Bratin Mondal
    * Roll No: 21CS10016

    * Department of Computer Science and Engineering
    * Indian Institute of Technology, Kharagpur
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data;
    struct Node *next;
};
void printReverse(struct Node *head)
{

    if (head == NULL)
        return;

    printReverse(head->next);

    printf("%d", head->data);
}

int main()
{
    char num1[100], num2[100];
    printf("Enter Number 1:");
    scanf("%s", num1);
    printf("Enter Number 2:");
    scanf("%s", num2);
    int len1 = strlen(num1), len2 = strlen(num2);
    struct Node *head1 = NULL, *head2 = NULL, *p, *prev, *head3 = NULL;
    int i;
    for (i = len1 - 1; i >= 0; i--)
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = num1[i] - '0';
        p->next = NULL;
        if (head1 == NULL)
            head1 = p;
        else
            prev->next = p;
        prev = p;
    }
    for (i = len2 - 1; i >= 0; i--)
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = num2[i] - '0';
        p->next = NULL;
        if (head2 == NULL)
            head2 = p;
        else
            prev->next = p;
        prev = p;
    }
    int carry = 0, sum;
    struct Node *ptr1 = head1, *ptr2 = head2;
    while (ptr1 != NULL || ptr2 != NULL)
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        if (ptr1 != NULL && ptr2 != NULL)
        {
            sum = ptr1->data + ptr2->data + carry;
            p->data = sum % 10;
            carry = sum / 10;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if (ptr1 != NULL && ptr2 == NULL)
        {
            sum = ptr1->data + carry;
            p->data = sum % 10;
            carry = sum / 10;
            ptr1 = ptr1->next;
        }
        else if (ptr1 == NULL && ptr2 != NULL)
        {
            sum = ptr2->data + carry;
            p->data = sum % 10;
            carry = sum / 10;
            ptr2 = ptr2->next;
        }
        p->next = NULL;
        if (head3 == NULL)
            head3 = p;
        else
            prev->next = p;
        prev = p;
    }

    if (carry != 0)
    {
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = carry;
        p->next = NULL;
        if (head3 == NULL)
            head3 = p;
        else
            prev->next = p;
        prev = p;
    }
    printReverse(head3);
    printf("\n");
    return 0;
}
