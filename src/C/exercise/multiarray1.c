#include <stdio.h>



int main()
{
    int multiarray[2][3][4] = {{{1,2,3,4},{5,6,7,8},{9,10,11,12}}, \
			{{13,14,15,16},{17,18,19,20},{21,22,23,24}}};
	printf("%p\t%p\t%p\n", multiarray, multiarray[0]);
	int (*p)[3][4] = multiarray;
    printf("address\t\t\tvalue\n");
	printf("%p\t%x\t%p\t%x\n", p,*p, p++, *p);
	int (*r)[4] = multiarray[0];
	printf("%p\t%x\t%p\t%x\n", r,*r, r++, *r);
	int *t = multiarray[0][0];
	printf("%p\t%02X\t%p\t%02X\n", t,*t, t++, *t);
	return 0;
}
