#include<stdio.h>
void check(int a[],int n,int key){
    int flag = 0,i,j;
    for(i = 0 ; i < n ; i++){
        if(a[i]==key)
        {
            flag=1;
            j = i;
        }
    if(flag){
        printf("\nthe key element %d is found in this array at array index of %d",key,j);\
    }
}
}


int main(){
    int n,key;
    scanf("%d",&n);
    int a[n];
    for (int  i = 0; i < n; i++) scanf("%d",&a[i]);
    printf("ENter the key element");
    scanf("%d",&key);
    check(a,n,key);
    return 0;
}