#include "queue.h"

int incAndWrap(int val)
{
    ++val;
    if(val>=Q_SIZE)
        val=0;
    return val;
}

void queueClear(Queue *q)
{
    /*optionally zero out tb
    *for(int i=0;i<Q_SIZE;++i)
    *    q->tb[i]=0;
	*/
    q->front=0;
    q->back=0;
}
double queuePushBack(Queue *q,double val)
{
    if(queueFull(q))
		return NAN;
	q->tb[q->back]=val;
	q->back=incAndWrap(q->back);	
    return val;
}
double queuePopFront(Queue *q)
{
    if(queueEmpty(q))
		return NAN;
	int val=q->tb[q->front];
	q->front=incAndWrap(q->front);
    return val;
}
int queueEmpty(Queue *q)
{
    return q->front==q->back;
}
int queueFull(Queue *q)
{
	int tmp=incAndWrap(q->back);
	return tmp==q->front;
}
