#include <stdio.h> 

int main()
{
	int i,j,a;
	int t=a,s=t;
	scanf("%d %d",&a,&j);
	
	for(i=2;i<=j;i++)
	{
		t=t*10+a;
		s+=t;
	}
	
	printf("%d",s);
}
