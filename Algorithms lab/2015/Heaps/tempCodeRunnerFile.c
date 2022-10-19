int deleteMax(Node H[])
{
    if(size==0)
    {
        printf("Empty priority queue.\n");
        exit(0);
    }
    int num=H[Root()].priority;
    H[Root()]=H[size];
    size--;
    shiftDown2(H,Root());
    return num
}