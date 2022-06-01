#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node* Node;

Node getnode(int data)
{
    Node nw;
    nw=(Node)malloc(sizeof(struct node));
    if(nw==NULL)//Stack full
    {
        return(nw);
    }
    nw->data=data;
    return(nw);
}

Node push(Node first,int data)
{
   Node nw;
    nw=getnode(data);
    if(first==NULL)
    {
        first=nw;
        nw->next=NULL;
        return(first);
    }
    else
    {
        nw->next=first;
        first=nw;
        return(first);
    }

}

Node pop(Node first)
{
    Node temp=first;
    if(first==NULL)
    {
        return(first);
    }
    else if(first->next==NULL)
    {
        free(temp);
        first=NULL;
        return(first);
    }
    else
    {
        first=first->next;
        free(temp);
        return(first);
    }
}

int main()
{

    int n,i,data;
    Node first1=NULL,first2=NULL,temp1,temp2;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&data);
        first1=push(first1,data);
    }
    for(i=0;i<n;i++)
    {
        scanf("%d",&data);
        first2=push(first2,data);
    }
    temp1=first1;
    temp2=first2;
    while(temp1!=NULL && temp2!=NULL)
    {
        if(temp1->data==temp2->data)
        {
            printf("%d ",0);
            temp1=pop(temp1);
            temp2=pop(temp2);
        }
        else if(temp1->data>temp2->data)
        {
            printf("%d ",1);
            temp2=pop(temp2);
        }
        else
        {
            printf("%d ",2);
            temp1=pop(temp1);
        }
    }
    return 0;
}