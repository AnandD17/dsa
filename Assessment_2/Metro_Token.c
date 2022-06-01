#include<string.h>

typedef struct metro
{
    int token_no;
    char from[25], to[25];
    float amt;
}M;

void read(M *m1, int n)
{
    for(int i=0; i<n; i++)
    {
        (m1+i)->token_no = i+1;
        printf("Enter the details of the passenger %d :\n", i+1);
        printf("From : ");
        scanf(" %s", (m1+i)->from);
        printf("To : ");
        scanf(" %s", (m1+i)->to);
        printf("Price : ");
        scanf("%f", &(m1+i)->amt);
    }
}

void display(M *m1, int n)
{
    for(int i=0; i<n; i++)
    {
        printf("\nThe details of the passenger %d :\n", i+1);
        printf("Token Number : %d\nFrom : %s\nTo : %s\nPrice : %.2f\n", (m1+i)->token_no,(m1+i)->from, (m1+i)->to, (m1+i)->amt);
    }
}

void display_start(M m1[50], int n)
{
    char start[25];
    printf("\nEnter the starting point : ");
    scanf(" %s", start);
    for(int i=0; i<n; i++)
    {
        if(!(strcmp(start,m1[i].from)))
        {
           printf("Token Number : %d\nFrom : %s\nTo : %s\nPrice : %.2f\n", m1[i].token_no, m1[i].from, m1[i].to, m1[i].amt);
        }
    }
}

void display_end(M *m1, int n)
{
    char end[25];
    printf("\nEnter the ending point : ");
    scanf(" %s", end);
    for(int i=0; i<n; i++)
    {
        if(!(strcmp(end,m1[i].to)))
        {
           printf("Token Number : %d\nFrom : %s\nTo : %s\nPrice : %.2f\n", m1[i].token_no, m1[i].from, m1[i].to, m1[i].amt);
        }
    }
}

void main()
{
    int n;
    printf("Enter the number of tokens - ");
    scanf("%d", &n);
    M *m1 = (M*)malloc(n*sizeof(M));
    read(m1,n);
    display(m1,n);
    display_start(m1,n);
    display_end(m1,n);
    free(m1);
}