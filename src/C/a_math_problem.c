/*	a_math_problem.c -- an exercise for math.h
**		prorequisite:	x^2 + y^2 == 1
**		     problem:   the maximum of (x + y)
**
*/

#include<stdio.h>
#include<math.h>

/* #define PI 3.1415926	*/	
#define PI (2*(asin(1)))

int main()
{
	long double temp = 0.0;
	long double max = 0.0;
	long double t = 0.0;
	while (t <= (2*PI)){
		temp = sin(t) + cos(t);
		if(temp > max)
			max = temp;
		t += ((PI)/64);
	}
	printf("(x + y) maximum: %Lf\n", max);	// Note: long double
	return 0;
}
