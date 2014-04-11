#include "fraction.h"
#include "math_utils.h"
#include <stdio.h>
FRACTION getFractionFromStream(FILE *stream)
{
	int n,d;
	int res=fscanf(stream,"%d/%d",&n,&d);
	if(res==1)
		return makeFractionFromInt(n,1);
	return makeFractionFromInt(n,d);
}
void writeFractionToStream(FILE *stream,FRACTION a)
{
	int n,d;
	n=getFractionNumerator(a);
	d=getFractionDenominator(a);
	if(d==1)
		fprintf(stream,"%d",n);
	else
		fprintf(stream,"%d/%d",n,d);
}
FRACTION makeFractionFromInt(int numerator,int denominator)
{
	if(denominator<0)
	{	
		numerator=-numerator; denominator=-denominator;
	}
	int g=gcd(numerator,denominator);
	numerator/=g;denominator/=g;
	FRACTION tmp=denominator;
	/*TODO: check correctness*/
	tmp|=((FRACTION)numerator)<<32;
	return tmp;
}
int getFractionNumerator(FRACTION a)
{
	/*TODO: check correctness*/
	return (int)(a>>32);
}
int getFractionDenominator(FRACTION a)
{
	return (int)a;
}
FRACTION addFraction(FRACTION a,FRACTION b)
{
	int e,f,g,h;
	e=getFractionNumerator(a);
	f=getFractionNumerator(b);
	g=getFractionDenominator(a);
	h=getFractionDenominator(b);
	/*TODO: use long long?*/
	int n,d;
	n=e*h+g*f;
	d=g*h;
	int k=gcd(n,d);
	n/=k;
	d/=k;
	return makeFractionFromInt(n,d);	
}
FRACTION subFraction(FRACTION a,FRACTION b)
{
	int e,f,g,h;
	e=getFractionNumerator(a);
	f=getFractionNumerator(b);
	g=getFractionDenominator(a);
	h=getFractionDenominator(b);
	/*TODO: use long long?*/
	int n,d;
	n=e*h-g*f;
	d=g*h;
	int k=gcd(n,d);
	n/=k;
	d/=k;
	return makeFractionFromInt(n,d);
}
FRACTION mulFraction(FRACTION a,FRACTION b)
{
	int e,f,g,h;
	e=getFractionNumerator(a);
	f=getFractionNumerator(b);
	g=getFractionDenominator(a);
	h=getFractionDenominator(b);
	/*TODO: use long long?*/
	int n,d;
	n=e*f;
	d=g*h;
	int k=gcd(n,d);
	n/=k;
	d/=k;
	return makeFractionFromInt(n,d);
}
FRACTION divFraction(FRACTION a,FRACTION b)
{
	int e,f,g,h;
	e=getFractionNumerator(a);
	f=getFractionNumerator(b);
	if(f==0)
		return 0;/*error*/
	g=getFractionDenominator(a);
	h=getFractionDenominator(b);
	/*TODO: use long long?*/
	int n,d;
	n=e*h;
	d=g*f;
	int k=gcd(n,d);
	n/=k;
	d/=k;
	return makeFractionFromInt(n,d);
}