/*program testuje funkcje sumy,przekroju, usuwania i czyszczenia*/


#include <stdio.h>
#include <stdlib.h>
#include "set.h"

int main()
{
    int tmp_set_size;
    int tmp_number;
    SET s[2];
    SET outcome_union,outcome_intersect;
	/*CZYSZCZENIE*/
    clearSet(s[0]);clearSet(s[1]);clearSet(outcome_union);clearSet(outcome_intersect);
    for(int i=0;i<2;++i)
    {
        printf("Set %d size: ",i);
        scanf("%d",&tmp_set_size);
        printf("Space delimited set elements: ");
        for(int j=0;j<tmp_set_size;++j)
        {
            scanf("%d",&tmp_number);
            addElement(s[i],tmp_number);
        }
    }
	printf("\n");
    for(int j=0;j<2;++j)
    {
        printf("Set %d: ",j);
        for(int i=1;i<=s[j][0];++i)
            printf("%d, ",s[j][i]);
        printf("\n");
    }
	
	/*SUMOWANIE*/

    printf("Summing provided sets...\n");
    unionSets(s[0],s[1],outcome_union);
    printf("Result: ");
    for(int i=1;i<=outcome_union[0];++i)
            printf("%d, ",outcome_union[i]);
    printf("\n");
	
	/*PRZEKROJ*/
	
	printf("Intersection of provided sets...\n");
	intersectSets(s[0],s[1],outcome_intersect);
	printf("Result: ");
    for(int i=1;i<=outcome_intersect[0];++i)
            printf("%d, ",outcome_intersect[i]);
    printf("\n");
	
	/*USUWANIE*/
	
	printf("Enter amount of elements to be deleted from set1:");
	int amt_del;
	scanf("%d",&amt_del);
	printf("Enter values of elements (space delimited):");
	while(amt_del--)
	{
		int tmp_val;scanf("%d",&tmp_val);
		deleteElement(s[0],tmp_val);
	}
	printf("Result: ");
	for(int i=1;i<=s[0][0];++i)
            printf("%d, ",s[0][i]);
	printf("\n");
	
	/*CZYSZCZENIE*/
	clearSet(s[1]);
	printf("Result of cleaning set 2: ");
	for(int i=1;i<=s[1][0];++i)
            printf("%d, ",s[1][i]);
	printf("\n");
	
	
    return 0;
}
