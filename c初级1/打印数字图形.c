#include<stdio.h>

int main()
{
 int i,j,n,p,q;
 scanf("%d",&n);
 
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n-i;j++)
   printf(" ");
   for(p=1;p<=i;p++)
    printf("%d",p);
     for(q=i-1;q>0;q--)
      printf("%d",q);
        printf("\n");
 }
 
 for(i=1;i<=n-1;i++)
{
 for(j=1;j<=i;j++)
  printf(" ");
  for(p=1;p<=n-i;p++)
   printf("%d",p);
    for(q=n-i-1;q>0;q--)
     printf("%d",q);
      printf("\n");
 }
 
  return 0;
}
