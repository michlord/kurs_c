/*
*Michal Zimniak
*Indeks: 258375
*Lista 5
*Zadanie 2
*To dziala dla n<=4
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
void writeArray(FILE *stream,int *tb,int size)
{
    for(int i=0;i<size;++i)
        fprintf(stream,"%d,",tb[i]);
    fprintf(stream,"\n");
}

int validateMagicSquare(int *tb,int row_size)
{
	int magic_sum=(row_size*(row_size*row_size+1))/2;
	for(int i=0;i<row_size;++i)
	{
		int sum=0;
		for(int j=0;j<row_size;++j)
		{
			int index=i*row_size+j;
			sum+=tb[index];
		}
		if(sum!=magic_sum)
			return 0;
	}
	for(int i=0;i<row_size;++i)
	{
		int sum=0;
		for(int j=0;j<row_size;++j)
		{
			int index=i+j*row_size;
			sum+=tb[index];
		}
		if(sum!=magic_sum)
			return 0;
	}
	{
		int sum=0;
		for(int i=0;i<row_size;++i)
		{
			int index=i*row_size+i;
			sum+=tb[index];
		}
		if(sum!=magic_sum)
			return 0;
	}
	{
		int sum=0;
		for(int i=0;i<row_size;++i)
		{
			int index=i*row_size+(row_size-i-1);
			sum+=tb[index];
		}
		if(sum!=magic_sum)
			return 0;
	}
	return 1;
}

void writeMagicSquare(FILE *stream,int *tb,int row_size)
{
	for(int i=0;i<row_size;++i)
	{
		writeArray(stream,tb+i*row_size,row_size);
	}
}

char ch;
int A[100];
int B[100];
void magicPermute(int n,int size)
{
	for(int i=1;i<=size*size;++i)
		if(B[i]==0)
		{
			B[i]=1;A[n-1]=i;
			if(n%size==0)
			{
				int sum=0;
				for(int i=n-size;i<n;++i)
					sum+=A[i];
				if(sum==(size*(size*size+1))/2)
				{
					if(n<size*size)
						magicPermute(n+1,size);
					else
					{
						if(validateMagicSquare(A,size))
						{
							writeMagicSquare(stdout,A,size);
							while((ch=getchar())!='\n');
							ch=toupper(getchar());
							if(ch=='N')
								exit(0);
						}
					}
				}
			}
			else
			{
				magicPermute(n+1,size);
			}
			B[i]=0;
		}
}

int main()
{
    int size;scanf("%d",&size);
	magicPermute(1,size);
    return 0;
}
