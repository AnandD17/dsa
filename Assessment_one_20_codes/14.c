#include<stdio.h>
int checkRight(int a[],int p, int n){
    int sum = 0;
    for(int i = p+1; i < n ; i++){
        sum+=a[i];
    }
    return sum;
}

int checkLeft(int a[],int n){
    int sum = 0;
    for(int i = 0 ; i < n ; i++){
        sum+=a[i];
    }
    return sum;
}

int checkEqual(int a[],int n){
    for(int i = 1 ; i < n-1 ; i++){
        if(checkLeft(a,i)==checkRight(a,i,n)) return i;
    }
    return -1;
}

int main(){
    int n;
    printf("Enter the size of the array  : ");
    scanf("%d",&n);
    printf("Enter the elements of that array  :");
    int a[n];
    for(int i = 0 ; i < n ; i++) scanf("%d",&a[i]);
    if(checkEqual(a,n)!=-1) printf("The given array is equilibrium at index %d : ", checkEqual(a,n));
    else printf("The given array is not equilibrium");

}