typedef struct node
{
    double val;
    struct node* next;
} Node, *List;
/* (mozna tez typedef Node* List) */

List LISTnewEmpty();
Node* LISTpushFront(List *list,double val);
Node* LISTpushBack(List *list,double val);
double LISTpopFront(List *list);
double LISTfront(List *list);
double LISTisEmpty(List *list);
List LISTjoin(List *list1, List *list2);
List LISTcopy(List *list);
int LISTlength(List *list);
Node* LISTinsertSorted(List *list,double val);
