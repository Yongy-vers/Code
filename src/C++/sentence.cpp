//	sentence.cpp -- analyse a sentence component

#include<iostream>
#define SIZE 20
int main()
{
	using namespace std;
	char ch;
	int i = 0;
	int j = 0;
	char word[SIZE][SIZE];
	int spaces = 0;
	int words = 0;
	int total = 0;
	cin.get(ch);
	while(ch != '#')
	{
		while(ch != ' '){
			word[i][j] = ch;
			j++;
		}		
		if(ch == ' '){
			i++;
			++spaces;
			
		}
		++total;
		cin.get(ch);
	}
	words = i+1;
	cout << words << " words, " << spaces << " space, " << total;
	cout << "characters total in sentence\n";
	int m;
	int n;
	for(m = 0; m < i; m++)
	{
		for(n = 0; n < j; n++)
		{
			cout << word[m][n];
		}
		cout << "\n";
	}
	return 0;
}
