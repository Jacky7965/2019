#include "date.h"

Date Date::operator+(int days) {
	if (days < 0) {
		return *this - (0 - days);
	}
	Date temp(*this);
	temp.day += days;
	int Monthday = Month2_Day(temp.year, temp.month);
	while (temp.day > Monthday) {
		temp.day -= Monthday;
		temp.month++;
		if (temp.month > 12) {
			temp.year++;
			temp.month = 1;
		}
	}
	return temp;
}

Date Date::operator-(int days) {
	if (days < 0) {
		return *this + (0 - days);
	}
	Date temp(*this);
	temp.day -= days;
	while (temp.day <= 0) {
		temp.month -= 1;
		if (temp.month < 1) {
			temp.year -= 1;
			temp.month = 12;
		}
		temp.day += Month2_Day(temp.year, temp.month);
	}
	return temp;
}

int Date::operator-(const Date & d) {
	Date minDate(*this);
	Date maxDate(d);
	if (minDate > maxDate) {
		minDate = d;
		maxDate = *this;
	}
	int cout = 0;
	while (minDate != maxDate) {
		cout++;
		++minDate;
	}
	return cout;
}

bool Date::operator>(const Date & d) {
	if ((year > d.year) ||
		(year == d.year && month > d.month) ||
		(year == d.year && month > d.month && day > d.day))
		return true;
	return false;
}

bool Date::operator==(const Date & d)const {
	return year == d.year &&
		month == d.month &&
		day == d.day;
}

bool Date::operator!=(const Date & d) {
	return !(*this == d);
}

Date& Date::operator++() {
	*this = *this + 1;
	return *this;
}

Date Date::operator++(int) {
	Date temp(*this);
	*this = *this + 1;
	return temp;
}

Date& Date::operator--() {
	*this = *this - 1;
	return *this;
}

Date Date::operator--(int) {
	Date temp(*this);
	*this = *this - 1;
	return temp;
}

void FunTest() {
	Date d1(1996, 9, 12);

	Date d2(d1);
	cout << d2 << endl;
	d2 = d1 + 10000;
	cout << d2 << endl;
	Date d3(d1);
	d3 = d1 - 100;
	cout << d3 << endl;
	Date d4(1996, 6, 4);
	int tmp = 0;
	tmp = d4 - d1;
	cout << tmp << endl;
}

int main() {
	FunTest();
	return 0;
}


