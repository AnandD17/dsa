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

int smallestValue(tree root)
{
    tree cur = root;
    while(cur->left != NULL)
        cur = cur->left;
    return (cur->data);
}

int largestValue(tree root)
{
    tree cur = root;
    while(cur->right != NULL)
        cur = cur->right;
    return (cur->data);
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
    int n, d, s, l;
    printf("Enter the number of ele : ");
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &d);
        root = insert(root,d);
    }
    printf("\nIn Order Display\n");
    display_inorder(root);
    s = smallestValue(root);
    l = largestValue(root);
    printf("\n\nSmallest = %d\nLargest = %d\n", s, l);
    return 0;
}

