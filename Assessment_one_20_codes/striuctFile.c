#include<stdio.h>

typedef struct node{
    int id;
    char name[50];
    int marks;
}*e;

void savetofile(e ptr){
    FILE *fptr;
    fptr = fopen("E://student.txt","w+");
    fprintf(fptr,"Id       :%d\nName     :%s\nMarks    :%d\n",ptr->id,ptr->name,ptr->marks);
}

int main(){
    e ptr;
    printf("Enter the id of the student  :");
    scanf("%d",&ptr->id);
    printf("\nEnter the name of the student  :");
    scanf("%s",ptr->name);
    printf("\nEnter the marks of the student  :");
    scanf("%d",&ptr->marks);
    savetofile(ptr);
return 0;
}