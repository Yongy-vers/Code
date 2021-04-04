/* #pragma omp parallel for */

#include<stdio.h>

#define SIZE 10

int main(int argc, char **argv)
{
	int array[SIZE];
	
	/*	test 1
	#pragma omp parallel for
	for(int i = 0; i < SIZE; i++){
		array[i] = i;
		printf("array[%d] has been created\n", array[i]);
	}
	*/
	

	/*	test 2 fabonic(a wrong use case)
	array[0] = 0; array[1] = 1;
	#pragma omp parallel for
	for(int i = 2; i < SIZE; i++){
		array[i] = array[i-1] + array[i-2];
		printf("array[%d] has been created\n", array[i]);
	}
	*/
	
	/*	test 3 addition(another wrong case) 
	*	test result can be 44, 45, 38... although most of all is 45.
		parallel add bug(a and b add c simtaneously, the result is uncertain)	
	*/
	array[0] = 0;
	#pragma omp parallel for
	for(int i = 1; i < SIZE; i++){
		array[i] = i;
		array[0] += array[i];
		printf("%d has been added, now the value is %d\n", array[i], array[0]);
	}
	printf("Final result: %d\n", array[0]);
	return 0;

}
