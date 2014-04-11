/*specjalnie malo, zeby wygodnie sie testowalo*/
#define Q_SIZE 8

#include <math.h>
#ifndef NAN
#define NAN (0.0/0.0)
#endif


typedef struct queue
{
    int front; /*inclusive*/
    int back; /*exclusive*/
    double tb[Q_SIZE];
} Queue;

void queueClear(Queue *q);
double queuePushBack(Queue *q,double val); /*returns NAN on error*/
double queuePopFront(Queue *q); /*returns NAN on error*/
int queueEmpty(Queue *q);
int queueFull(Queue *q);
