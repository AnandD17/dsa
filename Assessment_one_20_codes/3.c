#include<stdio.h>
int calculate(int n){
    if(n>=5&&n<=7){
        n = 10600 + (10600/10);
        return n;
    }
    if(n>=8&&n<=10){
        n = 10600 + (10600/20);
        return n;
    }
    if(n>10){
        n = 10600 + (10600/30);
        return n;
    }
}


int main(){
    int n;
    printf("Enter the experience of the employee   :");
    scanf("%d",&n);
    if(n<5)
    {
        printf("Invalid information");
        return 0;
    }
    n = calculate(n);
    printf("The salary of the employee is  %d",n);
    return 0;
}