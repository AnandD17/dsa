#include<stdio.h>
int Sum1(int a[],int j,int m,int n){
    int sum = 0;
    for(int i = j ; i < j+m && i < n ;i++){
        sum+=a[i];
    }
    return sum;
}

void evaluateAndPrint(int a[],int n,int m){
    for(int i = 0 ; i < n ; i++){
       printf("\nThe sum of next %d digits at index %d is %d",m,i,Sum1(a,i,m,n));

    }
}


int main(){
    int n;
    printf("Enter the size of the array  : ");
    scanf("%d",&n);
    printf("\nEnter the elements of that array :");
    int a[n];
    for(int i = 0 ; i < n ; i++) scanf("%d",&a[i]);
    int m;
    printf("\nEnter the key element  :");
    scanf("%d",&m);
    evaluateAndPrint(a,n,m);
    return 0;
}