/*
 *Lista 1
 *Zadanie 2
 *Michal Zimniak
 *258375
 */

#include <stdio.h>
#include <stdlib.h>
#define LIMIT 10000

int main(void) {
	int n,m,r,rep=0;
	int number[LIMIT];
	int np=0;
	int repeating[LIMIT];
	int rp=0;
	scanf("%d%d",&n,&m);
	number[np++]=n/m;
	r=n%m;
	while(r!=0)
	{
		r*=10;
		for(int i=0;i<rp;++i)
		{
			if(repeating[i]==r)
			{
				rep=i+1;
				break;
			}
		}
		if(rep)
			break;
		repeating[rp++]=r;
		number[np++]=r/m;
		r-=(r/m)*m;
	}
	/*printf("%d\n",rep);*/
	printf("%d",number[0]);
	if(np>1)
		printf(",");
	if(rep)
	{
		for(int i=1;i<np;++i)
		{
			if(i==rep)
				printf("(");
			printf("%d",number[i]);
		}
		printf(")");
	}
	else
	{
		for(int i=1;i<np;++i)
			printf("%d",number[i]);
	}
	return EXIT_SUCCESS;
}
