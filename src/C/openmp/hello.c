/* using multiple threads to display "hello" with openmp API
 * the result will depend on your core number
 * compile format: gcc -fopenmp ***.c -o hello
 */

#include<stdio.h>
#include<omp.h>

int main(void)
{
	#pragma omp parallel
	printf("Hello, world.\n");
	return 0;
}
