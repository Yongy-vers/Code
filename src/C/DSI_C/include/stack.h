/*	stack.h -- declarations for stack	*/

#ifndef _STACK_H
#define _STACK_H

#ifndef _BOOL_H
#include"bool.h"
#endif

typedef struct {
	void **array;
	int size;
	int capacity;
}Stack;

	//functions prototype
void initStack(Stack *s, int n);

void destroy(Stack *s);

void *gettop(Stack *s);

void push(Stack *s, void *ptr);

void pop(Stack *s);


#endif
