#include<stdio.h>
void printRankings(int a[],int n){
    int temp;
    for(int i = 0 ; i < n ; i++){
        for(int j = i ; j < n ; j++){
            if(a[i]>a[j]){
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            } 
                
        }
    }
    for(int i = 0 ; i < n ; i++) printf("\n  %d",a[i]);

    printf("\n The maximum ranking of the student is : %d",a[n-1]);
    printf("\n The minimum ranking of the student is : %d",a[0]);
}
int main(){
    int n;
    printf("Enter the Number of students  :");
    scanf("%d",&n);
    printf("\nEnter the rankings  :");
    int a[n];
    for(int i = 0; i < n ; i++) scanf("%d",&a[i]);
    printRankings(a,n);
    return 0;
}