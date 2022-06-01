#include<stdio.h>


int morethen(long int a[],int n){
    int cnt=0;
    for(int i = 0 ; i < n ; i++) if(a[i]>250000) cnt++;
    return cnt;
}

int between(long int a[],int n){
    int cnt=0;
    for(int i = 0 ; i < n ; i++) if(a[i]>=50000&&a[i]<=150000) cnt++;
    return cnt;
}

float avg(long int a[],int n){
    float avg=0;
    for(int i = 0 ; i < n ; i++) avg+=a[i];
    return avg/n;
}

int main(){
    int n;
    printf("Enter the Number of Tax Payers  :");
    scanf("%d",&n);
    printf("\nEnter the Tax paid  :");
    long int a[n];
    for(int i = 0; i < n ; i++) scanf("%ld",&a[i]);
    printf("\nThe number of tax payers more than 2.5 lackhs were     : %d",morethen(a,n));
    printf("\nThe number of tax payers between 50000 and 150000 were : %d",between(a,n));
    printf("\nThe average tax collected is                           : %f",avg(a,n));
}