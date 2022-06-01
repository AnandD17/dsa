#include<stdio.h>
int evenCount(int a[],int n){
    int cnt = 0;
    for(int i = 0 ; i < n ; i++) if(a[i]%2==0) cnt++;
    return cnt;
}

int oddCount(int a[],int n){
    int cnt = 0;
    for(int i = 0 ; i < n ; i++) if(a[i]%2!=0) cnt++;
    return cnt;
}

void printOuts(int a[],int n){
    for(int i = 0 ; i < n ; i++) if(a[i]==10) printf("\nThe student number \'%d\' scored 10 out of 10",i+1);
}


int outCount(int a[],int n){
    int cnt = 0;
    for(int i = 0 ; i < n ; i++) if(a[i]==10) cnt++;
    return cnt;
}


int main(){
    int n;
    printf("Enter the Number of students  :");
    scanf("%d",&n);
    printf("\nEnter the marks  :");
    int a[n];
    for(int i = 0; i < n ; i++) scanf("%d",&a[i]);
    printf("\nNumber of students who scored Even marks are  : %d",evenCount(a,n));
    printf("\nNumber of students who scored Odd marks are   : %d",oddCount(a,n));
    printOuts(a,n);
    printf("\nNumber of students who scored 10 out of 10    : %d",outCount(a,n));
    return 0;
}