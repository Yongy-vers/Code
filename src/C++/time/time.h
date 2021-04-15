//	time.h --a header file for time class

#include<ostream>
#ifndef _TIME_H
#define _TIME_H

namespace TIME{
	enum months{JAN = 1, FEB, MAR, MAY, APR, JUN, JUL, AUG, SEP, OCT, NOV, DEC};	
	class time
	{
		private:
			int years;
			int months;
			int days;
			int hours;
			int minutes;
			long int seconds;
		public:
			time();
			~time();
			time(int y, int mon, int d, int h, int min, long int s);
			
			void addSec(long int s);
			void addMin(int min);
			void addHour(int h);
			void addDay(int d);
			void addMon(int mon);
			void addYear(int y);
			void reset(int y = 0, int mon = 1, int d = 0, int h = 0, int min = 0, long int s = 0);
			void showTime();
			
			time operator+(const time &t) const;
			time operator-(const time &t) const;
			time operator*(double n) const;
			friend time operator*(double m, const time &t){
				return t*m;		//inline definition
			}

			friend std::ostream &operator << (std::ostream &os, const time &t);


	};
}
#endif
