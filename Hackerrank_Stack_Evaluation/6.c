//Arjun and Bheem are playing a game. In this game both of them are provided with the stack of n numbers. Strategy to play the game is: Arjun and Bheem pick an element from their stacks.

// Method to be followed to play the game is:

// a. If the number picked by Arjun is bigger than Bheem then this step's output is 1. Bheem removes the number that was picked from his stack.

// b. If the number picked by Arjun is smaller than Bheem then this step's output is 2. Arjun removes the number that was picked from his stack.

// c. If both have the same number then this step's output is 0. Both Arjun and Bheem remove the number that was picked from their stack. The game ends when at least one of them has no more elements to be picked.

// The game ends when at least one of them has no more elements to be picked.



//input
// 5
// 6 8 4 3 1
// 5 7 9 2 4

//output
// 2 2 0 1 2 2



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


void comparePrint(a topa,b topb){
    while(topa!=NULL&&topb!=NULL){
        if(topa->data>topb->data){
            printf("1 ");
            topb = topb->next;
        }
        else if(topa->data<topb->data){
            printf("2 ");
            topa = topa->next;
        }
        else{
            printf("0 ");
            topa = topa->next;
            topb = topb->next;
        }
        
            
    }
}

a popa(a top){
    top = top->next;
    return top;
}

b popb(b top){
    top = top->next;
    return top;
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
