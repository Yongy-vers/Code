/*	list.h -- declarations for list.	*/
/*	ADT list{
**			Element;	}implemented by
**			Relation;	}a struct
**
**			Operations;	}functions
**		}
#ifndef	_LIST_H
#define _LIST_H

#ifndef _BOOL_H
#include"bool.h"
#endif

typedef int Element;	//change as needed

	// struct for node in the list
typedef struct node{
	Element elem;		// element
	struct node *next;	// a pointer pointed to the next node
};

	// head node (actually a pointer to the first node)
typedef struct node* list;

	// functions prototype
void initList(list *L);
bool createList(list *L);
bool deleteList(list *L);
bool addList(list *L, int i, Element e);
bool removeList(list *L, int i, Element *e);
int searchList(list L, int i);
void traverse(list L);
#endif
