//waiting.cpp -- using clock() in a time delay loop

#include<iostream>
#include<ctime>	//describes clock() function, clock_type

int main()
{
	using namespace std;
	cout <<"Enter the delay time in seconds: ";
	float secs;
	cin >> secs;
	clock_t delay = secs * CLOCKS_PER_SEC;
	cout << "starting\n";
	clock_t start = clock();
	while(clock() - start < delay)
		;
	cout <<secs<< " secs delay has done\n" ;
	return 0;
}
