/*Micha³ Zimniak*/
/*258375*/
/*Lista A zadanie 5*/
#include <stdio.h>
#include <stdlib.h>

#define STBLIMIT 46341
#define PLIMIT 1000000
int pcount=0;
int primes[PLIMIT];
unsigned char tb[STBLIMIT];
void sieve()
{
    for(int i=0;i<STBLIMIT;++i)
      tb[i]=1;
    tb[0]=0;
    tb[1]=0;
    int j=2;
    for(int i=0;i<STBLIMIT;++i)
    {
        if(tb[i]==1)
        {
            j=i;
            for(int k=j*j;k<STBLIMIT;k+=j)
                tb[k]=0;
        }
    }

}

void gPrimes()
{
    for(int i=0;i<STBLIMIT;++i)
    {
            if(tb[i]==1)
                primes[pcount++]=i;
    }
}

int main()
{
    sieve();
    gPrimes();

    int n=1;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)
            break;
        if(n==1)
        {
            printf("1 NIE\n");
            continue;
        }
        for(int i=0;i<pcount;++i)
        {

            if((n%primes[i]) == 0 && n!=primes[i])
            {
                printf("%d NIE\n",n);
                //printf("prime: %d",primes[i]);
                break;
            }
            if(i==pcount-1)
                printf("%d TAK\n",n);

        }

    }

    return 0;
}
