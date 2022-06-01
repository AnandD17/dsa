// On the release date of the movie Venom 2, there is a huge line at the ticket counter at INOX and price of each ticket is 300Rs. To manage the huge number of ticket buyers, the INOX staff named Vikram requests the people to form new line formed in such a way that maximum K number of people who have age between 18 to 25, are allowed. Display the content of new line. One of the person standing in new line wants to know his/her position and requests INOX staff to tell his/her position. After approving the request of the person, INOX staff displays the current position. Help INOX staff to display total amount collected in both lines. The people in line are recognized by Name and Age.


//input
// 6 3
// Manoj 20
// Ajay 16      
// Vishal 35      
// Karan 21      
// Laxman 40      
// Pavan 18      
// Karan


//output
// Manoj 20 
// Karan 21 
// Pavan 18 
// 2
// 900
// 900



#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

typedef struct queue
{
    char name[20];
    int age;
    struct queue *next;
} *NODE, *NODE1;

NODE front = NULL;
NODE rear = NULL;

NODE1 f = NULL;
NODE1 r = NULL;

NODE getNode()
{
    NODE newNode;
    newNode=(NODE)malloc(sizeof(struct queue));
    if(newNode==NULL)
    {
        printf("Memory error\n");
        return NULL;
    }
    scanf("%s %d", newNode->name, &newNode->age);
    newNode->next=NULL;
    return newNode;
}

NODE1 getNode1(NODE cur)
{
    NODE1 n = (NODE1)malloc(sizeof(struct queue));
    if(n==NULL)
        return NULL;
    strcpy(n->name,cur->name);
    n->age = cur->age;
    n->next = NULL;
    return n;
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

void enqueue1(NODE1 newnode)
{
    if(r==NULL)
    {
        f=r=newnode;
    }
    else
    {
        r->next=newnode;
        r=newnode;
    }
}

void display(int N, int k, char key[20])
{
    if(front==NULL)
    {
        printf("Queue empty\n");
        return;
    }
    int n = 0, sum1, sum2;
    NODE cur = front;
    NODE1 temp = NULL;
    while(cur!=NULL)
    {
        if(cur->age>=18 && cur->age<=25 && n<=k)
        {
            temp = getNode1(cur);
            enqueue1(temp);
            n++;
        }
        cur = cur->next;
    }
    sum1 = n*300;
    sum2 = (N-n)*300;
    temp = f;
    int i = 1;
    n=0;
    while(temp!=NULL)
    {
        printf("%s %d\n", temp->name, temp->age);
        if(!(strcmp(temp->name,key)))
            n = i;
        i++;
        temp = temp->next;
    }
    printf("%d\n", n);
    printf("%d\n", sum2);
    printf("%d\n", sum1);
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, k;
    char key[20];
    scanf("%d %d", &n, &k);
    if(n==0)
    {
        printf("N should be greater than 0");
        return 0;
    }
    for(int i=0; i<n; i++)
        enqueue();
    scanf("%s", key);
    display(n,k,key);
    return 0;
}