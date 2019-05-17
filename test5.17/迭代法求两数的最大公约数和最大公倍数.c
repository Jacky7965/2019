#include <stdio.h>

int main()
{
 int x,y,a,b,p; 
 scanf("%d %d",&x,&y);

 a=x;b=y;
 do
 {p=a%b;
  a=b;
  b=p;
 }
 while(p!=0);
 
 printf("%d %d\n",x*y/a,a);
 /*
 int main()
{
  int a,b,c,d;
  scanf("%d%d",&a,&b); 
  for(c=a;(a%c)!=0||(b%c)!=0;c--); 
	printf("%d %d\n",c,a*b/c);
    
} */

}
