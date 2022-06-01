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

NODE sort(NODE head, int k)
{
    if(head==NULL || head->next==NULL)
        return head;
    NODE temp1, temp2, temp3;
    for(NODE i = head->next; i!=NULL; i=i->next)
    {
        NODE j = i;
        while(j->prev!=NULL && j->prev->data>j->data)
        {
            temp1 = j->prev->prev;
            temp2 = j->prev;
            temp3 = j->next;
            j->prev->next = temp3;
            j->prev->prev = j;
            j->prev = temp1;
            j->next = temp2;
            if(temp1 != NULL)
                temp1->next = j;
            if(temp3 != NULL)
                temp3->prev = temp2;
        }
        if(j->prev == NULL)  //resetting the head if j->prev = NULL
            head = j;
    }
    return head;
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
        printf("%d", -1);
    }
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    NODE head = NULL;
    int t, k;
    signed int d;
    scanf("%d", &t);
    scanf("%d", &k);
    while(1)
    {
        scanf("%d", &d);
        if(d==-1)
            break;
        head = insert_end(head,d);
    }
    head = sort(head,k);
    display(head);
    return 0;
}
