// Stuart came up with a Stack problem! He first learns about stacks. Stack is a basic data structure where 3 operations can be done:

// Push: You can push an element to the stack

// Pop: You can pop the element from the stack

// Top: You can access the value of the top element. He wants to modify the stack to perform the following operations as efficiently as possible!

// There are 3 types of operations as describe below:

// push x: Push element x onto the top of the stack.

// pop: Pop the top element from the stack if not empty.

// inc k v: Add v to each of the bottom k elements of the stack using above operations. For example:

// Push 1: 1

// Push 2: 1 2

// Push 3: 1 2 3

// Push 4: 1 2 3 4

// Push 5: 1 2 3 4 5

// Pop: 1 2 3 4

// inc 2 1: 2 3 3 4




//input
// 7
// 2
// 3
// 2
// 5 6 8 9 4 2 7 


//output
// 4 9 10 8 7





#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct node{
int data;
struct node *next;
}*e;


 e pop(e top){
     top = top->next;
     return top;
}


e newNode(e top){
    e ptr = (e)malloc(sizeof(struct node));
    scanf("%d",&ptr->data);
    ptr->next=NULL;
    if(top==NULL) return ptr;
    ptr->next = top;
    return ptr;
}



e redesignStack(e top,int p,int k,int v,int n){
    for(int i=0;i<p;i++) top = pop(top);
    e ptr = top;
    int cnt = 1;
    for(;;){
        ptr = ptr->next;
        cnt++;
        if(cnt==k) break;
    }
    while(ptr!=NULL){
        ptr->data+=v;
        ptr=ptr->next;
    }
    return top;
    
}

void printStack(e top){
    while(top!=NULL){
        printf("%d ",top->data);
        top = top->next;
    }
}


int main() {

    e top=NULL;
    int n,p,k,v;
    scanf("%d%d%d%d",&n,&p,&k,&v);
    for(int i = 0 ; i < n ; i++){
        top = newNode(top);
    }
    
    top  = redesignStack(top,p,k,v,n);
    printStack(top);
    return 0;
}
