/*Dla przykladowych testow clock() jest zbyt niedokladne (dokladnosc 15ms), zeby zmierzyc tak krotkie przedzialy czasu.
*Doda³em test 600000 * 100, zeby bylo widac ze pomiar min dziala (100 testow zajmuje ok 20 sekund na moim komputerze, wiec
*prosze o cierpliwosc)
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include "randomsequence.h"
#include "quicksort.h"

#define TEST_SIZES_AMT 4
#define TEST_AMT 100
#define BENCH_QSORT 1
#define BENCH_QUICKSORT 2

int cmp(const void *a,const void *b)
{
	return (*(int*)a-*(int*)b);
}

double performTest(const int *tb,int size,int type)
{
	int* tb_copy=(int*)malloc(sizeof(int)*size);
	memcpy(tb_copy,tb,sizeof(int)*size);
	clock_t time;
	time=clock();
	if(type==BENCH_QSORT)
	{
		qsort(tb_copy,size,sizeof(int),cmp);
	}
	else/*(type==BENCH_QUICKSORT) (defaults)*/
	{
		quickSort(tb_copy,0,size-1);
	}
	time=clock()-time;
	free(tb_copy);
	return ((double)time)/(double)CLOCKS_PER_SEC;
}

int main()
{
	double min[2]={INFINITY,INFINITY};
	double max[2]={0.0,0.0};
	double avg[2]={0.0,0.0};
	double tmp[2];
	int test_sizes[TEST_SIZES_AMT] = {5000,10000,50000,600000};
	for(int i=0;i<TEST_SIZES_AMT;++i)
	{
		for(int i=0;i<2;++i)
		{
			min[i]=INFINITY;
			max[i]=0.0;
			avg[i]=0.0;
		}
		printf("Test size: %d\n",test_sizes[i]);
		int* unsorted=(int*)malloc(sizeof(int)*test_sizes[i]);
		clock_t time=clock();
		for(int j=0;j<TEST_AMT;++j)
		{
			fillWithRandomSequence(unsorted,test_sizes[i]);
			tmp[0]=performTest(unsorted,test_sizes[i],BENCH_QSORT);
			tmp[1]=performTest(unsorted,test_sizes[i],BENCH_QUICKSORT);
			for(int i=0;i<2;++i)
			{
				if(min[i]>tmp[i])
					min[i]=tmp[i];
				if(max[i]<tmp[i])
					max[i]=tmp[i];
				avg[i]+=tmp[i];
			}
		}
		free(unsorted);
		avg[0]/=TEST_AMT;
		avg[1]/=TEST_AMT;
		time=clock()-time;
		double elapsed=((double)time/(double)CLOCKS_PER_SEC);
		printf("qsort: min: %f max: %f avg: %f\n",min[0],max[0],avg[0]);
		printf("quickSort: min: %f max: %f avg: %f\n",min[1],max[1],avg[1]);
		printf("total time for 100 tests (including time for array allocation): %f\n",elapsed);
	}
	return 0;
}