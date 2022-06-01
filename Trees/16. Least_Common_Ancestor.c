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

tree lca(tree root, int n1, int n2)
{
    if(root==NULL)
        return NULL;
    if(root->data > n1 && root->data > n2)
        return lca(root->left, n1, n2);
    if(root->data < n1 && root->data < n2)
        return lca(root->right, n1, n2);
    return root;
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
    int n, d, n1, n2;
    printf("Enter the number of ele : ");
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &d);
        root = insert(root,d);
    }
    printf("\nPre Order Display\n");
    display_preorder(root);
    printf("\nEnter two value of n1 & n2 : ");
    scanf("%d %d", &n1, &n2);
    tree t = lca(root,n1,n2);
    printf("LCA of %d & %d is %d",n1,n2,t->data);
    return 0;
}

