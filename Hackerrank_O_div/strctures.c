#include<stdio.h>
#include<string.h>
struct vector{
    int x;
    int y;
};
int main(){
    struct vector v1,v2;
    v1.x=34;
    v1.y=53;
    printf("X dim is %d and Y dim is %d",v1.x,v1.y);
return 0;
}
