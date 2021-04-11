//	exercise2.cpp	-- from "C++ primer plus" by Stephen Prata 

#include<iostream>

using namespace std;

const int SIZE = 20;
struct student{
	char name[SIZE];
	char hobby[SIZE];
	int level;
};

int getinfo(student stu[], int n);
void display1(student stu);
void display2(const student* stu);
void display3(const student stu[], int n);

int main()
{
	cout << "Enter class size: ";
	int class_size;
	cin >> class_size;
	while(cin.get() != '\n')
		continue;

	student* ptr_stu = new student[class_size];
	int entered = getinfo(ptr_stu, class_size);
	for(int i = 0; i < entered; i++)
	{
		display1(ptr_stu[i]);
		display2(&ptr_stu[i]);
	}
	display3(ptr_stu, entered);
	delete [] ptr_stu;
	cout << "Done\n";
	return 0;
}

int getinfo(student stu[], int n)
{
	int i = 0;
	while(i < n){
		cout << "Name: ";
		cin.get(stu[i].name, SIZE);
		cout << "Hobby: ";
		cin >> stu[i].hobby;
		cout << "Level: ";
		cin >> stu[i].level;
		i++;
	}
	return i;
}

void display1(student st)
{
	cout << st.name;
	cout << st.hobby;
	cout << st.level;
	cout << endl;
}

void display2(const student* stu)
{
	cout << stu->name;
	cout << stu->hobby;
	cout << stu->level;
	cout << endl;
}

void display3(const student stu[], int n)
{
	for(int i = 0; i < n; i++)
	{
		cout << stu[i].name;
		cout << stu[i].hobby;
		cout << stu[i].level;
		cout << endl;
	}
}
