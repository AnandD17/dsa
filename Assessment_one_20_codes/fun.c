
//a boy goes to hotel to buy donut and coffee at day 1 he takes 2 coffee and 1 donut and pays Rs 15 to hotel
// 2x + y = 15  ->(1)

//same boy goes to hotel to buy same product at day 2 he takes 1 coffee and 3 donut and pays Rs 15 to hotel
// x + 3y = 30  ->(2)

//this guy is excited to calculate the price of the coffee and donut let us help him





//soln
//let x be price of a coffee
//let y be price of a donut

//representing it in matrix
//   2   1  x  =   15
//   1   3  y  =   30

//a = 2  1
//    1  3


// b  =  15
//       30


#include<stdio.h>
int main(){
    int a[4],b[2],x,y;
    a[3] = 3;
    a[2] = 1;
    a[1] = 1;
    a[0] = 2;

    b[1] = 30;
    b[0] = 15;

    x = a[1];
    a[1] = a[2];  //calculating a transpose
    a[2] = x;

    //calculating a inverse
    x = (a[0]*a[3])-(a[1]*a[2]);

    a[0] = a[0]/x;
    a[1] = a[1]/x;
    a[2] = a[2]/x;
    a[3] = a[3]/x;

    x = (a[0]*b[0])+(a[1]*b[1]);
    x = (a[2]*b[0])+(a[3]*b[1]);
    printf("%d %d",x,y);
    return 0;
    


}