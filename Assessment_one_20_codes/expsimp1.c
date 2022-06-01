// 4x3 - 2x2 + 5x3 + 2x - 4x2 - 6x
#include<stdio.h>
#include<math.h>
int main(){
    int x = 5,ans;
    ans = (4 * (pow(x,3))) - (2*(pow(x,2))) + (5*(pow(x,3))) + (2*x) - (4*(pow(x,2))) - (6*x);
    printf("%d",ans);
    return 0;

}