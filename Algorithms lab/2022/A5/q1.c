#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
    struct node *inOrderSuccesor;
};

struct node* createNode(int data){
    struct node *n; // creating a node pointer
    n = (struct node *) malloc(sizeof(struct node)); // Allocating memory in the heap
    n->data = data; // Setting the data
    n->left = NULL; // Setting the left and right children to NULL
    n->right = NULL; // Setting the left and right children to NULL
    return n; // Finally returning the created node
}

struct node* minValue(struct node* node)
{
    struct node* current = node;
 
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

struct node* inOrderSuccessorfind(
    struct node* root,
    struct node* n)
{
    // step 1 of the above algorithm
    if (n->right != NULL)
        return minValue(n->right);
 
    // step 2 of the above algorithm
    struct node* p = n->parent;
    while (p != NULL && n == p->right) {
        n = p;
        p = p->parent;
    }
    return p;
}
void inOrder(struct  node* root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main ()
{

struct node* root = createNode(5);
root->left = createNode(9);
root->right = createNode(7);
root->left->left = createNode(3);
root->right->left = createNode(4);
root->right->right = createNode(1);
root->right->right->left = createNode(6);
root->right->right->right = createNode(2);

struct node* copy=root;
while(copy->left!=NULL){

copy=copy->left;
}

struct node * curr=copy;
do
{
curr->inOrderSuccesor=inOrderSuccessorfind(curr);
printf("The in order succesor of %d is %d\n",curr->data,curr->inOrderSuccesor->data);
curr=curr->inOrderSuccesor;
}while(curr->inOrderSuccesor!=NULL);


}

