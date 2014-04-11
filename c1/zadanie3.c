/*
 *Lista 1
 *Zadanie 3
 *Michal Zimniak
 *258375
 *Na windowsie EOF robi siê jak siê wcisnie ctrl-Z
 */
#include <stdio.h>
#include <stdlib.h>


#define MAXROW 10
#define MAXCOL 10000
char buf[MAXCOL+MAXROW];
int p=0;



int main(void)
{
	int c;
	int beg=0,end=0,len=0,rows=1;
	int prevbeg=0;
	while((c=getchar())!=EOF)
	{
		buf[end++]=c;
		if(end>=MAXCOL+MAXROW)
			end=0;
		if(c!='\n')
			++len;
		else
		{
			prevbeg=beg;
			if(rows<MAXROW)
				++rows;
			else
			{
				while(buf[beg]!='\n')
				{
					++beg;
					if(beg>=MAXCOL+MAXROW)
						beg=0;
					--len;
				}
				++beg;
				if(beg>=MAXCOL+MAXROW)
					beg=0;
			}
		}
		if(len>MAXCOL)
		{
			printf("Dlugosc 10 kolejnych wierszy przekracza 10000 znakow\n");
			return 1;
		}
	}

	if(beg<end)
	{
		for(int i=prevbeg;i<end;++i)
			putchar(buf[i]);
	}
	else
	{
		for(int i=prevbeg;i<MAXCOL+MAXROW;++i)
			putchar(buf[i]);
		for(int i=0;i<end;++i)
			putchar(buf[i]);

	}


	return EXIT_SUCCESS;
}
