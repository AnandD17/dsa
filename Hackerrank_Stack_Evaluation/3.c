// Ptolem and Neil making experiments about the asteroids collision. Each asteroid will be having Size with a sign representing its direction (positive meaning right, negative meaning left). Both of them are provided with the stack of N aseroids. Ptolem and Neil pick asteroids Size from their stacks.

// Conditions about collision:

// a. If both asteroids Size are Positive or Negative then they will move in same direction (non-collision), then output is 0. Both the asteroids Size are removed from their stack.

// b. If both asteroids Size have different signs then they will collide and output will be 1. Both the asteroids Size are removed from their stack.

// c. If the asteriods Size is 0, it is neither positive nor negative. Hence only 0 will be removed from their stack. NOTE: Size – an integer indicating the Size of asteroid with Positive or Negative signs.

// The experiment ends when either Ptolem or Neil or both stack is empty.


//input
// 5 
// 3 -5 6 7 -2
// -1 -5 9 0 -4


//output
// 0 0 1 0
// 1
// 3




#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct nodeb{
int data;
struct nodeb *next;
}*b;

typedef struct nodea{
int data;
struct nodea *next;
}*a;


b newNodeb(b top){
    b ptr = (b)malloc(sizeof(struct nodeb));
    scanf("%d",&ptr->data);
    ptr->next=NULL;
    if(top==NULL) return ptr;
    ptr->next = top;
    return ptr;
}

a newNodea(a top){
    a ptr = (a)malloc(sizeof(struct nodea));
    scanf("%d",&ptr->data);
    ptr->next=NULL;
    if(top==NULL) return ptr;
    ptr->next = top;
    return ptr;
}

a popa(a top){
    top = top->next;
    return top;
}

b popb(b top){
    top = top->next;
    return top;
}

void comparePrint(a topa,b topb){
    int col = 0,nonCol = 0;
    while(topa!=NULL&&topb!=NULL){
        if((topa->data<0&&topb->data<0)||(topa->data>0&&topb->data>0)){
            printf("0 ");
            nonCol++;
            topb = popb(topb);
            topa = popa(topa);
        }
        else if((topa->data<0&&topb->data>0)||(topa->data>0&&topb->data<0)){
            printf("1 ");
            col++;
            topb = popb(topb);
            topa = popa(topa);
        }
        else{
            if(topa->data == 0) topa=popa(topa);
            if(topb->data == 0) topb=popb(topb);
        }
        
            
    }
    
    printf("\n%d\n%d",col,nonCol);
}

int main() {

    b topb=NULL;
    a topa=NULL;
    int n;
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++){
        topa = newNodea(topa);
    }
    
    for(int i = 0 ; i < n ; i++){
        topb = newNodeb(topb);
    }
    
    comparePrint(topa,topb);
    return 0;
}
