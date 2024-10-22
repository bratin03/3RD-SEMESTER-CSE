#include <stdio.h>
#include <stdlib.h>

int size = 0; // size of heap (global_variable)

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
    while (HasParent(n) && (H[Parent(n)] < H[n]))
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
        if (IsNode(RightChild(n)) && (H[RightChild(n)] > H[LeftChild(n)]))
            child = RightChild(n);
        if (H[n] < H[child])
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
{
    int n, k, i;

    // taking input
    printf("Enter number of containers:\n");
    scanf("%d", &n);

    int arr[n], total = 0; // total stores the total number of sweets initially
    printf("Enter the number of sweets in the containers(separataed by space):\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        total += arr[i]; // adding the sweets to total
    }

    printf("Enter K:\n");
    scanf("%d", &k);
    // taking input done

    int heap_arr[n + 1];         // array to create the heap
    buildheap(arr, heap_arr, n); // building the heap

    int choosen;                        // chossen indicates the number of sweets in the container that we choose each time
    int taken_out, total_taken_out = 0; // taken out indicates the number of sweets that we take out from the container that we choose
                                        // total_taken_out indicates the number of total sweets taken out

    for (i = 0; i < k; i++)
    {
        choosen = Pop(heap_arr);             // choosing the container with maximum sweet
        taken_out = choosen / 2;             // taking out floor(total) sweets from the container
        total_taken_out += taken_out;        // adding the taken out sweets to total taken out sweets
        push(heap_arr, choosen - taken_out); // inserting the remaining sweets in the container to the heap
    }

    printf("Remaining total sweets: %d\n", total - total_taken_out); // printing remaining sweets
}
