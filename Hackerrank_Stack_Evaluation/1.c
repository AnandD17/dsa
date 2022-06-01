// You are given a stack of N integers. You need to replace first element by last element and vice versa and continue the same for rest of the elements of stack. One thing you need to follow is, you should reverse the integer and then replace it. And also pop the integers after replacing.

//input
// 5
// 123 45 89 74 69
// 2


//ouput
// 98 47 96


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct node{
int data;
struct node *next;
}*e;

typedef struct node1{
int data;
struct node1 *next;
}*p;


e newNode(e top){
    e ptr = (e)malloc(sizeof(struct node));
    scanf("%d",&ptr->data);
    ptr->next=NULL;
    if(top==NULL) return ptr;
    ptr->next = top;
    return ptr;
}

p reverseStack(e top){
    e cur=top;
    p top2=NULL;
    while(cur!=NULL){
        p ptr2 = (p)malloc(sizeof(struct node1));
        ptr2->data = cur->data;
        ptr2->next = NULL;
        if(top2==NULL) top2 = ptr2;
        else{
            ptr2->next = top2;
            top2 = ptr2;
        }
        cur = cur->next;
    }
    return top2;
}

int reverseNumber(int n){
    int  reverse = 0, remainder;
    
    while (n != 0) {
    remainder = n % 10;
    reverse = reverse * 10 + remainder;
    n /= 10;
  }
    return reverse;
}

void printStack(p top){
    while(top!=NULL){
        printf("%d ",reverseNumber(top->data));
        top=top->next;
    }
}

p pop(p top){
    top = top->next;
    return top;
}

int main() {

    e top=NULL;
    int n;
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++){
        top = newNode(top);
    }
    
    p top3 = reverseStack(top);
    
    int k;
    scanf("%d",&k);
    for(int i = 0 ; i < k ; i++){
        top3 = pop(top3);
    }
    
    printStack(top3);
    return 0;
}
