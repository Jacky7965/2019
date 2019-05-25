#include <stdio.h>

void func(int n)
{
 int v;
 if(n==0) return;//到0结束。
  v=n%10;//取出个位。
  func(n/10);//递归调用
  printf("%d ",v);//输出。
}
int main()
{
 int n;
 scanf("%d",&n);//输入。
 func(n);//调用函数，正序输出各个位。
 return 0;
}
