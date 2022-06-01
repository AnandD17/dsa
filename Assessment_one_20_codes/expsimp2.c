// 4x3 - 2x2 + 5x3 + 2x - 4x2 - 6x
#include<stdio.h>
#include<math.h>
int main(){
    int x = 5;
    int cube = pow(x,3);
    int square = pow(x,2);
    x = (9*cube) - (6*square) - (4*x);
    printf("%d",x);
    return 0;
}