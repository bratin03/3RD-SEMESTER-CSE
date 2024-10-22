/*
    * Author: Bratin Mondal
    * Roll No: 21CS10016

    * Department of Computer Science and Engineering
    * Indian Institute of Technology, Kharagpur
*/
#include <stdio.h>
#include <stdlib.h>

int method0(int *arr, int n)
{
    int a, b, c, i, j, k, ind, flag = 1;
    for (a = 1; a <= n; a++)
    {
        for (b = a + 1; b <= n; b++)
        {
            for (c = b + 1; c <= n; c++)
            {
                for (ind = 0; ind < n; ind++)
                {
                    if (arr[ind] == c)
                    {
                        i = ind;
                    }
                    else if (arr[ind] == b)
                    {
                        k = ind;
                    }
                    else if (arr[ind] == a)
                    {
                        j = ind;
                    }
                }
                if (i < j && j < k)
                    flag = 0;
                break;
            }
        }
    }
    return flag;
}

int method1(int *arr, int n)
{
    int a, b, c, flag = 1;
    for (a = 0; a < n; a++)
    {
        for (b = a + 1; b < n; b++)
        {
            for (c = b + 1; c < n; c++)
            {
                if (arr[a] > arr[c] && arr[c] > arr[b])
                {
                    flag = 0;
                    break;
                }
            }
        }
    }
    return flag;
}

int method2(int *arr, int n)
{
    int i, j, key, current, flag;
    for (i = 0; i < n; i++)
    {
        key = arr[i];
        current = arr[i];
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < key)
            {
                if (arr[j] > current)
                {
                    flag = 0;
                    break;
                }
                current = arr[j];
            }
        }
    }
    return flag;
}

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int method3(int *arr, int n)
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = n;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    int i, a = 1;
    for (i = 0; i < n; i++)
    {

        while (a <= arr[i])
        {
            push(s, a);
            a++;
        }
        if (isEmpty(s))
            return 0;
        if (s->arr[s->top] != arr[i])
            return 0;
        pop(s);
    }
    return 1;
}
void show_ans(int key)
{
    if (key)
        printf("Algolicious\n");
    else
        printf("Unalgolicious\n");
}

int main()
{
    int n, i;
    printf("Enter n:\n");
    scanf("%d", &n);
    int num[n];
    for (i = 0; i < n; i++)
    {
        printf("Enter %d element:\n", i + 1);
        scanf("%d", &num[i]);
    }
    int ans1 = method0(num, n), ans2 = method1(num, n), ans3 = method2(num, n), ans4 = method3(num, n);
    printf("Method 0:");
    show_ans(ans1);
    printf("Method 1:");
    show_ans(ans2);
    printf("Method 2:");
    show_ans(ans3);
    printf("Method 3:");
    show_ans(ans4);
}