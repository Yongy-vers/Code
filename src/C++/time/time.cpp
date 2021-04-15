//	time.cpp --function definitions for class time.
//		 --a stupid way been used to calculate the time
#include<iostream>	
#include"time.h"

using namespace TIME;

time::time()
{
	years = days = hours = minutes = 0;
	seconds = 0;
	months = JAN;
}

time::~time()
{
}

time::time(int y, int mon, int d, int h, int min, long int s)
{
	years = y;
	months = mon;
	days = d;
	hours = h;
	minutes = min;
	seconds = s;
}

void time::addSec(long int s)
{
	int m,n;
	m = (seconds + s) / 60;
	n = (seconds + s) % 60;
	seconds = n;
	int j,k;
	j = (minutes + m) / 60;
	k = (minutes + m) % 60;
	minutes = k;
	m = (hours + j) / 24;
	n = (hours + j) % 24;
	hours = n;
	j = (days + m) / 30;	//suppose every months = 30 days
	k = (days + m) % 30;
	days = k;
	m = (months + j) / 12;
	n = (months + j) % 12 + 1;
	months = n;
	years += m;
}

void time::addMin(int min)
{
	int m, n;
	m = (minutes + min) / 60;
	n = (minutes + min) % 60;
	minutes = n;
	int j, k;
	j = (hours + m) / 24;
	k = (hours + n) % 24;
	hours = k;
	m = (days + j) / 30;
	n = (days + j) % 30;
	days = n;
	j = (months + m) / 12;
	k = (months + m) % 12;
	months = k;
	years += j;
}

void time::addHour(int h)
{
	int m, n;
	m = (hours + h) / 24;
	n = (hours + h) % 24;
	hours = n;
	int j, k;
	j = (days + m) / 30;
	k = (days + m) % 30;
	days = k;
	m = (months + j) / 12;
	n = (months + j) % 12;
	months = n;
	years += m;
}

void time::addDay(int d)
{
	int m, n;
	m = (days + d) / 30;
	n = (days + d) % 30;
	days = n;
	int j, k;
	j = (months + m) / 12;
	k = (months + m) % 12;
	months = k;
	years += j;
}

void time::addMon(int mon)
{
	int m, n;
	m = (months + mon) / 12;
	n = (months + mon) % 12;
	months = n;
	years += m;
}

void time::addYear(int y)
{
	years += y;
}

void time::showTime()
{
	cout << "years: " << years << endl
	     << "months: " << months << endl
	     << "days: " << days << endl
	     << "hours: " << hours << endl
	     << "minutes: " << minutes << endl
	     << "seconds: " << seconds << endl;
}

time time::operator+(const time &t) const
{
	time sum;
	int m,n;
        int m = (seconds + t.seconds) / 60;
        int n = (seconds + t.seconds) % 60;
        sum.seconds = n;
        int j,k;
        int j = (minutes + m + t.minutes) / 60;
        int k = (minutes + m + t.minutes) % 60;
        sum.minutes = k;
        m = (hours + j + t.hours) / 24;
        n = (hours + j + t.hours) % 24;
        sum.hours = n;
        j = (days + m + t.days) / 30;    //suppose every months = 30 days 
        k = (days + m + t.days) % 30;
        sum.days = k;
        m = (months + j + t.months) / 12;
        n = (months + j + t.months) % 12 + 1; 
        sum.months = n;
        sum.years += m;
	return sum;
}

time time::operator-(const time &t) const
{
	time diff;
	long long int totalSeconds_t = t.seconds + t.minutes * 60 + t.hours * 3600;
	long long int totalSeconds = seconds + minutes * 60 + hours * 3600;
	std::cout << "waitint to implement!";
}

time time::operator*(double n) const
{

}

std::ostream &operator<<(std::ostream &os, const time &t)
{
	os << "years: " << years << endl
           << "months: " << months << endl
           << "days: " << days << endl
           << "hours: " << hours << endl
           << "minutes: " << minutes << endl
           << "seconds: " << seconds << endl;
	return os;
}
