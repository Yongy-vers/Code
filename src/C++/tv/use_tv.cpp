//	use_tv.cpp -- using the Tv and Remote classes
#include<iostream>
#include"tv.h"

int main()
{
	using std::cout;
	using std::endl;
	Tv yangtv;
	cout << "Initial settings for yangtv" << endl;
	yangtv.settings();
	yangtv.onoff();
	cout << "Tv has been opened, parameters are as follows:" << endl;
	yangtv.settings();
	yangtv.chanup();
	cout << "\nAdjusted settings for yangtv" << endl;
	yangtv.settings();
	
	Remote remote;
	
	remote.set_chan(yangtv, 10);
	yangtv.settings();
	for(int i = 5; i > 0; i--)
	{
		remote.volup(yangtv);
	}
	cout << "\nyangtv settings after using remote:" << endl;
	yangtv.settings();
	
	Tv yongytv(Tv::On);
	yongytv.set_mode();
	remote.set_chan(yongytv, 66);
	cout << "\nyongytv settings:" << endl;
	yongytv.settings();
	return 0;
}
	
	
