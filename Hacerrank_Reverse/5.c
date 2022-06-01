// You are given a doubly-linked list with 'N' nodes, rotate the linked list counter-clockwise by 'K' nodes. 'K' is a positive integer and is smaller than the number of nodes in the linked list, that is 'N'.

//input
// 2
// 4 3 9 1 7 8 -1
// 4
// 1 2 3 4 5 -1
// 2


//output
// 7 8 4 3 9 1 
// 3 4 5 1 2

//code

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
}*NODE;

NODE getNode(int d)
{
    NODE n = (NODE)malloc(sizeof(struct node));
    if(n==NULL)
        exit(0);
    //printf("Enter a number : ");
    n->data = d;
    n->next = NULL;
    n->prev = NULL;
    return n;
}

NODE insert_end(NODE head, int d)
{
    NODE temp = getNode(d);
    if(head==NULL)
        return temp;
    NODE cur = head;
    while(cur->next!=NULL)
        cur = cur->next;
    cur->next = temp;
    temp->prev = cur;
    return head;
}

NODE rotate(NODE head)
{
    if(head==NULL || head->next==NULL)
        return head;
    NODE cur = head;
    while(cur->next!=NULL)
        cur = cur->next;
    cur->next = head;
    head->prev = cur;
    head = head->next;
    head->prev->next = NULL;
    head->prev = NULL;
    return head;
}

void display(NODE head)
{
    if(head==NULL)
        printf("Linked list is empty.\n");
    else
    {
        NODE cur = head;
        while(cur!=NULL)
        {
            printf("%d ", cur->data);
            cur = cur->next;
        }
        printf("\n");
    }
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    NODE head[50] = {NULL};
    int t, k[50];
    signed int d;
    scanf("%d", &t);
    for(int i=0; i<t; i++)
    {
        while(1)
        {
             scanf("%d", &d);
             if(d==-1)
                break;
             head[i] = insert_end(head[i], d);
        }
        scanf("%d", &k[i]);
    }
    for(int i=0; i<t; i++)
    {
        for(int j=0; j<k[i]; j++)
            head[i] = rotate(head[i]);
        display(head[i]);
    }
    return 0;
}