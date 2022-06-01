#include<stdio.h>
#include<stdlib.h>

typedef struct avl_tree
{
    int data;
    int height;
    struct avl_tree *left;
    struct avl_tree *right;
}*tree;

int height(tree node)
{
    if(node==NULL)
        return 0;
    return 1+max(height(node->left), height(node->right));
}

int max(int a, int b)
{
    return(a > b)? a : b;
}

int getBalanceFactor(tree n)
{
    if(n==NULL)
        return 0;
    return (height(n->left) - height(n->right));
}

tree leftRotate(tree x)
{
    tree y = x->right;
    tree z = y->left;
    y->left = x;
    x->right = z;
    x->height = height(x);
    y->height = height(y);
    return y;
}

tree rightRotate(tree x)
{
    tree y = x->left;
    tree z = y->right;
    y->right = x;
    x->left = z;
    x->height = height(x);
    y->height = height(y);
    return y;
}

tree newnode(int value)
{
    tree node = (tree)malloc(sizeof(struct avl_tree));
    node->data = value;
    node->height = 0;
    node->left = node->right = NULL;
    return node;
}

tree insert(tree root, int value)
{
    tree node = newnode(value);
    if(root==NULL)
        return node;
    if(value<root->data)
        root->left = insert(root->left, value);
    else if(value>root->data)
        root->right = insert(root->right, value);
    else
        return root;

    root->height = height(root);
    int bFactor = getBalanceFactor(root);

    if(bFactor>1 && value<root->left->data)
        return rightRotate(root);
    if(bFactor<-1 && value>root->right->data)
        return leftRotate(root);
    if(bFactor>1 && value>root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if(bFactor<-1 && value<root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

void display_inorder(tree root)
{
    if(root==NULL)
        return;
    display_inorder(root->left);
    printf("%d\t",root->data);
    display_inorder(root->right);
}

void display_preorder(tree root)
{
    if(root==NULL)
        return;
    printf("%d\t", root->data);
    display_preorder(root->left);
    display_preorder(root->right);
}

int main()
{
    tree root = NULL;
    int n, d;
    printf("Enter the number of ele : ");
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &d);
        root = insert(root,d);
    }
    printf("\nPre Order Display\n");
    display_preorder(root);
    printf("\n\nIn Order Display\n");
    display_inorder(root);
    return 0;
}