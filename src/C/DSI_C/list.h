/*	list.h -- declarations for list.	*/
/*	ADT list{
**			[Element;	]implemented by
**			[elation;	]a struct
**
**			[Operations;	]functions
**		}
*/
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
}node;

	// head node (actually a pointer to the first node)
typedef struct node* list;

	// functions prototype
/* 	function: initList()
**	interface: Address of a list
**	influence: initialize a list
**	return: none
*/
void initList(list *L);

/*	function: createList()
**	interface: Address of a list, with the num of node equals n
**	influence: create a list with meaningful node
**	return: true(success)	false(failure)
*/
bool createList(list *L, int n);

/*	function: deleteList()
**	interface: Address of the list
**	influence: delete a list totally
**	return: true(success)	false(failure)
*/
bool deleteList(list *L);

/*	function: addItem()
**	interface: Address of the list, an integer to indicate the insert place, and the value inserted
**	influence: At the place of i th, Insert a node with element equal to e
**	return: true(success)	false(wrong place or other failures)
*/
bool addItem(list *L, int i, Element e);

/*	function: deleteItem()
**	interface: Address of the list, the number of node to be deleted, and the deleted element value
**	influence: Delete the ith node
**	return: ture(success)	false(wrong place or other failures)
*/
bool deleteItem(list *L, int i, Element *e);

/*	function: searchItem()
**	interface: Name of list, the initial search place, the value searched
**	influence: Search a node with specified element value
**	return: nodeplace(success)	false(failed search)
*/
int searchItem(list L, int i, Element e);

/*	function: traverse()
**	interface: Name of list
**	influence: Traverse a list and output the result onto screen
**	return: none
*/
void traverse(list L);

/*bool isFull(const list L);*/

bool isEmpty(const list L);
int elemNum(list L);
#endif
