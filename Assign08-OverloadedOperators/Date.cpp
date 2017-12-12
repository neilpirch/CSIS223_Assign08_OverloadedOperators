#include "stdafx.h"
#include "Date.h"
#include <iostream>
#include <iomanip>

using namespace std;


istream&	operator>>(istream& isObject, Date& dateVal)			// overloaded extraction operator - friend to Date class
{
	isObject >> dateVal.month >> dateVal.day >> dateVal.year;
	return isObject;
}

ostream&	operator<<(ostream& osObject, const Date& dateVal)		// overloaded insertion  operator - friend to Date class
{
	osObject << setfill('0')
		<< setw(2) << dateVal.month << '/'
		<< setw(2) << dateVal.day << '/'
		<< setw(4) << dateVal.year << endl;
	return osObject;
}

Date::Date()										// default constructor (no parameters)
{
	setDefaultDate();
}

Date::Date(int m, int d, int y)					// constructor with month day year parameters
{
	month = m;
	day = d;
	year = y;
}

void	Date::setDate(int mm, int dd, int yyyy)
{
	month = mm;
	day = dd;
	year = yyyy;
}
void	Date::displayDate()	const
{
	cout << setfill('0') << right << setw(2) << month << "/" << setw(2) << day << "/" << setw(4) << year;
}

bool	Date::operator==(const Date& dateVal) const		// overloaded equals operator       ==
{
	return (day == dateVal.day && month == dateVal.month && year == dateVal.year);
}

bool	Date::operator!=(const Date& dateVal) const		// overloaded not equal operator    !=
{
	return (day != dateVal.day || month != dateVal.month || year != dateVal.year);
}

bool	Date::operator>(const  Date& dateVal) const		// overloaded less than operator    <
{
	return ((year > dateVal.year) ||
		(year == dateVal.year && month > dateVal.month) ||
		(year == dateVal.year && month == dateVal.month && day > dateVal.day));
}

bool	Date::operator<(const  Date& dateVal) const		// overloaded greater than operator >
{
	return ((year < dateVal.year) ||
		(year == dateVal.year && month < dateVal.month) ||
		(year == dateVal.year && month == dateVal.month && day < dateVal.day));
}

bool	Date::operator<=(const Date& dateVal) const		// overloaded less than or equal operator    <=
{
	bool result;
	result = operator>(dateVal);
	return !result;
}

bool	Date::operator>=(const Date& dateVal) const		// overloaded greater than or equal operator =>
{
	bool result;
	result = operator<(dateVal);
	return !result;
}

void	Date::setDefaultDate()					// set default date - 1/01/1970
{
	month = 1;
	day = 1;
	year = 1970;
}