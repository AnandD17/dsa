#include<stdio.h>
float checkAvg(int a[],int n){
    float avg=0;
    for(int i=0;i<n;i++){
        avg+=a[i];
    }
    return avg/n;
}

int checkCnt(int a[],int n,float avg){
    int cnt = 0;
    for(int i = 0;i<n;i++){
        if(a[i]>avg) cnt++;
    }
    return cnt;
}

int main(){
    int n,cnt = 0;
    float avg = 0;
    printf("Enter the number of students  :");
    scanf("%d",&n);
    int a[n];
    printf("\nEnter the marks of every studets  :");
    for(int i = 0 ; i < n ; i++) scanf("%d",&a[i]);
    avg = checkAvg(a,n);
    cnt = checkCnt(a,n,avg);
    printf("The average of the class is : %f\nThe number of students scored above average is : %d",avg,cnt);
    return 0;
}