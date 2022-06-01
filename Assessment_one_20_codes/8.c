#include<stdio.h>
int max(int a[]){
    int m=0;
    for(int i = 0 ; i < 12 ;i++) if(a[i]>m) m = a[i];
    return m;
}

int min(int a[]){
    int m=max(a);
    for(int i = 0 ; i < 12 ;i++) if(a[i]<m) m = a[i];
    return m;
}

float avg(long int a[]){
    float avg=0;
    for(int i = 0 ; i < 12 ; i++) avg+=a[i];
    return avg/12;
}

int main(){
    printf("\nEnter the expenditure of every month  :");
    int a[12];
    for(int i = 0; i < 12 ; i++) scanf("%d",&a[i]);
    printf("\nThe month they spent more is  :%d",max(a));
    printf("\nThe month they spent less is  :%d",min(a));
    printf("\nThe average of expenditure is :%d",max(a));
    return 0;
}

