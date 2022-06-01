#include<stdio.h>
int calculatePenalty(int *m){
    int n=*m;
    if(n>15) n = (n-15)*2;
    else n = 0;
    return n;
}

float checkavg(int a[],int n){
    float avg;
    for(int i = 0 ; i < n ; i++) avg+=a[i];
    return avg / n;
}

int checkMax(int a[],int n){
    int max=0;
    for(int i = 0 ; i < n ; i++){
        if(max<a[i]) max = a[i];
    }
    return max;
}

int checkMin(int a[],int n){
    int min = checkMax(a,n);
    for(int i = 0 ; i < n ; i++){
        if(a[i]==0) continue;
        if(min>a[i]) min = a[i];
    }
    return min;
}

int checkTotal(int a[],int n){
    int t=0;
    for(int i = 0 ; i < n ; i++) t+=a[i];
    return t;
}

int main(){
    int n;
    printf("Enter the number of students  :");
    scanf("%d",&n);
    int a[n];
    printf("\nEnter the marks of every studets  :");
    for(int i = 0 ; i < n ; i++) scanf("%d",&a[i]);
    for(int i = 0; i < n ; i++) a[i]=calculatePenalty((a+i));

    printf("\n average penalty paid by the student is : %f",checkavg(a,n));
    printf("\n maximum penalty paid by the student is : %d",checkMax(a,n));
    printf("\n minimum penalty paid by the student is : %d",checkMin(a,n));
    printf("\n Total penalty paid by the student is : %d",checkTotal(a,n));

}