#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "randomsequence.h"
#include "sortvalidator.h"
#include "quicksort.h"

void printArray(int *tb,int size)
{
	for(int i=0;i<size;++i)
		printf("%d ",tb[i]);
	putchar('\n');
}


int main()
{
	const int size1=13;
	int *test1=(int*)malloc(sizeof(int)*size1);
	int *test1sorted=(int*)malloc(sizeof(int)*size1);
	fillWithRandomSequence(test1,size1);
	memcpy(test1sorted,test1,sizeof(int)*size1);
	printArray(test1,size1);
	quickSort(test1sorted,0,size1-1);
	printArray(test1sorted,size1);
	if(isValidSort(test1,test1sorted,size1))
		printf("Sort is valid!\n");
	else
		printf("Sort is invalid!\n");
		
	const int size2=4;
	int *test2=(int*)malloc(sizeof(int)*size2);
	int *test2sorted=(int*)malloc(sizeof(int)*size2);
	test2[0]=1;
	test2[1]=2;
	test2[2]=1;
	test2[3]=-24;
	memcpy(test2sorted,test2,sizeof(int)*size2);
	printArray(test2,size2);
	quickSort(test2sorted,0,size2-1);
	printArray(test2sorted,size2);
	if(isValidSort(test2,test2sorted,size2))
		printf("Sort is valid!\n");
	else
		printf("Sort is invalid!\n");	
		
	return 0;
}