struct stack
{
    int size;
    int top;
    int* arr;
};



int isEmpty(struct stack* ptr)
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



int isFull(struct stack* ptr)
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



void push(struct stack* ptr, int val) {
    if (isFull(ptr)) {
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}



int pop(struct stack* ptr) {
    if (isEmpty(ptr)) {
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}



int peek(struct stack* sp, int i) {
    int arrayInd = sp->top - i + 1;
    if (arrayInd < 0) {
        printf("Not a valid position for the stack\n");
        return -1;
    }
    else {
        return sp->arr[arrayInd];
    }
}



int stackTop(struct stack* sp) {
    return sp->arr[sp->top];
}



int stackBottom(struct stack* sp) {
    return sp->arr[0];
}



int main()
{

    struct stack* s= (struct stack*)malloc(sizeof(struct stack));
    s->size = 80;
    s->top = -1;
    s->arr = (int*)malloc(s->size * sizeof(int));

    return 0;
}


//stack using linked list



struct Node {
    int data;
    struct Node* next;
};



struct Node* top = NULL;



void linkedListTraversal(struct Node* ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}



int isEmpty(struct Node* top) {
    if (top == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}



int isFull(struct Node* top) {
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    if (p == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}



struct Node* push(struct Node* top, int x) {
    if (isFull(top)) {
        printf("Stack Overflow\n");
    }
    else {
        struct Node* n = (struct Node*)malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}



int pop(struct Node* tp) {
    if (isEmpty(tp)) {
        printf("Stack Underflow\n");
    }
    else {
        struct Node* n = tp;
        top = (tp)->next;
        int x = n->data;
        free(n);
        return x;
    }
}



int peek(int pos) {
    struct Node* ptr = top;
    for (int i = 0; (i < pos - 1 && ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL) {
        return ptr->data;
    }
    else {
        return -1;
    }
}