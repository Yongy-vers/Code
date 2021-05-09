/*	stack.c -- implementations for stack	*/
#include "stack.h"
#include <stdlib.h>
void initStack(Stack *s, int n)
{
	s->capacity = (n > 0) ? n : 1;
	s->array = (void **)malloc((s->capacity) * sizeof(void *));
	s->size = 0;
}

void destroy(Stack *s)
{
	free(s->array);
}

void *gettop(Stack *s)
{
	return (s->size == 0) ? NULL : s->array[s->size - 1];
}

void push(Stack *s, void *ptr)
{
	if(s->size == s->capacity)
	{
		return;
	}
	s->array[s->size] = ptr;
	++(s->size);
}

void pop(Stack *s)
{
	if(s->size != 0){
		--(s->size);
	}
}

