//	calculate.cpp -- calculate the adjust mean value of two numbers
//	calculate() -- double calculate(double a, double b);

#include<iostream>

using namespace std;
#define AdMean(x,y) (2.0*(x)*(y))/((x)+(y))

	// prototype
double	calculate(double a, double b);

int main()
{
	double a,b;
	while(1){
		cout << "Please input two number:\n";
		cin >> a >> b;
		if(a == 0 || b == 0)
			break;
		cout << "AdMeans by function is " << calculate(a, b) << endl;
		cout << "AdMeans by macro is " << AdMean(a,b) << endl;
	}
	cout << "over!" << endl;
	return 0;
}

	// definition
double calculate(double x, double y)
{
	return (2.0*x*y)/(x+y);
}
