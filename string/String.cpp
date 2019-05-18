#include "String.h"

String::String(const char* ptr)
{
	//cout << "String(const char* str)" << endl;
	mptr = new char[strlen(ptr)+1]();
	strcpy(mptr, ptr);
}


String::~String()
{
	//cout << "~String()" << endl;
	delete[] mptr;
	mptr = NULL;
}

String::String(const String& rhs)
{
	//cout << "String(const string& rhs)" << endl;
	mptr = new char[strlen(rhs.mptr) + 1]();
	strcpy(mptr, rhs.mptr);
}

String& String::operator=(const String& rhs)
{
	//cout << "operator=(const string& rhs)" << endl;
	if (this != &rhs)
	{
		delete[] mptr;//���ͷţ��ٿ��٣���ֹ�ռ䲻��
		mptr = new char[strlen(rhs.mptr) + 1]();
		strcpy(mptr, rhs.mptr);
	}
	return *this;
}

void String::Show()
{
	cout << mptr << endl;
}

int main()
{
	String str1("hello");
	String str2("world");
	str1.Show();
	str2.Show();
	String str3 = str2;
	String str4(str1);

	return 0;
}
