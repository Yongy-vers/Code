/* This is a simple record program for student records
** Function: get students' record and store and print
**
*/

#include<iostream>
#include<string>
#include<stdio.h>
#define SIZE 1000	//record size
using namespace std;

int main(void)
{
	FILE * fp;
	fp = fopen("data.md", "a+");
	if(!fp){
		fprintf(stderr, "can't create the store file");
		exit(-1);
	}
	string firstname, lastname;
	char grade;
	int age;
	cout << " Welcome to the record system " << endl;
	int i = 1;
	while(i--){
		cout << "your first name:";
		getline(cin, firstname);
		cout << "your last name:";
		getline(cin, lastname);
		cout << "your grade:";
		cin >> grade;
		cout << "your age:";
		cin >> age;
	}
	cout << firstname << " " << lastname << endl;
	cout <<"grade: " << grade << " age: " << age << endl;
	//fprintf(fp, "\t first name \t last name \t grade \t age\t\n");
	fprintf(fp, "\t%-s\t%-s\t%-c\t%-d\t", firstname, lastname, grade, age);
	fclose(fp);
	return 0;
}
