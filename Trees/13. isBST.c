#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* left, *right;
}*tree;

tree createnode(int key)
{
    tree newnode = (tree)malloc(sizeof(struct node));
    newnode->data = key;
    newnode->left = NULL;
    newnode->right = NULL;
    return(newnode);
}

void inorder(struct node *root)
{
    if(root !=NULL)
    {
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}

int isBST(tree root)
{
    if(root==NULL)
        return 1;
    if(root->left != NULL && root->left->data > root->data)
        return 0;
    if(root->right != NULL && root->right->data < root->data)
        return 0;
    if(!isBST(root->left) || !isBST(root->right))
        return 0;
    return 1;
}

int main()
{
    int flag = 0;
    tree newnode = createnode(25);
    newnode->left = createnode(27);
    newnode->right = createnode(19);
    newnode->left->left = createnode(17);
    newnode->left->right = createnode(91);
    newnode->right->left = createnode(13);
    newnode->right->right = createnode(55);
    printf("Inorder traversal of Input Binary Tree is\n");
    inorder(newnode);
    flag = isBST(newnode);
    if(flag)
        printf("\nTree is a BST.");
    else
        printf("\nTree is not a BST.");
    return 0;
}
