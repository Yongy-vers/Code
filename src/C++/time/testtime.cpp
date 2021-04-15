//	testtime.cpp -- for test

#include<iostream>
#include"time.h"

using namespace TIME;
int main()
{
	time initstate;
	initstate.showTime();
	time now(2021, 4, 15, 11, 53, 25);
	now.showTime();
	time end(2012, 12, 31, 24, 59, 59);
	end.showTime();
	time sum = now + end;
	sum.showTime();
	return 0;
}
