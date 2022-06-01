#include<stdio.h>
#include<stdlib.h>

typedef struct binary_tree
{
    int data;
    struct binary_tree *left;
    struct binary_tree *right;
} *tree;

tree newnode(int value)
{
    tree temp = (tree)malloc(sizeof(struct binary_tree));
    temp->left = temp->right = NULL;
    temp->data = value;
    return temp;
}

tree sortedArraytoBST(int arr[], int start, int end)
{
    if(start>end)
        return NULL;
    int mid = (start+end)/2;
    tree root = newnode(arr[mid]);
    root->left = sortedArraytoBST(arr,start,mid-1);
    root->right = sortedArraytoBST(arr,mid+1,end);
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
    int n;
    int arr[10];
    printf("Enter the number of ele : ");
    scanf("%d",&n);
    printf("Enter sorted array : ");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    root = sortedArraytoBST(arr,0,n-1);
    printf("\nPre Order Display\n");
    display_preorder(root);
    return 0;
}

