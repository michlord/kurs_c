/*
*Michal Zimniak
*Indeks: 258375
*Lista 6
*Zadanie 1
*/
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
void printQueue(Queue *q)
{
    for(int i=0;i<Q_SIZE;++i)
    {
        if(i!=q->front&&i!=q->back)
            printf("%d\t",i);
        else if(i==q->front)
            printf("f\t");
        else
            printf("b\t");
    }
    printf("\n");
    for(int i=0;i<Q_SIZE;++i)
    {
        printf("%.2f\t",q->tb[i]);
    }
    printf("\n");
}
void printQueueContents(Queue *q)
{
	if(queueEmpty(q))
	{
		printf("Kolejka jest pusta\n");
		return;
	}
	if(q->front < q->back)
	{
		for(int i=q->front;i<q->back;++i)
			printf("%.2f\t",q->tb[i]);
	}
	else
	{
		for(int i=q->front;i<Q_SIZE;++i)
			printf("%.2f\t",q->tb[i]);
		for(int i=0;i<q->back;++i)
			printf("%.2f\t",q->tb[i]);			
	}
	printf("\n");
}
int main()
{
    Queue q;
    queueClear(&q);
	/*dla testowania bedzie wygodnie jak zapelni sie ja zerami*/
	for(int i=0;i<Q_SIZE;++i)
        q.tb[i]=0;
    printf("Program do testowania struktury typu kolejka.\n"
		   "Ta implementacja dla tablicy rozmiaru n (Q_SIZE=8) moze przechowac\n"
		   "maksymalnie n-1 elementow.\n"
		   "Front wskazuje na pierwszy element kolejki.\n"
		   "Back wskazuje na jeden element za ostatnim elementem.\n"
		   "Program interaktywny zaokragla double do dwoch miejsc po przecinku.\n"
           "Mozliwe operacje []:\n"
		   "[s] - wypisuje po kolei jedynie poprawne dane z kolejki\n"
           "[p] - wypisuje jak wyglada w pamieci kolejka\n"
           "[+ a] - dodaje element a\n"
           "[-] - zdejmuje element i go wypisuje (efekt jest taki, ze przesowa sie front)\n"
           "[e] - sprawdza czy kolejka jest pusta\n"
           "[c] - czysci kolejke\n"
           );
    char c;
    double a;
    while(scanf("%c",&c))
    {
		if(c=='s')
		{
			printQueueContents(&q);
		}
        else if(c=='+')
        {
            scanf("%lf",&a);
            printf("Dodaje %f\n",queuePushBack(&q,a));
        }
        else if(c=='p')
        {
            printQueue(&q);
        }
        else if(c=='-')
        {
            a=queuePopFront(&q);
            printf("Usunieto %f\n",a);
        }
        else if(c=='e')
        {
            if(queueEmpty(&q))
                printf("Kolejka jest pusta\n");
            else
                printf("Kolejka nie jest pusta\n");
        }
        else if(c=='c')
        {
            queueClear(&q);
            printf("Kolejka wyczyszczona\n");
        }
        else
        {
            fprintf(stderr,"BLAD - ten program jest dosyc glupi i wymaga zeby wpisane dane byly poprawne.");
            return 1;
        }
        while(getchar()!='\n')
            ;
    }
    return 0;
}
