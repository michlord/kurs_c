/*
indeks:258375
Michal Zimniak
Zad 1
Lista 3
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int isPrime(long long int n)
{
	if(n==2)
		return 1;
    if(n<2)
        return 0;
    long long int s=(long long int)sqrtl((long double)n)+1;
    for(int i=2;i<=s;++i)
    {
        if(n%i==0)
            return 0;
    }
    return 1;
}

long long int* nextKPrimes(long long int n,int k)
{
    long long int* ptable=(long long int*)malloc((k+1)*sizeof(long long int));
    int p=0;
    for(long long int i=n+1;p<k;++i)
    {
        if(isPrime(i))
            ptable[p++]=i;
    }
    ptable[k]=0; /*jak null-terminated string*/
    return ptable;
}

int main()
{
    long long int n;
    int k;
    scanf("%I64d%d",&n,&k);
    long long int* nextPrimes=nextKPrimes(n,k);
    for(int i=0;i<k;++i)
    {
        printf("%I64d, ",nextPrimes[i]);
    }
    free(nextPrimes);
    return 0;
}
