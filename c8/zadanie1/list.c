#include "list.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

WNODE WLLC_newNode(int type,int val,WLLC sub)
{
	WNODE new_node;
	new_node.type=type;
	new_node.val=val;
	new_node.sub=sub;
	new_node.next=0;
	return new_node;
}
WLLC WLLC_newListFromString(const char *str)
{
	#define MAX_STACK_SIZE 10
	WLLC stack[MAX_STACK_SIZE];
	for(int i=0;i<MAX_STACK_SIZE;++i)
		stack[i]=0;
	int top=-1;
	for(int i=0;str[i]!=0;++i)
	{
		if(str[i]=='[')
		{
			++top;
		}
		else if(str[i]==']')
		{
			--top;
			if(top==-1)
				break;
			WNODE new_node = WLLC_newNode(T_SUB,1,stack[top+1]);
			WLLC_pushBack(&stack[top],new_node);
			stack[top+1]=0;
		}
		else if(isdigit(str[i]))
		{
			int number;
			sscanf(str+i,"%d",&number);
			while(isdigit(str[i]))
				++i;
			--i;
			WNODE new_node = WLLC_newNode(T_VAL,number,0);
			WLLC_pushBack(&stack[top],new_node);
		}
	}
	return stack[0];
	
}
WNODE* WLLC_pushFront(WLLC *list,WNODE node)
{
	WNODE *new_node=(WNODE*)malloc(sizeof(WNODE));
	*new_node=node;
	new_node->next=*list;
	(*list)=new_node;
	return new_node;
}
WNODE* WLLC_pushBack(WLLC *list,WNODE node)
{
	WNODE *new_node=(WNODE*)malloc(sizeof(WNODE));
	*new_node=node;
	//new_node->next=0;
	if(*list==0)
	{
		*list=new_node;	
		return new_node;
	}
	WNODE* tmp=*list;
	while(tmp!=0)
	{
		if(tmp->next==0)
		{
			tmp->next=new_node;
			break;
		}
		tmp=tmp->next;
	}
	return new_node;
}
WLLC WLLC_copy(WLLC list)
{
	WNODE* head=0;
	WNODE* tmp;
	while(list!=0)
	{
		if(head==0)
		{
			tmp=(WNODE*)malloc(sizeof(WNODE));
			head=tmp;
		}
		if(list->type==T_VAL)
		{
			WNODE new_node = WLLC_newNode(T_VAL,list->val,0);
			*tmp=new_node;
		}
		else if(list->type==T_SUB)
		{
			WLLC sublist = WLLC_copy(list->sub);
			WNODE new_node = WLLC_newNode(T_SUB,1,sublist);
			*tmp=new_node;
		}
		list=list->next;
		if(list!=0)
		{
			tmp->next=(WNODE*)malloc(sizeof(WNODE));
			tmp=tmp->next;
		}
		else
			tmp->next=0;
	}
	return head;
}
WLLC WLLC_merge(WLLC list1, WLLC list2)
{
	WLLC new_list1=0;
	WLLC new_list2=0;
	new_list1=WLLC_copy(list1);
	new_list2=WLLC_copy(list2);
	if(new_list2!=0)
		WLLC_pushBack(&new_list1,*new_list2);
	return new_list1;
}
WLLC WLLC_flat(WLLC list)
{
	WNODE* head=0;
	WNODE* tmp;
	while(list!=0)
	{
		if(head==0)
		{
			tmp=(WNODE*)malloc(sizeof(WNODE));
			head=tmp;
		}
		if(list->type==T_VAL)
		{
			WNODE new_node = WLLC_newNode(T_VAL,list->val,0);
			*tmp=new_node;
		}
		else if(list->type==T_SUB)
		{
			if(list->sub==0)
			{
				list=list->next;
				if(list==0)
					tmp->next=0;
				continue;
			}
			WLLC sublist = WLLC_flat(list->sub);
			WNODE new_node = *sublist;
			*tmp=new_node;
			while(tmp->next!=0)
				tmp=tmp->next;
			
		}
		list=list->next;
		while(list!=0&&list->type==T_SUB&&list->sub==0)
			list=list->next;
		if(list!=0)
		{
			tmp->next=(WNODE*)malloc(sizeof(WNODE));
			tmp=tmp->next;
		}
		else
			tmp->next=0;
	}
	return head;
}
void WLLC_print(WLLC list,FILE *stream)
{
	fprintf(stream,"[");
	while(list!=0)
	{
		if(list->type==T_VAL)
		{	
			fprintf(stream,"%d",list->val);
		}
		else if(list->type==T_SUB)
		{
			WLLC_print(list->sub,stream);
		}
		if(list->next!=0)
				fprintf(stream,",");
		list=list->next;
	}
	fprintf(stream,"]");
}