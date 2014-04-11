#include "list.h"
#include <math.h>
#include <stdlib.h>
List LISTnewEmpty()
{
    return (List)0;
}
Node* LISTpushFront(List *list,double val)
{
    if(LISTisEmpty(list))
    {
        *list=(List)malloc(sizeof(Node));
        (*list)->next=(*list);
        (*list)->val=val;
    }
    else
    {
        Node* tmp=(Node*)malloc(sizeof(Node));
        tmp->next=(*list)->next;
        tmp->val=val;
        (*list)->next=tmp;
    }
    return (*list)->next;
}
Node* LISTpushBack(List *list,double val)
{
    LISTpushFront(list,val);
    (*list)=(*list)->next;
    return *list;
}
double LISTpopFront(List *list)
{
    if(LISTisEmpty(list))
        return NAN;
    if((*list)==(*list)->next)
    {
        double val=(*list)->val;
        free((*list));
        (*list)=(List)0;
        return val;
    }
    else
    {
        double val=(*list)->next->val;
        Node* next=(*list)->next->next;
        free((*list)->next);
        (*list)->next=next;
        return val;
    }
}
double LISTfront(List *list)
{
    if(LISTisEmpty(list))
        return NAN;
    return (*list)->next->val;
}
double LISTisEmpty(List *list)
{
    if((*list)==0)
        return 1;
    return 0;
}
List LISTjoin(List *list1, List *list2)
{
    /*
    *to dziala tak:
    *list1 to np. 1, 3, 6
    *list2 to np. 7, 1
    *polaczenie to 1, 3, 6, 7, 1
    */
    if(LISTisEmpty(list1))
        return (*list2);
    if(LISTisEmpty(list2))
        return (*list1);
    Node* front=(*list1)->next;
    (*list1)->next=(*list2)->next;
    (*list2)->next=front;
    return (*list2);
}
List LISTcopy(List *list)
{
    if(LISTisEmpty(list))
        return LISTnewEmpty();
    List list2=LISTnewEmpty();
    Node* tmp=(*list)->next;
    LISTpushBack(&list2,tmp->val);
    Node* start=(*list);
    while(start!=tmp->next)
    {
        tmp=tmp->next;
        LISTpushBack(&list2,tmp->val);
    }
    LISTpushBack(&list2,start->val);
    return list2;
}
int LISTlength(List *list)
{
    if(LISTisEmpty(list))
        return 0;
    int counter=1;
    Node* tmp=*list;
    Node* start=tmp;
    while(start!=tmp->next)
    {
        ++counter;
        tmp=tmp->next;
    }
    return counter;
}
Node* LISTinsertSorted(List *list,double val)
{
    if(LISTisEmpty(list))
        return LISTpushFront(list,val);
	List root=*list;
	if(root->val<=val)
		return LISTpushBack(list,val);
	List tmp=root;
	while(tmp->next!=root)
	{
		if(tmp->next->val>val)
		{
			Node* tmp_node=(Node*)malloc(sizeof(Node));
			Node* next=tmp->next;
			tmp->next=tmp_node;
			tmp_node->val=val;
			tmp_node->next=next;
			return tmp_node;
		}
		tmp=tmp->next;
	}
	Node* tmp_node=(Node*)malloc(sizeof(Node));
	tmp->next=tmp_node;
	tmp_node->val=val;
	tmp_node->next=root;
	return tmp_node;
}
