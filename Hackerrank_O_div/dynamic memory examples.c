/*#include <stdio.h>
#include <stdlib.h>
struct person
{
   int age;
   float weight;
   char name[30];
};

int main()
{
   struct person *ptr;
   int i, n;

   printf("Enter the number of persons: ");
   scanf("%d", &n);

   // allocating memory for n numbers of struct person
   ptr = (struct person*) malloc(n * sizeof(struct person));

   for(i = 0; i < n; ++i)
   {
       printf("Enter first name and age respectively: ");

       // To access members of 1st struct person,
       // ptr->name and ptr->age is used

       // To access members of 2nd struct person,
       // (ptr+1)->name and (ptr+1)->age is used
       scanf("%s %d", (ptr+i)->name, &(ptr+i)->age);
   }

   printf("Displaying Information:\n");
   for(i = 0; i < n; ++i)
       printf("Name: %s\tAge: %d\n", (ptr+i)->name, (ptr+i)->age);

   return 0;
}*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
     int id; char name[20],city[20];
     };
     void read(struct student *p,int n)
     { int i; for(i=0;i<n;i++)
     { printf(" enter name,id and city\n");
     scanf("%s\t%d\t%s",p->name,&p->id,p->city); } }
      void display(struct student *p,int n)
      { int i; printf("information of the employee are\n");
       for(i=0;i<n;i++)
        {
             printf("name %s\n",p->name);
       printf("id %d\n",p->id);
        printf("city %s\n",p->city); } }
       int main()
        { struct student *p,a;
         p=&a; int n;
         printf("enter no of employees\n");
       scanf("%d",&n);

       p=(struct student*)malloc(n*sizeof(struct student));
       read(p,n);
        display(p,n);
        free(p);
         return 0;
        }


