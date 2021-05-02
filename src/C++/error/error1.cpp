//	error1.cpp -- a good example for error dispose
#include<iostream>
#include<cfloat>	// for DBL_MAX

bool hmean_1(double a, double b, double *ans);
bool hmean_2(double a, double b, double &ans);

int main()
{
	double x, y, result;

	std::cout << "Enter two numbers: ";
	while (std::cin >> x >> y)
	{
		if(hmean_2(x, y, result))
		//if(hmean_1(x, y, &result))
			std::cout << "Harmonic mean of " << x << " and " << y
				  << " is " << result << std::endl;
		else
			std::cout << "One value should not be the negative "
				  << "of the other - try again.\n";
		std::cout << "Enter next set of numbers <q to quit>: ";
	}
	std::cout << "Bye!\n";
	return 0;
}

bool hmean_1(double a, double b, double *ans)
{
	if(a == -b)
	{
		*ans = DBL_MAX;
		return false;
	}
	else
	{
		*ans = 2.0 * a * b / (a + b);
		return true;
	}
}

bool hmean_2(double a, double b, double &ans)
{
	if(a == -b)
	{
		ans = DBL_MAX;
		return false;
	}
	else
	{
		ans = 2.0 * a * b / (a + b);
		return true;
	}
}
