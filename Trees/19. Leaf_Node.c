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

int getLeafCount(tree node)
{
  if(node == NULL)
    return 0;
  if(node->left == NULL && node->right==NULL)
    return 1;
  else
    return (getLeafCount(node->left)+ getLeafCount(node->right));
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
    d = getLeafCount(root);
    printf("\n\nLeaf Count = %d\n", d);
    return 0;
}

