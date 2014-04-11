#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "randomsequence.h"
#include "sortvalidator.h"
#include "quicksort.h"

#define VERBOSE 0
#define TESTS_AMT 100

#if VERBOSE
void printArray(int *tb,int size)
{
	for(int i=0;i<size;++i)
		printf("%d ",tb[i]);
	putchar('\n');
}
#endif
int performTest(int size)
{
	int* unsorted=(int*)malloc(sizeof(int)*size);
	fillWithRandomSequence(unsorted,size);
	int* sorted=(int*)malloc(sizeof(int)*size);
	memcpy(sorted,unsorted,sizeof(int)*size);
	quickSort(sorted,0,size-1);
	int res=isValidSort(unsorted,sorted,size);
	#if VERBOSE
		int partial_size;
		if(size>15)
		{
			partial_size=15;
			printf("Only printing %d first charactes",partial_size);
		}
		else
			partial_size=size;
		printf("Unsorted array:\n");
		printArray(unsorted,partial_size);
		printf("Sorted array:\n");
		printArray(sorted,partial_size);	
	#endif
	free(unsorted);
	free(sorted);
	return res;
}

int main()
{
	int res[5];
	for(int i=0;i<TESTS_AMT;++i)
	{
		res[0]=performTest(1);
		res[1]=performTest(5);
		res[2]=performTest(15);
		res[3]=performTest(100);
		res[4]=performTest(1000);
		int overall=1;
		for(int j=0;j<5;++j)
			overall&=res[j];
		if(overall==0)
		{
			fprintf(stderr,"Sort algorithm is invalid.");
			return 1;
		}
	}
	fprintf(stderr,"Sort algorithm passed the test!");
	return 0;
}