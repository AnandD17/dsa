#include<stdio.h>
int isPerfect(int x){
    int j,sum = 0;
    j = x-1;
    while(j>0){
        if(x%j==0) sum+=j;
        j--;
    }
    if(sum==x)return 1;
    else return 0;
}

void checkAndPrint(int a[],int n){
    int num;
    for(int i = 0 ; i < n ; i++){
        num = a[i];
        if(isPerfect(num)) printf("\nthe number %d in the array index %d is a perfect number",a[i],i);
    }
}

int main(){
    int n;
    printf("Enter the elements in the array  : ");
    scanf("%d",&n);
    int a[n];
    printf("\nEnter the elements of that array :");
    for(int i = 0 ; i < n ; i++) scanf("%d",&a[i]);
    checkAndPrint(a,n);
    return 0;
}