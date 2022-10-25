//normal hash table

#include<stdio.h>

#define size 100

int arr[size];


void init()
{   
    int i;
    for(i = 0; i < size; i++)
        arr[i] = -1;
}

void insert(int value)
{   
    int key = value % size;
    
    if(arr[key] == -1)
    {   
        arr[key] = value;
        printf("%d inserted at arr[%d]\n", value,key);
    }
    else
    {   
        printf("Collision : arr[%d] has element %d already!\n",key,arr[key]);
        printf("Unable to insert %d\n",value);
    }
}

void del(int value)
{
    int key = value % size;
    if(arr[key] == value)
        arr[key] = -1;
    else
        printf("%d not present in the hash table\n",value);
}

void search(int value)
{
    int key = value % size;
    if(arr[key] == value)
        printf("Search Found\n");
    else
        printf("Search Not Found\n");
}

void print()
{
    int i;
    for(i = 0; i < size; i++)
        printf("arr[%d] = %d\n",i,arr[i]);
}

//separate chaining

#include<stdio.h>
#include<stdlib.h>

#define size 100

struct node
{
    int data;
    struct node *next;
};

struct node *chain[size];

void init()
{
    int i;
    for(i = 0; i < size; i++)
        chain[i] = NULL;
}

void insert(int value)
{
    //create a newnode with value
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    //calculate hash key
    int key = value % size;

    //check if chain[key] is empty
    if(chain[key] == NULL)
        chain[key] = newNode;
    //collision
    else
    {
        //add the node at the end of chain[key].
        struct node *temp = chain[key];
        while(temp->next)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

/*
 * return 1, search found
 * return 0, Otherwise
 */
 
 int del(int value)
{
    int key = value % size;
    struct node *temp = chain[key], *dealloc;
    if(temp != NULL)
    {
        if(temp->data == value)
        {
            dealloc = temp;
            temp = temp->next;
            free(dealloc);
            return 1;
        }
        else
        {
            while(temp->next)
            {
                if(temp->next->data == value)
                {
                    dealloc = temp->next;
                    temp->next = temp->next->next;
                    free(dealloc);
                    return 1;
                }
                temp = temp->next;
            }
        }
    }

    return 0;
}

int search(int value)
{
    int key = value % size;
    struct node *temp = chain[key];
    while(temp)
    {
        if(temp->data == value)
            return 1;
        temp = temp->next;
    }
    return 0;
}

void print()
{
    int i;

    for(i = 0; i < size; i++)
    {
        struct node *temp = chain[i];
        printf("chain[%d]-->",i);
        while(temp)
        {
            printf("%d -->",temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

//linear probing

#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 5

void insert(int[], int);
void delete(int[], int);
void search(int[], int);
void display(int[]);

int main()
{
	int htable[TABLE_SIZE]={};
	int i;
	for(i=0;i<TABLE_SIZE;i++)
		htable[i] = -1;
	int ch,ele;
	while(1)
	{
		printf("Current Table: ");
		display(htable);
		printf("\n1. Insert Element\n2. Delete Element\n3.Search Element\n4.EXIT\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				printf("Enter element to be inserted: ");
				scanf("%d", &ele);
				insert(htable, ele);
				break;
			case 2:
				printf("Enter element to be deleted: ");
				scanf("%d", &ele);
				delete(htable, ele);
				break;
			case 3:
				printf("Enter element to be searched: ");
				scanf("%d", &ele);
				search(htable, ele);
				break;
			case 4:
				exit(0);
			default:
				printf("Invalid Choice\n");
		}
	}
	return 0;
}

void insert(int htable[TABLE_SIZE], int ele)
{
	int i, index,flag=0;
	for(i=0; i<TABLE_SIZE; i++)
	{
		index = (i+ele)%TABLE_SIZE;
		if(htable[index] == -1)
		{
			htable[index] = ele;
			flag = 1;
			break;
		}
	}
	if(flag == 0)
		printf("Element cannot be inserted\n");
	else
		printf("Element Successfully Inserted\n");
}

void delete(int htable[TABLE_SIZE], int ele)
{
	int i, index,flag=0;
	for(i=0;i<TABLE_SIZE;i++)
	{
		index = (i+ele)%TABLE_SIZE;
		if(htable[index] == ele)
		{
			htable[index] = -1;
			flag =1;
			break;
		}
	}
	if(flag == 1)
		printf("Element successfully deleted\n");
	else
		printf("Element cannot be deleted\n");
}

void search(int htable[TABLE_SIZE], int key)
{
	int i, index,flag=0,pos;
	for(i=0;i<TABLE_SIZE;i++)
	{
		index = (i+key)%TABLE_SIZE;
		if(htable[index] == key)
		{
			flag = 1;
			pos = index;
			break;
		}
	}
	if(flag == 1)
		printf("Element Found at Position: %d\n", pos);
	else
		printf("Element Not Found\n");
}

void display(int htable[TABLE_SIZE])
{
	int i;
	for(i=0;i<TABLE_SIZE;i++)
		printf("%d ", htable[i]);
}

//it can be modified to quadratic probing and double hashing

//modify

void insert(int htable[TABLE_SIZE], int ele)
{
	int i, index,flag=0;
	for(i=0; i<TABLE_SIZE; i++)
	{
		index = (i+ele)%TABLE_SIZE;
		if(htable[index] == -1||htable[index] == -2)
		{
			htable[index] = ele;
			flag = 1;
			break;
		}
	}
	if(flag == 0)
		printf("Element cannot be inserted\n");
	else
		printf("Element Successfully Inserted\n");
}

void delete(int htable[TABLE_SIZE], int ele)
{
	int i, index,flag=0;
		index=ele%TABLE_SIZE;
	while(htable[index]!=-1&&i<TABLE_SIZE)
	{
	   if(hashtable[index]==ele)
	   {
	      htable[index] = -2;
	      flag=1;
	      break;
	   }
	      index++;
	      i++;
	      index%=TABLE_SIZE;
	}

	if(flag == 1)
		printf("Element successfully deleted\n");
	else
		printf("Element cannot be deleted\n");
}

void search(int htable[TABLE_SIZE], int key)
{
	int i=0, index,flag=0,pos;
	index=key%TABLE_SIZE;
	while(htable[index]!=-1&&i<TABLE_SIZE)
	{
	   if(hashtable[index]==key)
	   {
	      pos=index;
	      flag=1;
	      break;
	   }
	      index++;
	      i++;
	      index%=TABLE_SIZE;
	}
	if(flag == 1)
		printf("Element Found at Position: %d\n", pos);
	else
		printf("Element Not Found\n");
}

