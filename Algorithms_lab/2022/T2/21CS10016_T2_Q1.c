/*
    * Author: Bratin Mondal
    * Roll No: 21CS10016

    * Department of Computer Science and Engineering
    * Indian Institute of Technology, Kharagpur
*/
#include <stdio.h>
#include <stdlib.h>

// node
struct node
{
    int key;
    struct node *left, *right;
};

// create node function
struct node *createNode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// getting the sample tree
struct node *getSampleTree()
{
    struct node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);
    root->left->left->left = createNode(8);
    root->left->left->right = createNode(9);
    root->left->right->left = createNode(10);
    root->left->right->right = createNode(11);
    root->right->left->left = createNode(12);
    root->right->left->right = createNode(13);
    root->right->right->left = createNode(14);
    root->right->right->right = createNode(15);

    return root;
}

// level traversal function
void level_traversal(struct node *root)
{
    struct node *queue[100], *temp = root; // using queue
    int i = 0, j = 0;
    queue[i++] = temp; // pushing the root

    // until the queue is empty,we extract the frontmost element,push its child (if they exist) and print the extracted element
    while (i > j)
    {
        temp = queue[j];
        j++;
        if (temp->left)
            queue[i++] = temp->left;
        if (temp->right)
            queue[i++] = temp->right;
        printf("%d ", temp->key);
    }
    printf("\n");
}

// fucntion to modify the tree
void change(struct node *root)
{
    struct node *arr[100], *temp = root; // using an array to store the elements
    int i = 0, j = 0;

    arr[i++] = temp; // pushing the root to array

    // similar to level traversal, we push all the nodes in the array
    while (i > j)
    {
        temp = arr[j];
        j++;
        if (temp->left)
            arr[i++] = temp->left;
        if (temp->right)
            arr[i++] = temp->right;
    }

    // we traverse the whole array
    // if it is an odd level, we mirror the elments
    // otherwise we skip it
    // k and x keep tracks of the index of a particular level
    int k = 0, x = 1, flag = 0, l, r, temp2;

    while (k < j)
    {
        if (flag == 0) // skipping even level
        {
            k += x;
            x *= 2;
            flag = 1;
        }

        if (flag == 1) // making swaps on odd level
        {
            // bound for the swaps
            l = k;
            r = k + x - 1;

            // making the swaps
            for (i = l; i <= (l + r) / 2; i++)
            {
                temp2 = arr[i]->key;
                arr[i]->key = arr[r + l - i]->key;
                arr[r + l - i]->key = temp2;
            }

            k += x;
            x *= 2;
            flag = 0;
        }
    }
}

int main()
{
    struct node *tree = getSampleTree();
    printf("Initial level order traversal:\n");
    level_traversal(tree);

    // making the change
    change(tree);
    printf("Final level order traversal:\n");
    level_traversal(tree);
}
