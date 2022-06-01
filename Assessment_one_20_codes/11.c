#include<stdio.h>
float checkPrice(int *m){
    int x = *m;
    printf("%d",x);
    float price = 0;
    if(x>600) {
        price=5.5*(x-600);
        x = 600;
    }
    if(x<=600 && x>=251){
        price=4.0*(x-250);
        x = 250;
    }

    if(x<=250 && x>=101){
        price=2.3*(x-100);
        x = 250;
    }

    if(x<100&&x>=0) price = 1.5 * (x);

    return price;
}

int main(){
    int n;
    float sum=0;
    printf("Enter the number of flats   :");\
    scanf("%d",&n);
    int a[n];
    for(int i = 0 ; i < n ; i++) scanf("%d",&a[n]);
    for(int i = 0 ; i < n ; i++){
        sum+=checkPrice((a+i));
    }
    printf("The Total charges are  : %f",sum);
}