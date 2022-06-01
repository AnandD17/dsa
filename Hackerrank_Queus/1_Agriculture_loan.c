// The National Bank of India announces special schemes for agricultural loans. The schemes include short term loan with a maximum amount of 50000 and long-term loan not exceeding 1,00,000. Farmers from the neighbouring villages visited the bank to avail the loan. Each day the bank can process at most 10 loan applications for both the schemes together. The farmers have to stand in the queue depending on the nature of their loan applied. The applications are processed from each queue starting with short term queue. Find the total loan amount applied for short term and long-term loans separately. Find the total number of applications processed on a day.

// Farmer details: Name, Type of loan, Amount.

//input
// 6
// Ajay short 15000
// Raj short 20000
// Rani long 135000
// Rahul long 75000
// Aditya short 16000
// Deepa long 80000


//output
// Short term Application details
// Ajay short 15000
// Raj short 20000
// Aditya short 16000
// 51000
// Long term Application details
// Rahul long 75000
// Deepa long 80000
// 155000
// 5



#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct queue
{
    char type[10];
    char name[20];
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
    scanf("%s %s %d", newNode->name, newNode->type, &newNode->amt);
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
    int flag = 0, count = 0;
    int s_amt = 0, l_amt = 0;
    if(front==NULL)
    {
        printf("Queue Empty\n");
        return;
    }
    printf("Short term Application details\n");
    while(cur!=NULL)
    {
        if(!(strcmp(cur->type,"short")) && cur->amt<=50000)
        {
            printf("%s %s %d\n", cur->name, cur->type, cur->amt);
            flag = 1;
            count++;
            s_amt += cur->amt;
        }
        cur = cur->next;
    }
    if(!flag)
        printf("Queue Empty\n");
    else
        printf("%d\n", s_amt);
    flag = 0;
    cur = front;
    printf("Long term Application details\n");
    while(cur!=NULL)
    {
        if(!(strcmp(cur->type,"long")) && cur->amt<=100000)
        {
            printf("%s %s %d\n", cur->name, cur->type, cur->amt);
            flag = 1;
            count++;
            l_amt += cur->amt;
        }
        cur = cur->next;
    }
    if(!flag)
        printf("Queue Empty\n");
    else
        printf("%d\n", l_amt);
    printf("%d\n", count);
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