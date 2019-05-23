#pragma once
#include<iostream>
using namespace std;

class Date 
{
public:
	Date(int year = 1, int month = 1, int day = 1)
		: year(year)
		, month(month)
		, day(day)
	{
		if (!((year > 0)&& (month > 0 && month < 13)&& (day > 0 
			&& day < Month2_Day(year, month)))) 
		{
			cout << "输入的日期不合法！" << endl;
		}
	}
	~Date()
	{
	}

	//判断是否闰年
	bool IsLeapYear(int year)
	{
		if ((0 == year % 4 && 0 != year / 100) || (0 == year % 400))
			return true;
		return false;
	}

	Date operator+(int days);//当前日期加n天后的日期
	Date operator-(int days);//当前日期减n天后的日期
	int operator-(const Date & d);//两个日期相隔的天数
	bool operator>(const Date & d);
	bool operator==(const Date & d)const;
	bool operator!=(const Date & d);
	Date & operator++();
	Date operator++(int);
	Date & operator--();
	Date operator--(int);

	friend ostream & operator<<(ostream & _cout, const Date d) {
		cout << "Date: " << d.year << "-" << d.month << "-" << d.day;
		return _cout;
	}

	int Month2_Day(int year, int month)
	{
		int Monthdays[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		if (month == 2 && IsLeapYear(year)) {
			return Monthdays[month] = 29;
		}
		else {
			return Monthdays[month];
		}
	}
private:
	int year;
	int month;
	int day;
};

