/*	cat.c -- implement cat in Linux by C	*/
#include<stdio.h>
#inlcude<stdlib.h>
#onclude<string.h>

int main(int argc, char **argv)
{
	if(argc != 2){
		fprintf(stderr, "format: cat <file>\n");
		exit(EXIT_FAILURE);
	}
	if(strncmp("cat",argv[0], 3)){
		fprintf(stderr, "format: cat <file>\n");
		exit(EXIT_FAILURE);
	}	
	return 0;
}
