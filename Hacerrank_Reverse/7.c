// Given a doubly-linked list, a position p, and an integer x. The task is to add a new node with value x at the position just after pth node in the doubly linked list.
//code

#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
struct node *prev;
};
struct node * createnode()
{
    return ((struct node *)malloc(sizeof(struct node)));
}
void readinfo(struct node *p)
{
   scanf("%d",&p->data);
}
struct node *createlist(int N)
{
    struct node *nw,*temp,*head;
    int i;
    temp=head=NULL;
    for(i=0;i<N;i++)
    {
    nw=createnode();
    readinfo(nw);
    nw->next=NULL;
    if(head==NULL)
    {
        temp=head=nw;
        head->prev=NULL;
    }
    else
    {
     nw->prev=temp;
     temp->next=nw;
     temp=nw;
    }
    }
return(head);
}
void display(struct node *p)
{
    struct node *temp;
    temp=p;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}
void addnode(struct node *p,int n,int x)
{
  struct node *temp,*nw,*head;
  head=p;
  int i=1;
  nw=createnode();
  nw->data=x;
  nw->next=NULL;
  nw->prev=NULL;
  if(head==NULL)
  {
      head=nw;
  }
  else
  {
      for(temp=p;i<n&&temp->next!=NULL;temp=temp->next,i++);
      nw->next=temp->next;
      temp->next=nw;
      nw->prev=temp;
      if(temp->next!=NULL)
      {
      (temp->next)->prev=nw;
      }
     }
  display(head);
}
int  main()
{
    struct node *head;
    int N,p,x;
    scanf("%d",&N);
    head=createlist(N);
    scanf("%d%d",&p,&x);
    addnode(head,p,x);
   return(0);
}