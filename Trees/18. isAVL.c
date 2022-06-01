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

int isAVL(tree ptr)
{
        int h_l, h_r, diff;
        if(ptr == NULL)
                return 1;
        h_l = height(ptr->left);
        h_r = height(ptr->right);
        diff = h_l>h_r ? h_l-h_r : h_r-h_l;
        if( diff<=1 &&  isAVL(ptr->left) && isAVL(ptr->right) )
                return 1;
        return 0;
}

int height(tree ptr)
{
        int h_left, h_right;

        if (ptr == NULL) /*Base Case*/
                return 0;

        h_left =  height(ptr->left);
        h_right = height(ptr->right);

        if (h_left > h_right)
                return 1 + h_left;
        else
                return 1 + h_right;
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
    int n, d, flag = 0;
    printf("Enter the number of ele : ");
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &d);
        root = insert(root,d);
    }
    printf("\nPre Order Display\n");
    display_preorder(root);
    flag = isAVL(root);
    if(flag)
        printf("\n\nAVL\n");
    else
        printf("\n\nNot AVL\n");
    return 0;
}
