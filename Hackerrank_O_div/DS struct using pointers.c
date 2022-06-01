#include <stdio.h>
struct employee
{
    char    name[30];
    int     id;
}emp;
int main()
{

    struct employee *ptr;       //pointer to student structure
    ptr= &emp;                  //assigning value of structure variable
    printf("Enter details of employee :: \n");
    printf("\nEnter Name of employee :: ");
    scanf("%s",ptr->name);
    printf("\nEnter ID of employee :: ");
    scanf("%d",&ptr->id);
    printf("\nEntered details of employees are :: \n");
    printf("\nName : %s \n\id: %d ",ptr->name,ptr->id);
    return 0;
}

