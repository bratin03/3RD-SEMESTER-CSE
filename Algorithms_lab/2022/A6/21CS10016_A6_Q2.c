/*
    * Author: Bratin Mondal
    * Roll No: 21CS10016

    * Department of Computer Science and Engineering
    * Indian Institute of Technology, Kharagpur
*/
#include <stdio.h>
#include <stdlib.h>

int size = 0; // size of heap(global_variable)

// functions for checking connections in the heap(1-based indexing of array)

int Root()
{
    return 1; // returns index of Root
}

int Parent(int n)
{
    return n / 2; // returns index of Parent
}

int LeftChild(int n)
{
    return 2 * n; // returns index of Left Child
}

int RightChild(int n)
{
    return 2 * n + 1; // returns index of Right Child
}

int HasParent(int n)
{
    return n != Root(); // returns if the node has a parent
}

int IsNode(int n)
{
    return n <= size && n >= 1; // returns if there exists a node in the heap at a given index
}

// swap function

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// shift up function for the heap at a given index

void shiftUp(int H[], int n)
{
    while (HasParent(n) && (H[Parent(n)] > H[n]))
    {
        swap(&H[Parent(n)], &H[n]);
        n = Parent(n);
    }
}

// push function to insert new element

void push(int H[], int newNum)
{
    H[size + 1] = newNum; // insertion at end
    size++;
    shiftUp(H, size); // shifting up to desired location
}

// shift down function for the heap at a given index

void shiftDown(int H[], int n)
{

    while (IsNode(LeftChild(n)))
    {
        int child = LeftChild(n);
        if (IsNode(RightChild(n)) && (H[RightChild(n)] < H[LeftChild(n)]))
            child = RightChild(n);
        if (H[n] > H[child])
            swap(&H[n], &H[child]);
        else
            break;
        n = child;
    }
}

// Pop function to extract and delete the topmost element of the heap

int Pop(int H[])
{
    if (size == 0) // check if Pop is possible
    {
        printf("Empty priority queue.\n");
        exit(0);
    }
    int key = H[Root()]; // extracting the value at the Root

    H[Root()] = H[size];  // shifting the last element to the Root
    size--;               // deleting the last node
    shiftDown(H, Root()); // shifting down the Root
    return key;
}

// Function to build heap from an array
void buildheap(int arr[], int H[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        H[i + 1] = arr[i]; // copying the elements
    }
    size = n;
    for (i = size / 2; i >= 1; i--)
    {
        shiftDown(H, i); // shifting down the nodes with children
    }
}

int main()
{ // storing the arrays

    int arr1[64] = {647, 225, 200, 820, 789, 338, 72, 274, 407, 577, 306, 167, 928, 40, 417, 86, 751, 384, 697, 144, 137, 823, 241, 986, 665, 468, 225, 121, 372, 143, 86, 737, 86, 4, 557, 874, 341, 628, 148, 748, 923, 173, 633, 852, 212, 50, 656, 681, 153, 353, 824, 8, 176, 783, 993, 559, 970, 936, 399, 61, 797, 203, 797, 882};

    int arr2[60] = {206, 354, 757, 547, 700, 623, 14, 623, 514, 646, 194, 444, 414, 849, 125, 566, 202, 948, 292, 96, 732, 285, 374, 702, 940, 772, 762, 737, 974, 559, 620, 898, 631, 96, 445, 331, 437, 177, 672, 951, 822, 866, 395, 955, 715, 520, 240, 636, 187, 532, 731, 637, 535, 823, 339, 475, 314, 819, 931, 7};

    // taking k as input
    int k;
    printf("Enter K:\n");
    scanf("%d", &k);

    int i, j; // loop variables

    int A[3840]; // declaring A

    // constructing A
    for (i = 0; i < 64; i++)
    {
        for (j = 0; j < 60; j++)
        {
            A[60 * i + j] = arr1[i] + arr2[j];
        }
    }

    // initializing the Heap
    int Heap[3841];
    buildheap(A, Heap, 3840); // building the Heap

    // showing the output
    printf("Output:\n");
    for (i = 0; i < k; i++)
    {
        printf("%d ", Pop(Heap));
    }
}
