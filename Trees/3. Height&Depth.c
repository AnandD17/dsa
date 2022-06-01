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

int maxDepth(tree node) //Height of the tree is equal to max depth of the tree.
{
    if (node == NULL)
        return -1;
    else {
        // compute the depth of each subtree
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);
        // use the larger one
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
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
    int n, d, h;
    printf("Enter the number of ele : ");
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &d);
        root = insert(root,d);
    }
    printf("\nIn Order Display\n");
    display_inorder(root);
    h = maxDepth(root);
    printf("\n\nHeight & Max Depth of the tree = %d\n", h);
    return 0;
}
