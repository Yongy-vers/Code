/*	list.c -- implementations for list.  author: yongy vers
**	<yongy-vers@outlook.com>
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"list.h"

#define SIZE 100
#define INCREMENT 10

void getDirective(char *str);
int direct(const char *str);

void initList(list *L)
{
	*L = NULL;	//initialize an empty list
	printf("List initialized done!\n");
}

bool isEmpty(const list L)
{
	if(L == NULL)
		return true;
	else
		return false;
}

int eleNum(list L)
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
	*L = (struct node*)malloc(sizeof(struct node));		/*although struct node == node, when describe a pointer, I perfer the struct.*/
	(*L)->next = NULL;
	int i;
	printf("Input your data one by one: ");
	for(i = 0; i < n; i++){
		struct node* p = (struct node*)malloc(sizeof(node));
		if(!p){
			fprintf(stderr, "memory allocated failure!\n");
			return false;		/*there better than exit(-1), won't terminate program right now.*/
		}
		scanf("%d", &(p->elem));
		p->next = (*L)->next;
		(*L)->next = p;
	}
	printf("List created done!\n");
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
	printf("list has been deleted!\n");
	return true;
}

bool addItem(list *L, int i, Element e)
{
	list *p = L;
	struct node *s;
	int j = 0;
	while(*p && j < i-1){
		*p = (*p)->next;
		++j;
	}
	if(!(*p) || j > i-1)
		return false;
	s = (struct node*)malloc(sizeof(node));
	if(!s)
		return false;
	s->next = (*p)->next;
	(*p)->next = s;
	s->elem = e;
	printf("element %d added done!\n", e);
	return true;
}

bool deleteItem(list *L, int i, Element *e)
{
	list *p = L;
	struct node *q;
	int j = 0;
	while((*p)->next && j < i-1){
		*p = (*p)->next;
		++j;
	}
	if(!(*p)->next || j > i-1)
		return false;
	q = (*p)->next;		//there, q is the one to be deleted
	(*p)->next = q->next;
	*e = q->elem;
	free(q);
	printf("Element %d deleted done!\n", *e);
	return true;
}

int searchItem(list L, int i, Element e)
{
	list p = L;
	int j = 1;
	int k = 0;
	while(L != NULL){
		k++;
		L = L->next;
	}
	if(i > k){
		printf("wrong search!\n");
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

void traverse(list L)
{
	puts("Your list: ");
	while(L->next){
		printf("%d ", L->next->elem);
		L = L->next;
	}
}

	/* test drive */
int main()
{	
	list L = (struct node*)malloc(sizeof(node));
	if(!L){
		fprintf(stderr, "error to allocate memory!\n");
		exit(-1);
	}
	initList(&L);
	printf("List length: ");
	int length;
	scanf("%d", &length);
	if(!createList(&L, length)){
		fprintf(stderr, "failed to create list\n");
		exit(-1);
	}
	char buffer[10];
	int i;
	Element e;
	printf("Now there are five choices for you:\n");
	printf("1.add	 2.delete	3.search	4.traverse	5.exit\n");
	while(1){
		printf("\nInput your action>> ");
		fflush(stdin);
		scanf("%s", buffer);
		switch(direct(buffer)){
			case 1:
				printf("you have chosen the add operation, now input the position and the value:\n");
				scanf("%d %d", &i, &e);
				if(!addItem(&L, i, e)){
					printf("something wrong with the insert operation.\n");
				}
				else{
					printf("%d has been added in the list with the position of %d.\n", e, i);
				}
				break;
			case 2:
				printf("you have chosen the delete operation, now input the position:\n");
				scanf("%d",&i);
				if(!deleteItem(&L, i, &e)){
					printf("something wrong with the delete operation.\n");
				}
				else{
					printf("%d has been deleted successfully.\n", e);
				}
				break;
			case 3:
				printf("you have chosen the search operation, now input the initial place and value searched:\n");
				scanf("%d %d", &i, &e);
				int j = searchItem(L, i, e);
				if(!j){
					printf("there is possibly no value %d in the list or something wrong.\n", e);
				}
				else{
					printf("%d has been found in %d.\n", e, i);
				}
				break;
			case 4:
				printf("you have chosen the traverse operation.\n");
				traverse(L);
				break;
			case 5:
				printf("exiting~\n");
				exit(EXIT_SUCCESS);
		}
	}
	return 0;
}


	/* function for interact */

int direct(const char *str)
{
	if(!strncmp(str, "add", 3))
		return 1;
	else if(!strncmp(str, "delete", 6))
		return 2;
	else if(!strncmp(str, "search", 6))
		return 3;
	else if(!strncmp(str, "traverse", 8))
		return 4;
	else if(!strncmp(str, "exit", 4))
		return 5;
	else{
		printf("wrong directive! eixt will be executed\n");
		return 5;
	}
}
