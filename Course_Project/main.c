#include<stdio.h>
#include "load.c"
#include "setup.c"


//Main Function
int main(){

load();    //initial load
printf("\033[0m");   
setup();  //login or signup


return 0;
}