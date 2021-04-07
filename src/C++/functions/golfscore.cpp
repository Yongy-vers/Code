//	golfsocre.cpp -- record score and calculate the average

//		input()	  -- int input(double *) return the size of array
//		show()	  -- void show(double [])
//		average() -- double average(double [], int)

#include<iostream>
#include<cctype>

#define SIZE 10
using namespace std;
	
	// prototypes
int input(double *);
void show(double *, int i);
double average(double *, int );

int main()
{
	int i;
	double result;
	double score[SIZE];
	i = input(score);
	result = average(score, i);
	show(score, i);
	cout << endl;
	cout << result << endl;
	return 0;
}

	// definitions
int input(double *array)
{
	cout << "Please input your socres:(use any letter to end)\n";
	int i = 0;
	while(i < SIZE){
		double j;
		cin >> j;
		if(isalpha(j)){
			i++;
			break;
		}
		array[i] = j;
		i++;
	}
	return i;
}

void show(double *array, int i)
{
	for(int j = 0; j < i; j++)
		cout << array[j] << " ";
}

double average(double array[], int i)
{
	int j = 0;
	double sum = 0;
	while(j < i){
		sum += array[j];
		j++;
	}
	return (sum/i);
}

