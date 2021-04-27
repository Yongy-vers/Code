//	time.h --a header file for time class

#include<ostream>
#ifndef TIME_H
#define TIME_H

class mytime
{
	private:
		int years;
		int months;
		int days;
		int hours;
		int minutes;
		long int seconds;
	public:
		mytime();
		~mytime();
		mytime(int y, int mon, int d, int h, int min, long int s);
			
		void addSec(long int s);
		void addMin(int min);
		void addHour(int h);
		void addDay(int d);
		void addMon(int mon);
		void addYear(int y);
		void reset(int y = 0, int mon = 1, int d = 0, int h = 0, int min = 0, long int s = 0);
		void showTime();
			
		mytime operator+(const mytime &t) const;
		mytime operator-(const mytime &t) const;
		mytime operator*(double n) const;
		friend mytime operator*(double m, const mytime &t){
			return t*m;		//inline definition
		}

		friend std::ostream &operator << (std::ostream &os, const mytime &t);


};

#endif
