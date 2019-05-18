#pragma once
#pragma warning(disable: 4996)

#include <iostream>
#include <cstring>
using namespace std;

class String
{
public:
	String(const char* ptr);
	~String();
	String(const String& rhs);
	String& operator=(const String& rhs);
	void Show();

private:
	char* mptr;
};

