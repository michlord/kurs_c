typedef struct node
{
	double val;
	struct node *prev;
	struct node *next;
} Node;
typedef struct queue
{
	struct node *head;
	struct node *tail;
} Queue;
Queue Queue_create();
void Queue_free(Queue *q);
double Queue_pushBack(Queue *q,double val);
double Queue_pushFront(Queue *q,double val);
double Queue_popFrontVal(Queue *q);
double Queue_popBackVal(Queue *q);
int Queue_isEmpty(Queue *q);