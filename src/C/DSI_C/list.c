/*	list.c -- implementations for list.
**	author: yongy vers <yongy-vers@outlook.com>
*/

#include<stdio.h>
#include<stdlib.h>

#include"list.h"

#define SIZE 100
#define INCREMENT 10

void initList(list *L)
{
	*L = NULL;	//initialize an empty list
}

bool isEmpty(const list *L)
{
	if(*L == NULL)
		return true;
	else
		return false;
}

bool isFull(const list *L)
{
	int i = 0;
	while(*L != NULL){
		i++;
		*L = (*L)->next;
	}
	if( i < SIZE)
		return false;
	else
		return true;
}
bool createList(list *L)
{
	L = (struct node*)malloc(sizeof(struct node));		/*although struct node == node, when describe a pointer, I perfer the struct.*/
	L->next = NULL;
	int i;
	for(i = 0; i < SIZE; i++){
		struct node* p = (struct node*)malloc(sizeof(node));
		if(!p){
			fprintf(stderr, "memory allocated failure!");
			return false;		/*there better than exit(-1), won't terminate program right now.*/
		}
		p->data = 0;
		p->next = L->next;
		L->next = p;
	}
	return true;
}

bool deleteList(list *L)
{
	struct node *p;
	while(*L != NULL){
		p = (*L)->next;
		free(*L);
		*L = p;
	}
	return true;
}

bool addItem(list *L, int i, Element e)
{
	
}

bool deleteItem(list *L, int i, Element *e)
{

}

int searchItem(list L, int i, Element e)
{

}

/*
void storeDate(list *L, int n)
{

}
*/

	/* test drive */
int main()
{
	return 0;
}
