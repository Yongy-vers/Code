/* This is a simple record program for student records
** Function: get students' record and store and print
**
*/

#include<iostream>
#include<string>	//string
#include<fstream>	//ofstream
#include<cstdlib>	//exit()
#include<iomanip>	//setw()

#define SIZE 1000	//record size

using namespace std;
struct student{
	string firstname, lastname;
        char grade;
        int age;
};
int main(void)
{
	ofstream outFile;
	outFile.open("data.txt");
	if(!outFile.is_open()){
		cout<< "can't create the store file"<<endl;
		exit(-1);
	}
	struct student stu[SIZE];
	char ch;
	cout << "Welcome to the record system " << endl;
	int i = 0;
	while(i < SIZE){
		getchar();
		cout << "your first name:";
		getline(cin, stu[i].firstname);
		cout << "your last name:";
		getline(cin, stu[i].lastname);
		cout << "your grade:";
		cin >> stu[i].grade;
		cout << "your age:";
		cin >> stu[i].age;
	label:
		cout << "want to gon(y/n?)"<<endl;
		cin.clear();
		cin >> ch;
		if(ch == 'n')
			break;
		else if(ch == 'y'){
			i++;
		}
		else{
			cout<<"wrong directive"<< endl;
			goto label;
		}		
	}
	cout << endl;
	cout << "Records:\n";
	int j = 0;
	outFile <<setw(15) << left << "id" << setw(15) << left <<"first name"
                        << setw(15) << left << "last name" << setw(15) << left <<"grade"
                        << setw(15) << left << "age" << endl;
	while(j <= i){
		cout << stu[j].firstname << " " << stu[j].lastname << endl;
		cout <<"grade: " <<stu[j].grade << " age: " << stu[j].age << endl;
		outFile << setw(15) << left << j << setw(15) << left << stu[j].firstname
			<<setw(15) << left << stu[j].lastname << setw(15) << left << stu[j].grade
			<< setw(15) << left << stu[j].age << endl;
		j++;
	}
	outFile.close();
	return 0;
}
