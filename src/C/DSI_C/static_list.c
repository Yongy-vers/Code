/*	static_list.c -- source file for static_list.h		*/

#include<stdio.h>
#include<stdlib.h>
#include"static_list.h"

status initList(list *L)
{
	L->elemAddress = (Elem *)malloc(INITSIZE * sizeof(Elem));
	if(!(L->elemAddress)){
		fprintf(stderr, "allocate memory failed!\n");
		exit(EXIT_FAILURE);
	}
	L->length = 0;
	L->size = INITSIZE;
	return true;
}

status insert(list *L, int i, Elem e)
{
	if(i < 0 || i > L->size){
		return false;
	}
	if(L->length == L->size){
		//return false;		// lazy way
		L->elemAddress = (Elem *)realloc((L->size + INCREMENT) * sizeof(Elem));
		if(!(L->elemAddress)){
			fprintf(stderr,"realloc memory failed!\n");
			return false;
		}
		L->size = L->size + INCREMENT;
		L->length = L->length;
	}
	int j = L->size-1;
	while(j >= i){
		L->elemAddress[j] = L->elemAddress[j-1];
		j--;
	}
	L->length++;
	L->elemAddress[i] = e;
	return true;
}

status delete(list *L, int i, Elem *e)
{
	if(i < 0 || i > L->length)
		return false;
	e = L->elemAddress[i-1];
	int j = L->length;
	while(i < j){
		L->elemAddress[i-1] = L->elemAddress[i];
		i++;
	}
	L->length--;
	return true;	
}

status deleteList(list *L)
{
	if(L == NULL)
		return true;
	free(L->elemAddress);
	return true;
}

status searchList(const list *L, Elem e)
{
	int i = 0;
	while(i < L->length){
		if(L->elemAddress[i] == e){
			fprintf(stdout, "found element in %d\n", i+1);
			return true; 
		}
		i++;
	}
	return false;
}

status traverse(cnost list *L)
{
	int i = 0;
	while(i < L->length){
		fprintf(stdout, "%d ", L->elemAddress[i]);
		i++;
	}
	return true;
}
