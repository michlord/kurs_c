/*
*Michal Zimniak
*Indeks: 258375
*Lista 6
*Zadanie 2
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swapPtr(char ** p1, char ** p2)
{
	char *temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

/*
int cmpLessThan(char *s1, char *s2)
{
	return strcmp(s1,s2) < 0;
}
*/

int cmpGreaterThan(char *s1, char *s2)
{
	/*return strcmp(s1,s2) > 0;*/
	int c = strncmp(s1,s2,2);
	if(c==0)
	{
		c = strncmp(s1+4,s2+4,40);
	}
	return c > 0;
}

int partition(char **tb,int left,int right)
{
	int store=left;
	for(int i=left;i<right;++i)
	{
		if(cmpGreaterThan(tb[i],tb[right]))
		{
			swapPtr(tb+i,tb+store);
			++store;
		}
	}
	swapPtr(tb+right,tb+store);
	return store;
}
void quickSort(char **tb,int left,int right)
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
	char** tb =(char**)malloc(sizeof(char*)*10001);
	for(int i=0;i<10001;++i)
	{
		tb[i]=(char*)malloc(sizeof(char)*40);
	}
	int size=0;
	while(1)
	{
		char c;
		int p=0;
		while((c=getchar())!='\n'&&c!=EOF)
		{
			tb[size][p++]=c;
		}
		tb[size][p]=0;
		if(p!=0)
			++size;
		if(c==EOF)
			break;
	}
	quickSort(tb,0,size-1);
	for(int i=0;i<size-1;++i)
	{
		printf("%s\n",tb[i]);
	}
	printf("%s",tb[size-1]);
	/*
	Nie chce mi sie czyscic tablicy, niech zajmie sie tym system
	*/
	
	return 0;
}