#include <stdio.h>

void func(int n)
{
 int v;
 if(n==0) return;//��0������
  v=n%10;//ȡ����λ��
  func(n/10);//�ݹ����
  printf("%d ",v);//�����
}
int main()
{
 int n;
 scanf("%d",&n);//���롣
 func(n);//���ú����������������λ��
 return 0;
}
