#include<stdio.h>
int isPrime(int x){
    if(x==0||x==1) return 0;
    for(int i = 2 ; i < x ; i++){
        if(i==x) continue;
        if(x%i==0) return 0;
    }
    return 1;
}


int main(){
    int n;
    printf("Enter the number : ");
    scanf("%d",&n);
    printf("\n");
    for(int i = 0 ; i < n ; i++){
        if(isPrime(i)) printf("%d   ",i);
    }
    return 0;
}