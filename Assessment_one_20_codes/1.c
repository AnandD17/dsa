#include<stdio.h>

int freqPos(int a[],int n){
    int cnt= 0;
    for(int i = 0 ; i < n ; i++) if(a[i]>=0) cnt++;
    return cnt;
}


int freqNeg(int a[],int n){
    int cnt= 0;
    for(int i = 0 ; i < n ; i++) if(a[i]<0) cnt++;
    return cnt;
}

int main(){
    int n;
    printf("Enter the size of the array  : ");
    scanf("%d",&n);
    printf("Enter the elements of that array  :");
    int a[n];
    for(int i = 0 ; i < n ; i++) scanf("%d",&a[i]);
    printf("\nThe positive integer frequency is  : %d",freqPos(a,n));
    printf("\nThe negative integer frequency is  : %d",freqNeg(a,n));
}