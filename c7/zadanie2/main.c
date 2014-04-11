#include <stdio.h>
#include <stdlib.h>
#include "list.h"
void quickSort(List *list)
{
	if(LISTisEmpty(list))
		return;
	double pivot=LISTpopFront(list);
	List lesser=LISTnewEmpty();
	List greater=LISTnewEmpty();
	while(LISTisEmpty(list)==0)
	{
		double current=LISTpopFront(list);
		if(current<=pivot)
		{
			LISTpushFront(&lesser,current);
		}
		else
		{
			LISTpushFront(&greater,current);
		}
	}
	quickSort(&lesser);
	quickSort(&greater);
	LISTpushBack(&lesser,pivot);
	*list=LISTjoin(&lesser,&greater);
}
void insertionSort(List *list)
{
	List sorted=LISTnewEmpty();
	while(LISTisEmpty(list)==0)
	{
		double current=LISTpopFront(list);
		LISTinsertSorted(&sorted,current);
	}
	*list=sorted;
	/*tutaj nie ma memory leak'a bo list i tak juz wskazuje na 0 jak jest puste*/
}
int main()
{
    int n;scanf("%d",&n);
	List list1=LISTnewEmpty();
	List list2=LISTnewEmpty();
	for(int i=0;i<n;++i)
	{
		double tmp;
		scanf("%lf",&tmp);
		LISTpushBack(&list1,tmp);
		LISTpushBack(&list2,tmp);
	}
	printf("Quicksort result:\n");
	quickSort(&list1);
	while(LISTisEmpty(&list1)==0)
	{
		double val=LISTpopFront(&list1);
        printf("%.2f ",val);
	}
	printf("\nInsertion sort result:\n");
	insertionSort(&list2);
	while(LISTisEmpty(&list2)==0)
	{
		double val=LISTpopFront(&list2);
        printf("%.2f ",val);
	}
    return 0;
}
