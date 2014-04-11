#include <stdio.h>
#include <stdlib.h>
void swap(int *a,int *b)
{
	int t=*a;
	*a=*b;
	*b=t;
}

int partition(int *tb,int left,int right)
{
	int store=left;
	for(int i=left;i<right;++i)
	{
		if(tb[i]<tb[right])
		{
			swap(tb+i,tb+store);
			++store;
		}
	}
	swap(tb+right,tb+store);
	return store;
}
void quickSort(int *tb,int left,int right)
{
	if(left<right)
	{
		int pivot=partition(tb,left,right);
		quickSort(tb,left,pivot-1);
		quickSort(tb,pivot+1,right);
	}
}
int main()
{
	int size; scanf("%d",&size);
	int *tb=(int*)malloc(sizeof(int)*size);
	for(int i=0;i<size;++i)
	{
		scanf("%d",tb+i);
	}
	quickSort(tb,0,size-1);
	for(int i=0;i<size;++i)
	{
		printf("%d ",tb[i]);
	}
	free(tb);
	return 0;
}