// You will be given n strings.You have to create a doubly linked list and then insert the given strings into it. After Insertion, You have to perform 'Q' queries. In each query, you will be provided with a string, your task is to delete the given string from the doubly linked list. After performing all the queries, your task is print the final Doubly linked list.

//input
// 6
// arpit
// anushka
// aditya
// abhinav
// apoorv
// ashutosh
// 3
// aditya 
// abhinav
// apoorv

//output
//arpit anushka ashutosh

//code

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct node{
    char str[100];
    struct node *next;
    struct node *prev;
}*e;


e createNode(e head){
    e ptr = (e)malloc(sizeof(struct node));
    scanf("%s",ptr->str);
    
    if(head==NULL) {
        head = ptr;
        head->next=NULL;
        head->prev=NULL;
    }
    else{
        ptr->next=head;
        head->prev=ptr;
        ptr->prev=NULL;
        head=ptr;
    }
    return head;
}

e removeQuery(e head){
    char key[100];
    scanf("%s",key);
    e cur = head;
    if(!strcmp(cur->str,key)){
            head = head->next;
                return head;
        }
    while(cur!=NULL){
        if(!strcmp(cur->str,key)){
            cur->prev->next=cur->next;
            cur->next->prev=cur->prev;
            break;
        }
        cur=cur->next;
        
    }
    free(cur);
    return head;
}

void printList(e head){
    e p=head;
    while(p!=NULL){
        printf("%s ",p->str);
        p=p->next;
    }
}


int main() {
    int n;
    scanf("%d",&n);
    e head = NULL;
    for(int i = 0 ; i < n ; i++){
        head = createNode(head);
    }
    int q;
    for(int i = 0 ; i < q ; i++){
        head = removeQuery(head);
    }
    
    printList(head);

      
    return 0;
}
