#include<stdio.h>

void main()
{
 int a,b;
 printf("����һ����b:");
 scanf("%d",&b);
 a=2;
 
 while(a<b)
  {
  if(b%a==0)
  break;
  a++;
  }
 if(a==b)
   printf("%d is prime\b",b);
 else
   printf("%d is no prime\b",b);
}
