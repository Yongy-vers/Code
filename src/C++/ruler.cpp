//	ruler.cpp -- using recursion to subdivide a ruler

#include<iostream>
#include<fstream>
using namespace std;

const int Len = 66;
const int Divs = 6;
void subdivide(char ar[], int low, int high, int level);

int main()
{
	ofstream outFile;
	outFile.open("data.txt");
	char ruler[Len];
	int i;
	for(i = 1; i < Len - 2; i++){
		ruler[i] = ' ';
	}
	ruler[Len-1] = '\n';
	int max = Len - 2;
	int min = 0;
	ruler[min] = ruler[max] = '|';
	cout << ruler << endl;
	outFile << ruler << endl;
	for(i = 1; i < Divs; i++)
	{
		subdivide(ruler, min, max, i);
		cout << ruler << endl;
		outFile << ruler << endl;
		for(int j = 1; j < Len-2; j++)
			ruler[j] = ' ';
	}
	outFile.close();
	return 0;
}

void subdivide(char ar[], int low, int high, int level)
{
	if(level == 0)
		return;
	int mid = (high + low)/2;
	ar[mid] = '|';
	subdivide(ar, low, mid, level - 1);
	subdivide(ar, mid, high, level - 1);
}
