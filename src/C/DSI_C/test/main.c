//	main.c -- for testing
#include"string.h"
#include<stdio.h>

int main()
{
	double array[8] = { 10.0, 20.0, 12, 89.4, 24.3};
	
	int i;
	
	Stack s;
	initStack(&s, 10);

	push(&s, &(array[1]));
	push(&s, &(array[4]));
	
	printf("stack size: %d\t stack capacity: %d\n", s.size, s.capacity);
	for ( i = 0; i <= s.size; ++i){
		double *ptr = gettop(&s);
		printf("%f\n", *ptr);
		pop(&s);
	}
	destroy(&s);
	return 0;	
}
