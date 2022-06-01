// One of the utility bill payments company wants to build a mobile recharge application for end users. The application should support all the network providers available in the market. The flow is, the user sends SMS in predefined format and application should parse the message and do the recharge accordingly.

// Now, the biggest challenge is the application gets a huge number of recharge requests during the peak hours and is not able to process each request, so the company is looking for some strategy where all the requests are parked when they come and processed one by one. Initially all the requests are parked together and then the prepaid and post-paid requests are separated. The company would like to know the total amount of money collected towards prepaid and post-paid mobile recharge. Apply Problem Solving Framework to simulate the above scenario.

//input
// 4
// 9876055421 260 prepaid
// 8796560345 129 postpaid
// 7012345211 599 prepaid
// 8906754312 249 prepaid


// output
// Postpaid Requests
// 8796560345 129 postpaid
// 129
// Prepaid Requests
// 9876055421 260 prepaid
// 7012345211 599 prepaid
// 8906754312 249 prepaid
// 1108


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct queue
{
    char type[10];
    long int num;
    int amt;
    struct queue *next;
} *NODE;

NODE front = NULL;
NODE rear = NULL;

NODE getNode()
{
    NODE newNode;
    newNode=(NODE)malloc(sizeof(struct queue));
    if(newNode==NULL)
    {
        printf("Memory error\n");
        return NULL;
    }
    scanf("%ld %d %s", &newNode->num, &newNode->amt, newNode->type);
    newNode->next=NULL;
    return newNode;
}

void enqueue()
{
    NODE newnode = getNode();
    if(rear==NULL)
    {
        front=rear=newnode;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
}

void displayAll()
{
    NODE cur = front;
    int flag = 0;
    int s_amt = 0, l_amt = 0;
    if(front==NULL)
    {
        printf("Queue Empty\n");
        return;
    }
    printf("Postpaid Requests\n");
    while(cur!=NULL)
    {
        if(!(strcmp(cur->type,"postpaid")))
        {
            printf("%ld %d %s\n", cur->num, cur->amt, cur->type);
            flag = 1;
            s_amt += cur->amt;
        }
        cur = cur->next;
    }
    if(!flag)
        printf("Queue Empty\n");
    printf("%d\n", s_amt);
    flag = 0;
    cur = front;
    printf("Prepaid Requests\n");
    while(cur!=NULL)
    {
        if(!(strcmp(cur->type,"prepaid")))
        {
            printf("%ld %d %s\n", cur->num, cur->amt, cur->type);
            flag = 1;
            l_amt += cur->amt;
        }
        cur = cur->next;
    }
    if(!flag)
        printf("Queue Empty\n");
    printf("%d\n", l_amt);
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        enqueue();
    displayAll();
    return 0;
}