#include "set.h"

void clearSet(SET s)
{
    s[0]=0;
}
void unionSets(const SET s1,const SET s2,SET outcome)
{
    int size1=s1[0];
    int size2=s2[0];
    int i=1,j=1,k=1;
    while(i<=size1||j<=size2)
    {
        if(i>size1)
        {
            outcome[k]=s2[j++];
            ++k;
        }
        else if(j>size2)
        {
            outcome[k]=s1[i++];
            ++k;
        }
        else if(s1[i]<s2[j])
        {
            outcome[k]=s1[i++];
            ++k;
        }
        else if(s1[i]==s2[j])
        {
            /*discard duplicates*/
            ++j;
        }
        else
        {
            outcome[k]=s2[j++];
            ++k;
        }
    }
    outcome[0]=k-1;
}
void intersectSets(const SET s1,const SET s2,SET outcome)
{
	const int* s[2];
	s[0]=s1;
	s[1]=s2;
    if(s1[0]>s2[0])
    {
        s[0]=s2;
        s[1]=s1;
    }
    int p0=1,p1=1;
	int k=1;
	while(p0<=s[0][0])
	{
		while(p1<=s[1][0]&&s[1][p1]<s[0][p0])
			++p1;
		if(s[1][p1]==s[0][p0])
		{
			outcome[k++]=s[0][p0];
			++p1;
		}
		++p0;
	}
	outcome[0]=k-1;
    
}
void addElement(SET s,ELEMENT e)
{
    /*discard duplicates*/
    for(int i=1;i<=s[0];++i)
        if(s[i]==e)
            return;
    /*insert at the end*/
    s[0]+=1;
    int size=s[0];
    s[size]=e;
    /*somewhat simillar to insert sort but in O(n) time*/
    int k;
    for(int i=2;i<=size;++i)
    {
        k=i;
        while(k>1&&s[k]<s[k-1])
        {
            ELEMENT t=s[k];
            s[k]=s[k-1];
            s[k-1]=t;
            --k;
        }
    }
}
void deleteElement(SET s,ELEMENT e)
{
    int size=s[0];
    /*nothing can be found at zero because we are indexing at 1 so found is set to zero*/
    int found=0;
    for(int i=1;i<=size;++i)
    {
        if(s[i]==e)
            found=i;
    }
    if(found==0)
        return;
    for(int i=found;i+1<=size;++i)
    {
        s[i]=s[i+1];
    }
    s[0]-=1;
}
