
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}*e;

typedef struct node2{
    int data;
    struct node2 *next;
    struct node2 *prev;
}*p;

e newNode(e head){
    e ptr = (e)malloc(sizeof(struct node));
    scanf("%d",&ptr->data);
    ptr->next=NULL;
    ptr->prev=NULL;
    if(head == NULL) return ptr;
    e cur = head;
    while(cur->next!=NULL) cur = cur->next;
    cur->next = ptr;
    ptr->prev = cur;
    return head;
}

e swapList(e head,int k){
    e cur = head;
    p head2 = NULL;
    while(cur!=NULL){
        e v = cur;
        for(int i = 0 ; i < k ; i++){
            p ptr = (p)malloc(sizeof(struct node2));
            ptr->data = cur->data;
            ptr->prev= NULL;
            ptr->next = NULL;
            if(head2 == NULL) head2 = ptr;
            else{
                ptr->next = head2;
                head2 = ptr;
            }
            cur=cur->next;
        }
           cur = v;
        for(int i = 0 ; i < k ; i++){
            cur->data = head2->data;
            head2 = head2->next;
            cur = cur->next;
        }
        head2=NULL;
    }
    return head;
}


void printList(e head){
    while(head!=NULL){
        printf("%d ",head->data);
        head = head->next;
    }
}

int main() {
    int n,k;
    e head = NULL;
    scanf("%d%d",&n,&k);
    for(int i = 0; i<n;i++){
        head = newNode(head);
    }
    head = swapList(head,k);
    printList(head);

     
    return 0;
}