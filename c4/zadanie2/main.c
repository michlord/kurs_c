#include <stdio.h>
#include "fraction.h"

int main()
{
	int t;
	FRACTION f1,f2;
	scanf("%d",&t);
	printf("n0\tn1\t+\t-\t*\t/");
	putchar('\n');
	for(int i=0;i<t;++i)
	{
		f1=getFractionFromStream(stdin);
		f2=getFractionFromStream(stdin);
		writeFractionToStream(stdout,f1);
		putchar('\t');
		writeFractionToStream(stdout,f2);
		putchar('\t');
		writeFractionToStream(stdout,addFraction(f1,f2));
		putchar('\t');
		writeFractionToStream(stdout,subFraction(f1,f2));
		putchar('\t');
		writeFractionToStream(stdout,mulFraction(f1,f2));
		putchar('\t');
		writeFractionToStream(stdout,divFraction(f1,f2));
		putchar('\n');
	}
	return 0;
}