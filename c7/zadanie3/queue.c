#include <stdlib.h>
#include <math.h>
#include "queue.h"
Queue Queue_create()
{
	Queue tmp;
	tmp.head=0;
	tmp.tail=0;
	return tmp;
}
void Queue_free(Queue *q)
{
	if(Queue_isEmpty(q))
		return;
	Node *tmp_node=q->head;
	while(tmp_node!=0)
	{
		Node *next=tmp_node->next;
		free(tmp_node);
		tmp_node=next;
	}
	q->head=0;
	q->tail=0;
}
double Queue_pushEmpty(Queue *q,double val)
{
	Node *new_node=(Node*)malloc(sizeof(Node));
	new_node->val=val;
	new_node->prev=0;
	new_node->next=0;
	q->tail=new_node;
	q->head=new_node;
	return val;
}
double Queue_pushBack(Queue *q,double val)
{
	if(Queue_isEmpty(q))
		return Queue_pushEmpty(q,val);
	Node *back=q->tail;
	Node *new_node=(Node*)malloc(sizeof(Node));
	new_node->val=val;
	new_node->prev=back;
	new_node->next=0;
	back->next=new_node;
	q->tail=new_node;
	return val;
}
double Queue_pushFront(Queue *q,double val)
{
	if(Queue_isEmpty(q))
		return Queue_pushEmpty(q,val);
	Node *front=q->head;
	Node *new_node=(Node*)malloc(sizeof(Node));
	new_node->val=val;
	new_node->prev=0;
	new_node->next=front;
	front->prev=new_node;
	q->head=new_node;
	return val;
}
double Queue_popFrontVal(Queue *q)
{
	if(Queue_isEmpty(q))
		return NAN;
	double val=q->head->val;
	Node *next=q->head->next;
	if(next!=0)
	{
		free(q->head);
		q->head=next;
		next->prev=0;
	}
	else
	{
		free(q->head);
		q->head=0;
		q->tail=0;
	}
	return val;
}
double Queue_popBackVal(Queue *q)
{
	if(Queue_isEmpty(q))
		return NAN;
	double val=q->tail->val;
	Node *prev=q->tail->prev;
	if(prev!=0)
	{
		free(q->tail);
		q->tail=prev;
		prev->next=0;
	}
	else
	{
		free(q->tail);
		q->tail=0;
		q->head=0;
	}
	return val;
}
int Queue_isEmpty(Queue *q)
{
	if(q->head==0)
		return 1;
	return 0;
}