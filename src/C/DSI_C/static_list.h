/*	static_list.h -- header file for list implemented by allocated a continuous area.	*/

#ifndef _LIST_H		/* change as needed. */
#define _LIST_H

#ifndef _BOOL_H
#include"bool.h"
#endif

	/* macro definitions */
typedef int Elem;	/* change as needed. */

#define INITSIZE 100
#define INCREMENT 10

struct List{
	Elem *elemAddress;
	int length;
	int size;
};

typedef struct List list;

	/* function definitions */
status initList(list *L);

status insert(list *L, int i, Elem e);

status delete(list *L, int i, Elem *e);

status deleteList(list *L);

status searchList(const list *L);


status traverse(const list *L);

#endif
