//	trick.cpp
//		-- implement some funny structure to display in the screen
//		-- by yongy-vers <yongy-vers@outlook.com>

#include<iostream>

using namespace std;

struct f1{
	char data[7] = {'0', ' ', '0', '\n',
			    ' ', 'V', ' '};
	const char *info = "hah";
};

struct f2{
	char data[11] = {'-', ' ', '-', '\n',
			'0', ' ', '0', '\n',
			' ', 'v', ' '};
	const char *info = "face";
};

struct f3{
	char data[7] = {'*', ' ', '*', '\n',
		       ' ', 'V', ' '};
	const char *info = "smile face";
};

int main()
{
	f1 smile;
	f2 face;
	f3 smileface;
	cout << smile.info << ": \n" << smile.data << endl;
	cout << face.info << ": \n" << face.data << endl;
	cout << smileface.info << ": \n" << smileface.data << endl;
	return 0;
}


