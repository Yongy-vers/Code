//	error2.cpp -- an example used catch-throw mechanism dispose exception "C++ primer plus"
#include<iostream>

double hmean(double a, double b);

int main()
{
	double x, y, result;
	
	std::cout << "Enter two numbers: ";
	while (std::cin >> x >> y)
	{
		try{
			result = hmean(x, y);
		}
		catch (const char *s)	// start of exception handler
		{
			std::cout << s << std::endl;
			std::cout << "Enter a new pair of numbers: ";
			continue;
		}			// end of handler
		std::cout << "Harmonic mean of " << x << " and " << y
			  << " is " << result << std::endl;
		std::cout << "Enter next set of numbers <q to quit>: ";
	}
	std::cout << "Bye!\n";
	return 0;
}

double hmean(double a, double b)
{
	if (a == -b)
		throw "bad hmean() arguments: a = -b not allowed";
	return 2.0 * a * b / (a + b);
}
