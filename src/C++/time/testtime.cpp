//	testtime.cpp -- for test

#include"mytime.h"

int main()
{
	mytime initstate;
	initstate.showTime();
	mytime now(2021, 4, 15, 11, 53, 25);
	now.showTime();
	mytime end(2012, 12, 31, 24, 59, 59);
	end.showTime();
	mytime sum = now + end;
	sum.showTime();
	return 0;
}
