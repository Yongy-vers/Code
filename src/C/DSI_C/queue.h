/*	queue.h -- declarations for sequential queue	*/
/*	ADT queue{	
**		[Element]	:Element elem
**		[Relation]
**		[operations]
**	}
*/
#ifndef _QUEUE_H
#define _QUEUE_H

#ifndef _BOOL_H
#include"bool.h"
#endif

typedef int Element;

	//type of node
typedef struct node{
	Element elem;
	struct node *next;
}node;

typedef struct node *qptr;

typedef struct{
	qptr front;
	qptr rear;
}queue;

void initQueue(queue *Q);
bool deleteQueue(queue *Q);
bool isEmpty(queue Q);
int queueLength(queue Q);
bool getHead(queue Q, Element *e);
bool enQueue(queue *Q, Element e);
bool deQueue(queue *Q, Element *e);
void traverse(queue Q);
#endif
