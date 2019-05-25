#include <stdio.h>

int main()
{
	int a,b,max;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		if(a>b) max=a;
		else max=b;
		printf("%d\n",max);
	}
}
