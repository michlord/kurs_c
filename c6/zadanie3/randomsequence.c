#include <stdlib.h>
#include <time.h>

static const int kRandomRange=10000;

/*duzo to nie daje*/
unsigned long mix(unsigned long a, unsigned long b, unsigned long c)
{
    a=a-b;  a=a-c;  a=a^(c >> 13);
    b=b-c;  b=b-a;  b=b^(a << 8);
    c=c-a;  c=c-b;  c=c^(b >> 13);
    a=a-b;  a=a-c;  a=a^(c >> 12);
    b=b-c;  b=b-a;  b=b^(a << 16);
    c=c-a;  c=c-b;  c=c^(b >> 5);
    a=a-b;  a=a-c;  a=a^(c >> 3);
    b=b-c;  b=b-a;  b=b^(a << 10);
    c=c-a;  c=c-b;  c=c^(b >> 15);
    return c;
}

void fillWithRandomSequence(int *tb,int size)
{
	unsigned long seed = mix(clock(), time(0), time(0));
	srand(seed);
	for(int i=0;i<size;++i)
	{
		/*tb[i]=(int)((double)rand() / ((double)RAND_MAX + 1) * kRandomRange);*/
		tb[i]=rand()%kRandomRange;
		if(rand() < (RAND_MAX+1u) / 2)
			tb[i]*=-1;
	}
}