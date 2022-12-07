#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *h;
    struct Node *v;
};

struct Node *initcal()
{
    struct Node *head[20], *new, *right;
    int i, j;
    for (i = 0; i < 20; i++)
    {
        head[i] = NULL;
        for (j = 0; j < 21; j++)
        {
            new = (struct Node *)malloc(sizeof(struct Node));
            new->h = NULL;
            new->v = NULL;
            new->data = 0;

            if (!head[i])
            {
                head[i] = new;
            }
            else
                right->h = new;
            right = new;
        }
    }
    for (i = 0; i < 19; i++)
    {

        struct Node *temp1 = head[i];
        struct Node *temp2 = head[i + 1];

        while (temp1 && temp2)
        {

            temp1->v = temp2;
            temp1 = temp1->h;
            temp2 = temp2->h;
        }
    }
    return head[0];
}

void storemonth(struct Node *c, int month, int day, int leapyear_key)
{
    int x = month % 3, y = month / 3;
    struct Node *start = c;
    int i = 0;
    for (i = 0; i < 7 * x; i++)
    {
        c = c->h;
    }
    for (i = 0; i < 5 * y; i++)
    {
        c = c->v;
    }
    struct Node *key1 = c;
    struct Node *key2 = key1->v;
    struct Node *key3 = key2->v;
    struct Node *key4 = key3->v;
    struct Node *key5 = key4->v;
    int days;
    if (month == 0 || month == 2 || month == 4 || month == 6 || month == 7 || month == 9 || month == 11)
        days = 31;
    else if (month == 1)
        days = 28 + leapyear_key;
    else
        days = 30;
    int count = 1;
    for (i = 0; i < day; i++)
    {
        key1 = key1->h;
    }
    for (i = day; i < 7; i++)
    {
        key1->data = count;
        count++;
        key1 = key1->h;
    }
    for (i = 0; i < 7; i++)
    {
        key2->data = count;
        count++;
        key2 = key2->h;
    }
    for (i = 0; i < 7; i++)
    {
        key3->data = count;
        count++;
        key3 = key3->h;
    }
    for (i = 0; i < 7; i++)
    {
        key4->data = count;
        count++;
        key4 = key4->h;
    }
    for (i = 0; i < 7; i++)
    {
        if (days < count)
            break;
        key5->data = count;
        count++;
        key5 = key5->h;
    }
    if (count < days)
    {
        while (count <= days)
        {
            c->data = count;
            count++;
            c = c->h;
        }
    }
}

void print(struct Node *head)
{
    struct Node *Rp;
    struct Node *Dp = head;
    int j = 0;
    while (Dp)
    {
        Rp = Dp;
        int i = 0;
        while (Rp)
        {
            if (Rp->data != 0)
            {
                printf("%3d ", Rp->data);
            }
            else
                printf("    ");
            Rp = Rp->h;
            i++;
            if (i % 7 == 0)
                printf("  ");
        }
        printf("\n");
        Dp = Dp->v;
        j++;
        if (j % 5 == 0)
            printf("\n\n");
    }
}
int main()
{
    struct Node *head = initcal();
    int n, leap;
    printf("Enter the first day of year:\n0:Sunday\n1:Monday\n2:Tuesday\n3:Wednesday\n4:Thursday\n5:Friday\n6:Saturday\n");
    scanf("%d", &n);
    printf("Is the year leap-year?\nLeap-year:1\nNot Leap-year:0\n");
    scanf("%d", &leap);
    int i;
    for (i = 0; i < 12; i++)
    {
        storemonth(head, i, n, leap);
        int days;
        if (i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11)
            days = 31;
        else if (i == 1)
            days = 28 + leap;
        else
            days = 30;

        n = (n + days) % 7;
    }
    print(head);
}