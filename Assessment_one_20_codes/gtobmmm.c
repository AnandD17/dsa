#include<stdio.h>
int main(){
    int g[3],b[3],comp[3];
    g[3] = 1;
    g[2] = 1;
    g[1] = 1;
    g[0] = 1;
    b[3] = g[3];
    b[2] = g[3]^g[2];
    b[1] = g[3]^g[2]^g[1];
    b[0] = g[3]^g[2]^g[1]^g[0];
    printf("%d %d %d %d ",b[3],b[2],b[1],b[0]);
    return 0;
}