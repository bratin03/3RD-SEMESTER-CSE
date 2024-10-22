#include <stdio.h>
#include <stdlib.h>

int size = 0; // size of heap (global_variable)

typedef struct Node
{
    double p;   // pass i
    double t;   // total i
    double inc; // indicates the change in pass percentage of that class if we introduce an extra student in that class
    // inc=(p+1)/(t+1)-p/t
    // inc will be the key for max heap
} node;

// initalizing node with given passi and totali
node *createnode(double p, double t)
{
    node *create = (node *)malloc(sizeof(node));
    create->p = p;
    create->t = t;
    create->inc = (p + 1) / (t + 1) - p / t;

    return create;
}

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

void swap(node *xp, node *yp)
{
    node temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// shift up function for the heap at a given index

void shiftUp(node H[], int n)
{
    while (HasParent(n) && (H[Parent(n)].inc < H[n].inc))
    {
        swap(&H[Parent(n)], &H[n]);
        n = Parent(n);
    }
}

// push function to insert new element

void push(node H[], node new)
{
    H[size + 1] = new; // insertion at end
    size++;
    shiftUp(H, size); // shifting up to desired location
}

// shift down function for the heap at a given index

void shiftDown(node H[], int n)
{

    while (IsNode(LeftChild(n)))
    {
        int child = LeftChild(n);
        if (IsNode(RightChild(n)) && (H[RightChild(n)].inc > H[LeftChild(n)].inc))
            child = RightChild(n);
        if (H[n].inc < H[child].inc)
            swap(&H[n], &H[child]);
        else
            break;
        n = child;
    }
}

// Pop function to extract and delete the topmost element of the heap

node Pop(node H[])
{
    node key = H[Root()]; // extracting the value at the Root

    H[Root()] = H[size];  // shifting the last element to the Root
    size--;               // deleting the last node
    shiftDown(H, Root()); // shifting down the Root
    return key;
}

// Function to build heap from an array

void buildheap(node arr[], node H[], int n)
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
{ // taking input
    int n, i;
    printf("Enter the number of classes:\n");
    scanf("%d", &n);
    double input[n][2];
    node input_arr[n], *temp, temp2;

    printf("Enter the pass and total students in the sujects:(separated by space in the format --  passi  totali)\n");
    for (i = 0; i < n; i++)
    {
        scanf("%lf %lf", &input[i][0], &input[i][1]); // taking input
        temp = createnode(input[i][0], input[i][1]);  // creating node with the input
        input_arr[i] = *temp;
    }

    node heap[n + 1];              // heap initialized
    buildheap(input_arr, heap, n); // buliding the heap

    // taking input for extra number of students
    int extra;
    printf("Enter number of extra students:\n");
    scanf("%d", &extra);

    // we push each extra student in the class which will give maximum increase in the average pass percentage
    for (i = 0; i < extra; i++)
    {
        temp2 = Pop(heap);
        temp2.p = temp2.p + 1;
        temp2.t = temp2.t + 1;
        temp2.inc = (temp2.p + 1) / (temp2.t + 1) - (temp2.p) / (temp2.t);
        push(heap, temp2);
    }

    // adding contribution of each class to pass percentage
    double pass_ratio = 0;
    for (i = 1; i <= n; i++)
    {
        pass_ratio += (heap[i].p / heap[i].t);
    }

    // taking the average
    pass_ratio /= n;

    // displaying the answer
    printf("Average pass ratio:%lf\n", pass_ratio);
}
