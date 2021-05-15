#include <stdio.h>

int multiarray[2][3][4] = {{{1,2,3,4},{5,6,7,8},{9,10,11,12}}, \
			{{13,14,15,16},{17,18,19,20},{21,22,23,24}}};

int main()
{
	printf("%p\t%p\t%p\n", multiarray, multiarray[0], multiarray[0][0]);
	int (*p)[3][4] = multiarray;
	printf("%p\t%p\n", p, p++);
	int (*r)[4] = multiarray[0];
	printf("%p\t%p\n", r, r++);
	int *t = multiarray[0][0];
	printf("%p\t%p\n", t, t++);
	return 0;
}
