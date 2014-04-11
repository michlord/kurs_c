#include <stdio.h>
#include <stdlib.h>
#include "list.h"
int main()
{
    List list=LISTnewEmpty();
    LISTpushFront(&list,1.0);
    LISTpushFront(&list,2.0);
    LISTpushFront(&list,3.0);
    LISTpushFront(&list,4.0);
    LISTpushFront(&list,5.0);
    LISTpushBack(&list,-1.0);
    LISTpushBack(&list,-2.0);
    LISTpushBack(&list,-3.0);
    LISTpushBack(&list,-4.0);
    printf("List length: %d\n",LISTlength(&list));
    while(LISTisEmpty(&list)==0)
    {
        double val=LISTpopFront(&list);
        printf("%.2f ",val);
    }
    putchar('\n');
    LISTpushFront(&list,1.0);
    LISTpushFront(&list,2.0);
    LISTpushFront(&list,3.0);
    printf("List length: %d\n",LISTlength(&list));
    while(LISTisEmpty(&list)==0)
    {
        double val=LISTpopFront(&list);
        printf("%.2f ",val);
    }
    putchar('\n');
    LISTpushBack(&list,1.0);
    LISTpushBack(&list,2.0);
    LISTpushBack(&list,3.0);
    LISTpushBack(&list,8.0);
    LISTpushBack(&list,10.0);
    printf("List length: %d\n",LISTlength(&list));
    while(LISTisEmpty(&list)==0)
    {
        double val=LISTpopFront(&list);
        printf("%.2f ",val);
    }
    putchar('\n');
    LISTinsertSorted(&list,9.0);
    printf("List length: %d\n",LISTlength(&list));
    while(LISTisEmpty(&list)==0)
    {
        double val=LISTpopFront(&list);
        printf("%.2f ",val);
    }
    putchar('\n');
    LISTpushBack(&list,1.0);
    LISTpushBack(&list,2.0);
    LISTpushBack(&list,3.0);
    LISTpushBack(&list,8.0);
    LISTpushBack(&list,10.0);
    LISTinsertSorted(&list,9.0);
    printf("List length: %d\n",LISTlength(&list));
    while(LISTisEmpty(&list)==0)
    {
        double val=LISTpopFront(&list);
        printf("%.2f ",val);
    }
    putchar('\n');
    LISTpushBack(&list,1.0);
    LISTinsertSorted(&list,9.0);
    printf("List length: %d\n",LISTlength(&list));
    while(LISTisEmpty(&list)==0)
    {
        double val=LISTpopFront(&list);
        printf("%.2f ",val);
    }
    putchar('\n');
    LISTpushBack(&list,10.0);
    LISTinsertSorted(&list,9.0);
    printf("List length: %d\n",LISTlength(&list));
    while(LISTisEmpty(&list)==0)
    {
        double val=LISTpopFront(&list);
        printf("%.2f ",val);
    }
    putchar('\n');

    List list2=LISTnewEmpty();
    LISTpushBack(&list,1.0);
    LISTpushBack(&list,4.0);
    LISTpushBack(&list,2.0);
    LISTpushBack(&list,7.0);
    LISTpushBack(&list,3.0);
    LISTpushBack(&list2,1.0);
    LISTpushBack(&list2,9.0);
    LISTpushBack(&list2,-1.0);
    LISTpushBack(&list2,-1.0);
    LISTpushBack(&list2,4.0);
    LISTpushBack(&list2,23.0);
    List list3=LISTcopy(&list2);
    list2=LISTjoin(&list,&list2);
    list=LISTjoin(&list2,&list3);
    printf("List length: %d\n",LISTlength(&list));
    while(LISTisEmpty(&list)==0)
    {
        double val=LISTpopFront(&list);
        printf("%.2f ",val);
    }
    putchar('\n');

    return 0;
}
