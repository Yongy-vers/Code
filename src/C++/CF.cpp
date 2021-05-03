//	CF.cpp -- a program to show the contents of the first file and append another.
//	       -- just exercise for <fstream> 
#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<cstring>
#include<iomanip>

int main(int argc, char *argv[])
{
	using namespace std;
	if(argc == 1 || argc > 3){
		cout << "Usage: " << argv[0] << " [filename1]/[-h]" << " [filename2]" << endl;
		exit(EXIT_FAILURE);
	}
	if(!strcmp(argv[1], "-h")){
		cout << " -h" << setw(20) << setfill('*') << "show the page" << endl
		     << " maybe others appended in future~~~" << endl;
		exit(EXIT_SUCCESS);
	}
	char ch;
	ifstream fin;
	fin.open(argv[1], ios_base::in);
	
	if(fin.is_open())
	{
		cout << "Here are the current contents of \""
		     << argv[1] << " \"" << endl;
		while(fin.get(ch))
			cout << ch;
		fin.close();
	}
	cout << "\n-----------------------------------" << endl;
	// add something new
	ofstream fout(argv[2], ios::out | ios::app);
	if(!fout.is_open())
	{
		cerr << "Can't open \"" << argv[1] << "\"\n";
		exit(EXIT_FAILURE);
	}
	
	cout << "Enter the contens you want to add :\n";
	string contents;
	while(getline(cin, contents) && contents.size() > 0){
		fout << " " << contents << endl;
	}
	fout.close();
	cout << "Done!" << endl;
	return 0;
}
