// Test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
#pragma warning(disable:4996)
#include <iostream>
using namespace std;

class Test
{
public:
	Test(int a = 5, int b = 5) :ma(a), mb(b)
	{
		cout <<this<<" "<< "Test(int, int)" << endl;
	}
	~Test()
	{
		cout<<this <<" "<< "~Test()" << endl;
	}
	Test(const Test& src) :ma(src.ma), mb(src.mb)
	{ 
		cout<<this <<" "<< "Test(const Test&)" << endl;
	}
	void operator=(const Test& src)
	{
		ma = src.ma;
		mb = src.mb;
		cout <<&src<<" "<< "operator=" << endl;
	}
private:
	int ma;
	int mb;
};
Test t1(10, 10);//1.构造  27.析构

int main()
{
	Test t2(20, 20);	//3.构造  25.析构
	Test t3 = t2;		//4.拷贝构造（对象初始化对象）24.析构
	static Test t4 = Test(30, 30);	//5.构造（生成临时对象，临时对象定义时进行优化） 26.析构
	t2 = Test(40, 40);		//6.构造 7.运算符重载 8.析构（执行完分号）
	t2 = (Test)(50, 50);//强转，是一个逗号表达式	//9.构造 10.运算符重载 11.析构（执行完分号）
	t2 = 60;				//12.构造 13.运算符重载 14.析构（执行完分号）
	Test* p1 = new Test(70, 70);	//15.构造
	Test* p2 = new Test[2];			 //16.构造 17.构造
	Test* p3 = &Test(80, 80);		//18.构造 19.析构
	Test p4 = Test(90, 90);			//20.构造
	delete p1;						//21.析构
	delete[]p2;						//22.析构 23.析构
}
Test t5(100, 100);//2.构造  //26.析构

/*全局变量t1和t5在程序运行（即main函数之前就已经生成），程序结束时销毁*/
/*从静态存储区分配：此时的内存在程序编译的时候已经分配好，并且在程序的整个运行期间都存在。
					全局变量，static变量等在此存储
在栈区分配：相关代码执行时创建，执行结束时被自动释放。
					局部变量在此存储。栈内存分配运算内置于处理器的指令集中，效率高，但容量有限
在堆区分配：动态分配内存。用new/malloc时开辟，delete/free时释放。生存期由用户指定，灵活。但有内存泄露等问题
*/