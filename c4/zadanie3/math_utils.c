#include "math_utils.h"
int gcd(int a,int b)
{
	a=ABS(a);b=ABS(b);
	if(a<b){int t=a;a=b;b=t;}
	while(b)
	{
		int t=b;
		b=a%b;
		a=t;
	}
	return a;
}
