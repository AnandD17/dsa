#include<stdio.h>
void printArray(int a[], int n){
    for(int i = 0 ; i < n ; i++) printf("%d    ",a[i]);
}

void swap(int a[],int b[],int n){
    int temp[n];
    for(int i = 0 ; i < n ; i++){
        temp[i] = a[i];
        a[i] = b[i];
        b[i] = temp[i];
    }
}

int main(){
    int n;
    printf("Enter the size of the array  : ");
    scanf("%d",&n);
    printf("\nEnter the elements of that array number 1 :");
    int a[n];
    for(int i = 0 ; i < n ; i++) scanf("%d",&a[i]);

    printf("\nEnter the elements of that array number 2 :");
    int b[n];
    for(int i = 0 ; i < n ; i++) scanf("%d",&b[i]);
    printf("\nthe Arrays before swapping are ");
    printf("\nthe Array a is :");
    printArray(a,n);

    printf("\nthe Array b is :");
    printArray(b,n);

    swap(a,b,n);

    printf("\nthe Arrays after swapping are ");
    printf("\nthe Array a is :");
    printArray(a,n);

    printf("\nthe Array b is :");
    printArray(b,n);

    

}