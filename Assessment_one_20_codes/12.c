#include<stdio.h>
void printArray(int a[],int n){
    printf("\n the elements in the array are :\n");
    for(int i=0;i<n;i++){
        printf("%d   ",a[i]);
    }
}

void maxAndPrintArray(int a[],int n){
    printf("\n");
    int temp,max,sum = 0;
    for(int i=0;i<n;i++){
        max = 0;
        while(a[i]!=0)
        {
            temp = a[i]%10;
            if(temp>max) max = temp;
            a[i]/=10;
        }
        printf("\nThe maximum element in the array index %d is %d",i,max);
        sum+=max;
    }
    printf("\nThe sum of all the maximum elements in the array is %d",sum);
}

int main(){
    int n;
    printf("Enter the number of the elements in the array   : ");
    scanf("%d",&n);
    int a[n];
    printf("\nEnter the elements in the array  : ");
    for(int i = 0 ; i < n ; i++) scanf("%d",&a[i]);
    printArray(a,n);
    maxAndPrintArray(a,n);
}