/*	dynamic_list.c -- implementations for list.  author: yongy vers
**	<yongy-vers@outlook.com>
*/

bool isEmpty(const list L)		/* L is the head node pointed to the first element onde in the list */
{
	if(L == NULL)
		return true;
	else
		return false;
}

int elemNum(const list L)
{
	list p = L;
	int i = 0;
	while(p != NULL){
		i++;
		p = p->next;
	}
	return i;
}

/* createList() get a pointer pointed to head node */
list *createList(list *L, int n)
{
	*L = (struct node*)malloc(sizeof(struct node));		/* head node*/
	(*L)->next = NULL;					/* head node point nothing *now.*/
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
	return L;		
}

bool deleteList(list *L)
{
	struct node *p, *q;
	p = (*L)->next;		/* the first element node */
	while(*p != NULL){
		q = (*p)->next;
		(*L)->next = q;
		free(*p);
		p = q;
	}
	free(*L);		/* free the head node */
	printf("list has been deleted!\n");
	return true;
}

bool addItem(list *L, int i, Element e)
{
	list *p = L;
	int j = 0;

	/* Note: (*p) == NULL is different with (*p)->next == NULL
		 (*p) == NULL which means head node isn't created
	   while (*p)->next == NULL means list is NULL(with no value)
	*/

	while(*p && j < i-1){		/* head node is not NULL && j < i-1 */
		*p = (*p)->next;
		++j;
	}
	if(!(*p) || j > i-1)		/* head node is NULL || j > i-1 */
		return false;

	struct node *s = (struct node*)malloc(sizeof(node));
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
	if((*p)->next == NULL){
		fprintf(stdout, "there is no element in the list.");
		return false;
	}
	/* considering delete an item need the location of the next item,*/
	/* make sure (*p)->next != NULL */
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

int searchItem(const list *L, const Element e)
{
	struct node *q = (*L)->next;
	int j = 1;
	while(*q){
		if((*q)->elem == e)
			return j;
		j++;
		(*q) = (*q)->next;
	}
	return false;
}

void traverse(const list *L)
{
	struct node *q = (*L)->next;
	if((*q) == NULL){
		fprintf(stdout, "your list is null!\n");
	}
	puts("your list: ");
	while((*q)->next){
		printf("%d ", (*q)->elem);
		*q = (*q)->next;
	}
}
