#include<stdio.h>

void printArray(int a[], int n){
    for(int i = 0 ; i < n ; i++) printf("%d    ",a[i]);
}

void revAndPrint(int a[],int n){
    int rev[n];
    int i = 0, j = n-1;
    while(i!=n){
        rev[j] = a[i];
        i++;
        j--;
    }

    printf("\nThe original array is  ");
    printArray(a,n);

    printf("\nThe reversed array is  ");
    printArray(rev,n);
}
int main(){
    int n;
    printf("Enter the size of the array  : ");
    scanf("%d",&n);
    printf("Enter the elements of that array  :");
    int a[n];
    for(int i = 0 ; i < n ; i++) scanf("%d",&a[i]);
    revAndPrint(a,n);
}