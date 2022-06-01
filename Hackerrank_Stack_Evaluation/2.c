// Bheem is having two boxes of cookies. He likes to share it with his best friends Chutki and Raju. He gives few cookies from first box to Chutki and few cookies from second box to Raju. As Bheem and Kalia are rivals, he doesn’t like to share cookies with Kalia. Therefore, Kalia decides to exchange the cookies from one box to another without worrying about the order of cookies. Bheem being not aware of this, can you help Kalia in exchanging the cookies?

// Here cookies are integers.

//input
// 5 
// 5
// 1 2 3 4 5
// 9 8 7 6 1
// 2 
// 1

//output
// 9 8 7 6
// 1 2 3


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


void printa(a top){
    if(top->next!=NULL) printa(top->next);
    printf("%d ",top->data);   
    return;
}
void printb(b top){
    if(top->next!=NULL) printb(top->next);
    printf("%d ",top->data);
    return;
}

a popa(a top){
    top = top->next;
    return top;
}

b popb(b top){
    top = top->next;
    return top;
}

void comparePrint(a topa,b topb,int k1,int k2){
    for(int i = 0 ; i < k1 ; i++){ topa = popa(topa); }
    for(int i = 0 ; i < k2 ; i++){ topb = popb(topb); }
    printb(topb);
    printf("\n");
    printa(topa);
    
    
    
}



int main() {

    b topb=NULL;
    a topa=NULL;
    int n1,n2;
    scanf("%d%d",&n1,&n2);
    for(int i = 0 ; i < n1 ; i++){
        topa = newNodea(topa);
    }
    
    for(int i = 0 ; i < n2 ; i++){
        topb = newNodeb(topb);
    }
    
    int k1,k2;
    scanf("%d%d",&k1,&k2);
    
    comparePrint(topa,topb,k1,k2);
    return 0;
}
