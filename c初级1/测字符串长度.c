#include <stdio.h> 
#include <string.h> 
int main()
{
	char a[256];
	gets(a);
	int i;
	i=strlen(a);
	printf("%d",i);
	return 0;
}
