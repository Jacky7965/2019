#include <iostream>					// 预处理命令
using namespace std;					// 使用标准命名空间std
#include <cstring>

//学生(Student)类
class Student
{
     private:
	         char* name;					// 姓名
	         int num;						// 学号
	         int mathScore;					// 数学成绩
             int englishScore;				// 英语成绩
             static int count;                     // 人数
	         static int mathTotalScore;             //数学总成绩
	         static int englishTotalScore;          //英语总成绩
	         
     public:
            Student(char* nm, int nu, int math,int english);		// 构造函数
	        void ShowBase() const;		// 显示基本数据函数
	        void ShowStatic() const;		// 显示静态数据函数
};

int Student::englishTotalScore=0;
int Student::mathTotalScore=0;
int Student::count = 0;				// 初始化静态数据成员count

//学生(Student)类的实现部分
Student::Student(char *nm, int nu, int math,int english)
{
	strcpy(name,nm);
	num=nu;
	mathScore=math;
	englishScore=english;
	mathTotalScore+=math;
	englishTotalScore+=english;
    count++; 
}						// 由已知信息构造对象, 人数num将自加1

void Student::ShowBase() const  // 显示基本数据函数
{
	  cout <<"姓名:" <<name <<endl;         // 显示姓名 
	  cout << "学号:" <<num << endl;		// 显示学号
	  cout << "数学成绩:" << mathScore <<endl;	// 显示数学成绩
	  cout << "英语成绩:" << englishScore << endl;// 显示英语成绩
	  cout << endl;							// 换行
}

void Student::ShowStatic() const  // 显示静态数据函数
{
	  cout << "总人数:" <<count << endl;		// 显示人数
	  cout << "数学总成绩:" << mathTotalScore <<endl;	// 显示数学总成绩
	  cout << "英语总成绩:" << englishTotalScore << endl;// 显示英语总成绩
	  cout << endl;							// 换行
}

int main()							
{
	Student s1("王皓",1,90,80);
	Student s2("黎明",2,99,88);
    
    s1.ShowBase();
    s2.ShowBase();
    s1.ShowStatic();
	
    return 0;                   		// 返回值0,返回操作系统
} 
