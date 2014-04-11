/*! @file */

#include <stdio.h>
 
/*! 
* @def T_VAL
* @brief Defines value type number.
*/
#define T_VAL 0
/*! 
* @def T_SUB
* @brief Defines sublist type number.
*/
#define T_SUB 1
typedef struct wllc 
{
	/*!defines type of node*/
	int type; 
	/*!value stored in node*/
	int val;
	/*!pointer to sublist*/
	struct wllc *sub;
	/*!pointer to next list node*/
	struct wllc *next;
} WNODE, *WLLC;
/*!
* @brief Creates new WLLC node.
*
* This is a convienience function that
* is meant to speed up list generation.
* @param either T_VAL or T_SUB	
* @param val when type=T_VAL then val represents 
* value stored in node
* @param sub when type=T_SUB then sub is a pointer
* to sublist which this node points to
* @return A new node.
*/
WNODE WLLC_newNode(int type,int val,WLLC sub);
/*!
* @brief Parses well-formatted string and creates WLLC.
*
* @param str a cstring formated like [[[3],[5,8],2],[1,5]]
* which represents a list to be created
* @return A new WLLC list.
*/
WLLC WLLC_newListFromString(const char *str);
/*!
* @brief Inserts a new node at the beggining of a list. 
*
* @param *list a pointer to WLLC
* @param node node to be inserted
* @return Pointer to inserted node.
*/
WNODE* WLLC_pushFront(WLLC *list,WNODE node);
/*!
* @brief Inserts a new node at the end of a list. 
*
* @param *list a pointer to WLLC
* @param node node to be inserted
* @return Pointer to inserted node.
*/
WNODE* WLLC_pushBack(WLLC *list,WNODE node);
/*!
* @brief Creates a copy of list.
*
* @param list a list to be copied
* @return New list which is copy of 'list'
*/
WLLC WLLC_copy(WLLC list);
/*!
* @brief Creates a list composed of list1 and list2
*
* @param *list1 a pointer to WLLC
* @param *list2 a pointer to WLLC
* @return New list.
*/
WLLC WLLC_merge(WLLC list1, WLLC list2);
/*!
* @brief Creates a list which is flattened 'list'
*
* List is no longer multilayered.
* @param *list a pointer to WLLC
* @return New list.
*/
WLLC WLLC_flat(WLLC list);
/*!
* @brief Prints out textual representation of a list to stream.
*
* @param list a list to be printed
* @param stream stream to which list is printed to
*/
void WLLC_print(WLLC list,FILE *stream);