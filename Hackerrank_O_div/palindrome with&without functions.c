#include<stdio.h>
#include<string.h>
int main()
{
char s[1000];
int i,n,c=0;
printf("enter the string:");
gets(s);
n=strlen(s);
for(i=0;i<0.5*n;i++)
{
  if(s[i]==s[n-i-1])
    c++;
}

if(c==i)
   {
       printf("palindrome\n");
   }
else
 {
    printf("not palindrome\n");
 }

  return 0;
}






/*#include<stdio.h>
int main()
{
    int n,r,sum=0,temp;
    printf("enter the no.");
    scanf("%d",&n);
    temp=n;

    while(n>0)
    {
        r=n%10;
        sum=(sum*10)+r;
        n=n/10;
    }
    if(temp==sum)
        printf("palindrome");
    else
        printf("not palindrome");
    return 0;
}*/4
