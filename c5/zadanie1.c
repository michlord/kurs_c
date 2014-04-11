/*
*Michal Zimniak
*Indeks: 258375
*Lista 5
*Zadanie 1
*/

#include <stdio.h>
#include <stdlib.h>

void writePermutation(FILE *stream,int *tb,int size)
{
    for(int i=0;i<size;++i)
        fprintf(stream,"%d,",tb[i]);
    fprintf(stream,"\n");
}

void makeFirstPermutation(int *tb,int size)
{
    for(int i=0;i<size;++i)
        tb[i]=i+1;
}

void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

int nextPermutation(int *tb,int size)
{
    if(size==1)
        return 0;
    if(tb[0]==size)
    {
        int t=tb[0];
        for(int i=1;i<size;++i)
            tb[i-1]=tb[i];
        tb[size-1]=t;
        return nextPermutation(tb,size-1);
    }
    for(int i=1;i<size;++i)
    {
        if(tb[i]==size)
        {
            swap(tb+i,tb+i-1);
            break;
        }
    }
    return 1;
}

int main()
{
    int counter=0;
    int size;scanf("%d",&size);
    int *tb=(int*)malloc(sizeof(int)*size);
    makeFirstPermutation(tb,size);
    do
    {
        ++counter;
        writePermutation(stdout,tb,size);
    }while(nextPermutation(tb,size));
    printf("Permutation count:%d",counter);
    free(tb);
    return 0;
}
