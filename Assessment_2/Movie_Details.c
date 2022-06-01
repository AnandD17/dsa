#include<string.h>

typedef struct movie
{
    char name[25], producer[25], director[25], production_house[25];
    int year;
}M;

void read(M *m, int n)
{
    for(int i=0; i<n; i++)
    {
        printf("\nEnter the details of movie %d :\n", i+1);
        printf("Movie Name : ");
        scanf(" %s",(m+i)->name);
        printf("Producer : ");
        scanf(" %s",(m+i)->producer);
        printf("Director : ");
        scanf(" %s",(m+i)->director);
        printf("Release Year : ");
        scanf("%d", &(m+i)->year);
        printf("Production House : ");
        scanf(" %s",(m+i)->production_house);
    }
}

void sort(M *m, int n)
{
    M temp;
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-1-i; j++)
        {
            if((m+i)->year>(m+j)->year)
            {
               temp = *(m+j);
               *(m+j) = *(m+j+i);
               *(m+j+1) = temp;
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        printf("\nMovie %d\n", i+1);
        printf("Movie Name : %s\nProducer : %s\nDirector : %s\nRelease Year : %d\nProduction House : %s\n", (m+i)->name, (m+i)->producer, (m+i)->director, (m+i)->year, (m+i)->production_house);
    }
}

void director(M *m, int n)
{
    char d[15];
    printf("\nEnter the Director's name : ");
    scanf(" %s", d);
    for(int i=0; i<n; i++)
    {
        if(!(strcmp(d,(m+i)->director)))
        {
            printf("Movie Name : %s\nProducer : %s\nDirector : %s\nRelease Year : %d\nProduction House : %s\n", (m+i)->name, (m+i)->producer, (m+i)->director, (m+i)->year, (m+i)->production_house);
        }
    }
}

void p_house(M *m, int n)
{
    char p[15];
    printf("\nEnter the Production House : ");
    scanf(" %s", p);
    for(int i=0; i<n; i++)
    {
        if(!(strcmp(p,(m+i)->production_house)))
        {
            printf("Movie Name : %s\nProducer : %s\nDirector : %s\nRelease Year : %d\nProduction House : %s\n", (m+i)->name, (m+i)->producer, (m+i)->director, (m+i)->year, (m+i)->production_house);
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of movies - ");
    scanf("%d", &n);
    M *m = (M*)malloc(n*sizeof(M));
    read(m,n);
    sort(m,n);
    director(m,n);
    p_house(m,n);
    return 0;
}