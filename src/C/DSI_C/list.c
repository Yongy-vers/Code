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

bool isEmpty(const list L)
{
	if(L == NULL)
		return true;
	else
		return false;
}

int eleNum(const list L)
{
	int i = 0;
	while(L != NULL){
		i++;
		L = L->next;
	}
	return i;
}

/*
bool isFull(const list L)
{
	int i = eleNum(L);
	if( i < SIZE)
		return false;
	else
		return true;
}
*/

bool createList(list *L, int n)
{
	L = (struct node*)malloc(sizeof(struct node));		/*although struct node == node, when describe a pointer, I perfer the struct.*/
	L->next = NULL;
	int i;
	printf("Input your store one by one");
	for(i = 0; i < n; i++){
		struct node* p = (struct node*)malloc(sizeof(node));
		if(!p){
			fprintf(stderr, "memory allocated failure!");
			return false;		/*there better than exit(-1), won't terminate program right now.*/
		}
		scanf("%d", &(p->data));
		p->next = L->next;
		L->next = p;
	}
	printf("list created done!");
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
	printf("list has been deleted!");
	return true;
}

bool addItem(list *L, int i, Element e)
{
	list *p = L;
	struct node s;
	int j = 0;
	while(*p && j < i-1){
		p = p->next;
		++j;
	}
	if(!(*p) || j > i-1)
		return false;
	s = (struct node*)malloc(sizeof(node));
	if(!s)
		return false;
	s->next = p->next;
	p->next = s;
	printf("element %d added done!", e);
	return true;
}
}

bool deleteItem(list *L, int i, Element *e)
{
	list *p = L;
	struct node *q;
	int j = 0;
	while((*p)->next && j < i-1){
		p = p->next;
		++j;
	}
	if(!(*p)->next || j > i-1)
		return false;
	q = (*p)->next;		//there, q is the one to be deleted
	(*p)->next = q->next;
	*e = q->elem;
	free(q);
	printf("Element %d deleted done!", *e);
	return true;
}

int searchItem(list L, int i, Element e)
{
	list p = L;
	int j = 0;
	if(i > elemNum(L)){
		printf("wrong search!");
		return false;
	}
	while(p && j < i){
		j++;
		p = p->next;
	}
	while(p){
		if(p->elem == e)
			return j;
		j++;
		p = p->next;
	}
	return false;
}


	/* test drive */
int main()
{
	return 0;
}
