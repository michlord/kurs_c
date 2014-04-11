#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void test1PushBackAndPushFront()
{
	/*pushback and pushfront test*/
	printf("pushBack and pushFront test:\n");
	WLLC list=0;
	WNODE new_node = WLLC_newNode(T_VAL,1,0);
	WNODE new_node1 = WLLC_newNode(T_VAL,2,0);
	WNODE new_node2 = WLLC_newNode(T_VAL,3,0);
	WLLC_pushBack(&list,new_node);
	WLLC_pushFront(&list,new_node);
	WLLC_pushFront(&list,new_node1);
	WLLC_pushFront(&list,new_node2);
	WLLC_pushBack(&list,new_node);
	WLLC_pushFront(&list,new_node1);
	WLLC_print(list,stdout);
	putchar('\n');
}
void test2ListFromString()
{
	/*make list from string test*/
	printf("make list from string test:\n");
	const int STR_AMT = 7;
	char list_string[7][200] = {"[9,2,[1,2],3,4,5]","[1,2,3]","[3,65,[3,4],5,[],43,[2,[3,4]]]","[]","[[[1],2]]","[1,2,3,[[2,3],[2]],4,3,2]","[[[[[]]]]]"};
	for(int i=0;i<STR_AMT;++i)
	{
		WLLC list_from_string=0;
		list_from_string = WLLC_newListFromString(list_string[i]);
		WLLC_print(list_from_string,stdout);
		putchar('\n');
	}
}

void test3MergeLists()
{
	/*list merge test*/
	printf("list merge test:\n");
	const int STR_AMT = 5;
	/*w C bledem jest zrobienie string1[STR_AMT][200] a w c++ nie*/
	char string1[5][200] = {"[3,1,5]","[2,[4,7],[]]","[]","[]","[9]"};
	char string2[5][200] = {"[2,[4,7],[]]","[3,1,5]","[[[1,2,[]]]]","[]","[[[1,2,[]]]]"};
	for(int i=0;i<STR_AMT;++i)
	{
		WLLC list1=0;
		WLLC list2=0;
		WLLC result=0;
		list1 = WLLC_newListFromString(string1[i]);
		list2 = WLLC_newListFromString(string2[i]);
		printf("Merging ");
		WLLC_print(list1,stdout); 
		printf(" with ");
		WLLC_print(list2,stdout);
		printf("\nResult: ");
		result = WLLC_merge(list1,list2);
		WLLC_print(result,stdout);
		putchar('\n');
	}
}

void test4FlattenList()
{
	printf("list flatten test:\n");
	const int STR_AMT = 14;
	char string1[14][200] = {"[[[3],[5,8],2]],[1,5]]","[3,1,5]","[2,[4,7],[]]","[]","[9]","[[[1,2,[]]]]","[9,2,[1,2],3,4,5]","[1,2,3]","[3,65,[3,4],5,[],43,[2,[3,4]]]","[]","[[[1],2]]","[1,2,3,[[2,3],[2]],4,3,2]","[[[[[]]]]]"};
	for(int i=0;i<STR_AMT;++i)
	{
		WLLC list1=0;
		WLLC result=0;
		list1 = WLLC_newListFromString(string1[i]);
		printf("Flattening ");
		WLLC_print(list1,stdout); 
		printf("\nResult: ");
		result = WLLC_flat(list1);
		WLLC_print(result,stdout);
		putchar('\n');
	}
}
int main()
{
	test1PushBackAndPushFront();
	test2ListFromString();
	test3MergeLists();	
	test4FlattenList();
    return 0;
}
