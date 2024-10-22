/*
    * Author: Bratin Mondal
    * Roll No: 21CS10016

    * Department of Computer Science and Engineering
    * Indian Institute of Technology, Kharagpur
*/
#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};
void push(struct stack *ptr, int val)
{

    ptr->top++;
    ptr->arr[ptr->top] = val;
}

int pop(struct stack *ptr)
{

    int val = ptr->arr[ptr->top];
    ptr->top--;
    return val;
}

int main()
{
    char str[100], str2[100];
    printf("Enter the sting:\n");
    scanf("%s", str);
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 100;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    int i = 0, j, key1, key2;
    char temp;
    while (str[i] != '\0')
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
            push(s, i);
        else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
        {
            key2 = i;
            key1 = pop(s);
            for (int j = 0; j <= (key2 - key1) / 2; j++)
            {
                temp = str[key1 + j];
                str[key1 + j] = str[key2 - j];
                str[key2 - j] = temp;
            }
        }
        i++;
    }
    i = 0;
    j = 0;
    while (str[i] != '\0')
    {
        if (str[i] != '[' && str[i] != '(' && str[i] != '{' && str[i] != ')' && str[i] != '}' && str[i] != ']')
            str2[j++] = str[i];
        i++;
    }
    str2[j] = '\0';
    printf("\n%s\n", str2);
}