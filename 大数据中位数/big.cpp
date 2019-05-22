#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SIZE 25*1024*1024*1024

void CreateBigFile(const char *path)
{
	FILE *fw=fopen(path,"wb");
	assert(fw!=NULL);
	int tmp;
	long long i;

	for(i=0;i<SIZE;i++)
	{
		tmp=rand();
		fwrite(&tmp,sizeof(int),1,fw);
	}
	fclose(fw);
}

int Dvide(char *path)
{
	char str[100][10];
	int i;
	for(i=0;i<100;i++)
	{

		sprintf(str[i],"%d.txt",i);
		FILE *fw=fopen(str[i],"wb");
	}
	char arr[100];
	for(i=0;i<100;i++)
	{
		fclose(arr[i]);
	}
	return 0;
	
}

int main()
{
	char *path="big.txt";
   
}