# define CAPACITY 10

int size=0;
int H[CAPACITY+1];

int Root(){
    return 1;
}

int Parent(int n)
{
    return n/2;
}

int LeftChild(int n)
{
    return 2*n;
}

int RightChild(int n)
{
    return 2*n+1;
}

bool HasParent(int n)
{
    return n!=Root();
}

bool IsNode(int n)
{
    return n<=size;
}

int getMin(int H[])
{
if (size==0)
{
    printf("Empty priority queue.\n");
    exit(0);
}

return H[Root()];
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void shiftUp(int H[],int n)
{
    while(HasParent(n)&&(H[Parent(n)]>H[n]))
    {
        swap(&H[Parent(n)],&H[n]);
        n=Parent(n);
    }
}

void push(int H[],int newNum)
{
    if(size==CAPACITY)
    {
        printf("Priority queue full.\n");
        exit(0);
    }
    H[size+1]=newNum;
    size++;
    shiftUp(H,size);
}

void shiftDown(int H[],int n)
{

    while(IsNode(LeftChild(n)))
    {
        int child=LeftChild(n);
        if(IsNode(RightChild(n))&&(H[RightChild(n)]<H[LeftChild(n)]))
        child=RightChild(n);
        if(H[n]>H[child])
        swap(&H[n],&H[child]);
        else break;
        n=child;
    }
}

void Pop(int H[])
{
    if(size==0)
    {
        printf("Empty priority queue.\n");
        exit(0);
    }

    H[Root()]=H[size];
    size--;
    shiftDown(H,Root());
}

void buildheap(int arr[],int H[],int n)
{
    for(int i=0;i<n;i++)
    {
        H[i+1]=arr[i];
    }
    size=n;
    for(int i=size/2;i>=1;i--)
    {
        shiftDown(H,i);
    }
}