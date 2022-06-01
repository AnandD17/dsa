// Lucky draw bot randomly picks the winners. It posts an announcement message listing all the winners in the channel immediately after the activity is closed. Everyone in the channel can see all the people joined the draw. Tryle team is conducting lucky draw contest, N number of users registered to the contest and all users will be provided with unique user id. Tryle team makes use of Stack to store all the N user id’s. It’s very difficult for the team to select the lucky winners among N users. So the team come-up with a solution to select the lucky winners.

// Solution :

// Every time the Team pick the Top most user id, if it is completely divisible by the Magic Number K then that user is announced as a Winner and output will be W, if not output will be L. Team removes the user id that was picked from the stack. This process repeates until all the user id's are exhausted.


//input
// 6 4
// 10 8 1 16 5 45

//output
// L L W L W L 
// 2
// 4



#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct node{
int data;
struct node *next;
}*e;



e newNode(e top){
    e ptr = (e)malloc(sizeof(struct node));
    scanf("%d",&ptr->data);
    ptr->next=NULL;
    if(top==NULL) return ptr;
    ptr->next = top;
    return ptr;
}



void printStack(e top,int k){
    int w=0,l=0;
    while(top!=NULL){
        if(top->data%k==0) {printf("W "); w++;}
        else {printf("L "); l++;}
        top=top->next;
    }
            printf("\n%d\n%d",w,l);
}


int main() {

    e top=NULL;
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i = 0 ; i < n ; i++){
        top = newNode(top);
    }
    
    
    printStack(top,k);
    return 0;
}
