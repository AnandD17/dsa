#include<stdio.h>
#include<stdlib.h>

typedef struct binary_tree
{
    int data;
    struct binary_tree *left;
    struct binary_tree *right;
} *tree;

tree insert(tree root, int value)
{
    tree temp = NULL;
    if(root==NULL)
    {
        temp = (tree)malloc(sizeof(struct binary_tree));
        temp->left = temp->right = NULL;
        temp->data = value;
        root = temp;
        return root;
    }
    if(value<root->data)
        root->left = insert(root->left, value);
    else if(value>root->data)
            root->right = insert(root->right, value);
    return root;
}

int left_height(tree root)
{
    int ht = 0;
    while(root)
    {
        ht++;
        root = root->left;
    }
    return ht;
}

int right_height(tree root)
{
    int ht = 0;
    while(root)
    {
        ht++;
        root = root->right;
    }
    return ht;
}

int no_of_nodes(tree root)
{
    if(root==NULL)
        return 0;
    int lh = left_height(root);
    int rh = right_height(root);
    if(rh==lh)
        return (1<<lh)-1;
    return (1 + no_of_nodes(root->left) + no_of_nodes(root->right));
}

void display_inorder(tree root)
{
    if(root==NULL)
        return;
    display_inorder(root->left);
    printf("%d\t",root->data);
    display_inorder(root->right);
}

int main()
{
    tree root = NULL;
    int n, d, n_nodes;
    printf("Enter the number of ele : ");
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &d);
        root = insert(root,d);
    }
    printf("\nIn Order Display\n");
    display_inorder(root);
    n_nodes = no_of_nodes(root);
    printf("\n\nTotal No. Of Nodes = %d\n", n_nodes);
    return 0;
}

