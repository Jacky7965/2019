#include <stdio.h>

int main()
{ 
   int i,j,n;
   scanf("%d",&n);
   
   for(i=1;i<=n;i++)
   {
    for(j=1;j<=n-i;j++)
      printf(" ");
    for(j=n-i+1;j<=n+i-1;j++)
      printf("*");
       printf("\n");
   }
   
   for(i=n+1;i<=2*n-1;i++)
    {
     for(j=1;j<=i-n;j++)
	 printf(" ");
	  for(j=i-n+1;j<=3*n-i-1;j++)
	  printf("*");
	  printf("\n");	
	  }  
    
	
}
