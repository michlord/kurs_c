/*
*Michal Zimniak
*Indeks:258375
*Lista: 7
*Zadanie: 3
*/
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
void printQueue(Queue *q)
{
	if(Queue_isEmpty(q))
	{
		printf("Kolejka jest pusta\n");
		return;
	}
	Node *tmp_node=q->head;
	while(tmp_node!=0)
	{
		Node *next=tmp_node->next;
		printf("%.2f ",tmp_node->val);
		tmp_node=next;
	}
	printf("\n");
}
int main()
{
	printf("Dzialanie programu:\n"
			"c - oproznianie kolejki\n"
			"f [double] - dopisywanie liczby do kolejki z przodu\n"
			"przykladowo: f 1.23 dodaje 1.23 z przodu\n"
			"b [double] - dopisywanie liczby do kolejki z tylu\n"
			"x - pobieranie liczby z kolejki z przodu (i jej usuniecie)\n"
			"y - pobieranie liczby z kolejki z tylu (i jej usuniecie)\n"
			"e - sprawdzenie, czy kolejka jest pusta\n"	
			"p - wypisuje kolejke\n"
	);
	Queue q=Queue_create();
	char c;
	double a;
	while(scanf("%c",&c))
	{
		if(c=='c')
		{
			Queue_free(&q);
			printf("Kolejka oprozniona\n");
		}
		else if(c=='f')
		{
			scanf("%lf",&a);
			printf("Dodano %f\n",Queue_pushFront(&q,a));
		}
		else if(c=='b')
		{
			scanf("%lf",&a);
			printf("Dodano %f\n",Queue_pushBack(&q,a));
		}
		else if(c=='x')
		{
			a=Queue_popFrontVal(&q);
			printf("Usunieto %f\n",a);
		}
		else if(c=='y')
		{
			a=Queue_popBackVal(&q);
			printf("Usunieto %f\n",a);
		}
		else if(c=='e')
		{
			if(Queue_isEmpty(&q))
				printf("Kolejka jest pusta\n");
			else
				printf("Kolejka nie jest pusta\n");
		}
		else if(c=='p')
		{
			printQueue(&q);
		}
		else
        {
            fprintf(stderr,"BLAD wczytywania danych\n");
            return 1;
        }
		while(getchar()!='\n')
            ;
	}
    return 0;
}
