/*
Lista:2ver2
Zadanie:2
Indeks:258375
Michal Zimniak
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int max(int a,int b)
{
	return a<b?b:a;
}
void removeSpaces()
{
	int c;
	while((c=getchar())!=EOF)
	{
		if(c!='\t' && c!=' ')
		{
			ungetc(c,stdin);
			break;
		}
	}
}
int main(int argc,char *argv[])
{
    int n1,n2,numsize=0;
	int *numbers;
	int curword=1;
	int c;
    if(argc<=1)
	{
        printf("Usage: %s [number] or [number-number]",argv[0]);
		return 1;
	}
    else
    {
        for(int i=1;i<argc;++i)
        {
            int amt=sscanf(argv[i],"%d-%d",&n1,&n2);
            if(amt==1)
            {
				numsize=max(numsize,n1);
            }
            else
            {
				numsize=max(max(numsize,n1),n2);
            }
        }
		numbers=(int*)malloc(sizeof(int)*(numsize+1)); /*indexing from 1*/
		if(numbers==0)
			return 1;
		memset(numbers,0,sizeof(int)*(numsize+1));
		for(int i=1;i<argc;++i)
        {
            int amt=sscanf(argv[i],"%d-%d",&n1,&n2);
            if(amt==1)
            {
				numbers[n1]=1;
            }
            else
            {
				for(int i=n1;i<=n2;++i)
					numbers[i]=1;
            }
        }
		#if 0
		for(int i=0;i<=numsize;++i)
			printf("%d, ",numbers[i]);
		putchar('\n');
		#endif
    }
	while((c=getchar())!=EOF)
	{
		if(c=='\n')
		{
			curword=1;
			removeSpaces();
			putchar('\n');
		}
		else if(c=='\t' || c==' ')
		{
			removeSpaces();
			if(numbers[curword]==1)
				putchar(' ');
			++curword;
		}
		else if(numbers[curword]==1)
		{
			putchar(c);
		}
	}
	free(numbers);
    return 0;
}
