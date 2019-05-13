#include <iostream>					// Ԥ��������
using namespace std;					// ʹ�ñ�׼�����ռ�std
#include <cstring>

//ѧ��(Student)��
class Student
{
     private:
	         char* name;					// ����
	         int num;						// ѧ��
	         int mathScore;					// ��ѧ�ɼ�
             int englishScore;				// Ӣ��ɼ�
             static int count;                     // ����
	         static int mathTotalScore;             //��ѧ�ܳɼ�
	         static int englishTotalScore;          //Ӣ���ܳɼ�
	         
     public:
            Student(char* nm, int nu, int math,int english);		// ���캯��
	        void ShowBase() const;		// ��ʾ�������ݺ���
	        void ShowStatic() const;		// ��ʾ��̬���ݺ���
};

int Student::englishTotalScore=0;
int Student::mathTotalScore=0;
int Student::count = 0;				// ��ʼ����̬���ݳ�Աcount

//ѧ��(Student)���ʵ�ֲ���
Student::Student(char *nm, int nu, int math,int english)
{
	strcpy(name,nm);
	num=nu;
	mathScore=math;
	englishScore=english;
	mathTotalScore+=math;
	englishTotalScore+=english;
    count++; 
}						// ����֪��Ϣ�������, ����num���Լ�1

void Student::ShowBase() const  // ��ʾ�������ݺ���
{
	  cout <<"����:" <<name <<endl;         // ��ʾ���� 
	  cout << "ѧ��:" <<num << endl;		// ��ʾѧ��
	  cout << "��ѧ�ɼ�:" << mathScore <<endl;	// ��ʾ��ѧ�ɼ�
	  cout << "Ӣ��ɼ�:" << englishScore << endl;// ��ʾӢ��ɼ�
	  cout << endl;							// ����
}

void Student::ShowStatic() const  // ��ʾ��̬���ݺ���
{
	  cout << "������:" <<count << endl;		// ��ʾ����
	  cout << "��ѧ�ܳɼ�:" << mathTotalScore <<endl;	// ��ʾ��ѧ�ܳɼ�
	  cout << "Ӣ���ܳɼ�:" << englishTotalScore << endl;// ��ʾӢ���ܳɼ�
	  cout << endl;							// ����
}

int main()							
{
	Student s1("���",1,90,80);
	Student s2("����",2,99,88);
    
    s1.ShowBase();
    s2.ShowBase();
    s1.ShowStatic();
	
    return 0;                   		// ����ֵ0,���ز���ϵͳ
} 
