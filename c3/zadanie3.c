/*
Lista:
Zadanie:
Indeks:258375
Michal Zimniak
*/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


/*
*poly[0] defines polynomial size
*poly[k], where 0<k<MAX_POLY_SIZE is kth coefficient
*/

#define MAX_POLY_SIZE 2500
#define POLY_AMT 3
/*third poly is result*/
double poly[POLY_AMT][MAX_POLY_SIZE];

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define ABS(a)	 (((a)<0)?-(a):(a))

#define INDEX_DEG(d)  (MAX_POLY_SIZE-1-(int)(d))


void addPoly()
{ 	
	int maxdeg=MAX((int)poly[0][0],(int)poly[1][0]);
	int start=INDEX_DEG(maxdeg);
	poly[2][0]=maxdeg;
	for(int i=start;i<MAX_POLY_SIZE;++i)
		poly[2][i]=poly[0][i]+poly[1][i];
}
void subtractPoly()
{
	int maxdeg=MAX((int)poly[0][0],(int)poly[1][0]);
	int start=INDEX_DEG(maxdeg);
	for(int i=start;i<MAX_POLY_SIZE;++i)
		poly[2][i]=poly[0][i]-poly[1][i];
	for(int i=start;i<MAX_POLY_SIZE;++i)
	{
		if(ABS(poly[2][i])<0.00001)
		{
			--maxdeg;
		}
		else
		{
			break;
		}
	}
	poly[2][0]=maxdeg;
}
void multiplyPoly()
{
	int d1=(int)poly[0][0];
	int d2=(int)poly[1][0];
	int maxdeg=d1+d2;
	if(d1*d2==0)
		if(poly[0][INDEX_DEG(d1)]*poly[1][INDEX_DEG(d2)]==0)
			maxdeg=0;
	
	for(int i=INDEX_DEG((int)poly[0][0]);i<MAX_POLY_SIZE;++i)
	{
		for(int j=INDEX_DEG((int)poly[1][0]);j<MAX_POLY_SIZE;++j)
		{
			poly[2][INDEX_DEG(INDEX_DEG(i)+INDEX_DEG(j))]+=poly[0][i]*poly[1][j];
		}
	}
	poly[2][0]=maxdeg;
}
void dividePoly(int div_deg,double div_cof)
{
	int deg=(int)poly[0][0];
	/*shift all coefficients in poly[0] by div_deg*/
	for(int i=INDEX_DEG(0);i>=INDEX_DEG(deg);--i)
	{
		int k=i+div_deg;
		if(k<=INDEX_DEG(0))
		{
			poly[2][k]=poly[0][i]/div_cof;
		}
	}
	int new_deg=INDEX_DEG(INDEX_DEG(deg)+div_deg);
	if(new_deg<0)
		new_deg=0;
	poly[2][0]=new_deg;

}
void writeOutPoly(int n)
{
	if(n<0||n>POLY_AMT-1)
		return;
	printf("%d ",(int)poly[n][0]);
	for(int i=MAX_POLY_SIZE-1;i>INDEX_DEG((int)poly[n][0]);--i)
		printf("%.2f ",poly[n][i]);
	printf("%.2f",poly[n][INDEX_DEG((int)poly[n][0])]);
}
void clearPoly(int n)
{
	/*fill coefficient table with zeroes*/
	for(int i=0;i<MAX_POLY_SIZE;++i)
		poly[n][i]=0;	
}

int readPoly(int n)
{
	if(n<0||n>1)
	{
		printf("Error polynomial %d doesn't exist.\n",n);
		return 1;
	}
	if(scanf("%lf",&poly[n][0])==0)
	{
		printf("Error reading degree of polynomial %d.\n",n);
		return 1;
	}
	if(poly[n][0]>=MAX_POLY_SIZE)
	{
		printf("Error degree of polynomial %d is too high.\n",n);
		return 1;
	}
	/*
	*fill coefficients in following order:
	*constant term is placed at [MAX_POLY_SIZE-1]
	*other coefficients of degree n are at [MAX_POLY_SIZE-1-n]
	*/
	for(int i=MAX_POLY_SIZE-1;i>=INDEX_DEG((int)poly[n][0]);--i)
	{
		if(scanf("%lf",&poly[n][i])==0)
		{
			printf("Error reading polynomial coefficient.\n");
			return 1;
		}
	}
	return 0;
}


int main()
{
	char operation;
	int div_deg;
	double div_cof;
	while(scanf("%[-+*/]",&operation)!=EOF)
	{
		clearPoly(0);
		clearPoly(1);
		clearPoly(2);
		readPoly(0);
		if(operation!='/')
			readPoly(1);
		else
		{
			scanf("%d%lf",&div_deg,&div_cof);
		}
		switch(operation)
		{
			case '+' :
				addPoly();
				break;
			case '-' :
				subtractPoly();
				break;
			case '*' :
				multiplyPoly();
				break;
			case '/' :
				dividePoly(div_deg,div_cof);
				break;
		}
		writeOutPoly(2);
		
		char c;
		while((c=getchar())!='\n')
			if(c==EOF)	return 0;
		c=getchar();
			if(c==EOF)
				return 0;
		ungetc(c,stdin);
		putchar('\n');
	}
	return 0;
}