#include<stdio.h>
void bubblePrint(int a[], int n){
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
    for(int i = 0 ; i < n ; i++) printf("  %d",a[i]);

}

int main(){
    int n;
    printf("Enter the size of the array  : ");
    scanf("%d",&n);
    printf("Enter the elements of that array  :");
    int a[n];
    for(int i = 0 ; i < n ; i++) scanf("%d",&a[i]);
    printf("\nThe array after bubble sorting is  :  ");
    bubblePrint(a,n);
    return 0;
}

