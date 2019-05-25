#include <stdio.h>

int main()
{
	int a[3][4],i,j,t=0,k=0;
	for(i=0;i<3;i++)
	for(j=0;j<4;j++)
	scanf("%d",&a[i][j]);
	for(i=0;i<3;i++)
	for(j=0;j<4;j++)
	if(a[i][j]>a[t][k])
	{
	 t=i;
	 k=j;
	}

	printf("%d\n%d\n%d\n",a[t][k],t,k);
}
