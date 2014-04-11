#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


/*--------------------THIS PART HANDLES READING EXPRESSION--------------*/
#define EXPR_BUFF_SIZE 2024
int expr_str_size=0;
char expr_str[EXPR_BUFF_SIZE];
int isValidExprChar(const char c)
{
	if(isdigit(c) || c=='(' || c==')' || c=='+' || c=='-' || c=='*' || c=='/')
		return 1;
	return 0;
}
void readExpr()
{
	int c;
	/*
	*this loop does some filtering on input, however if expression is
	*malformed it will not try to fix it
	*/
	while(((c=getchar())!=EOF) && expr_str_size<EXPR_BUFF_SIZE)
	{
		if(c==';')
			break;
		if(isValidExprChar(c))
			expr_str[expr_str_size++]=c;
	}
	expr_str[expr_str_size++]=0;
}
/*--------------------THIS PART HANDLES READING EXPRESSION--------------*/

/*--------------------THIS PART HANDLES CONVERTING EXPRESSION TO POSTFIX*/
/*INFO:
* Here postfix expression is not stored as a string but as a table 
* where single cell can contain whole number not just single digits.
*/
#define POSTFIX_STACK_LIMIT 2024
#define POSTFIX_NUMBER_T 0
#define POSTFIX_OPERATOR_T 1
typedef struct postfixCell
{
	int type;
	int val;
}POSTFIXCELL;
int stack_numbers_p=0;
POSTFIXCELL stack_numbers[POSTFIX_STACK_LIMIT];
int stack_operators_p=0;
int stack_operators[POSTFIX_STACK_LIMIT]={'s'}; /* has sentinel*/
int readIntFromStr(const char *str)
{
	int number;
	sscanf(str,"%d",&number);
	return number;
}
int getOperatorPrecedence(int op)
{
	if(op=='(' || op==')')
		return 2;
	if(op=='+' || op=='-')
		return 3;
	if(op=='*' || op=='/')
		return 5;
	return 1;
}
void makePostfixExpr()
{
	for(int i=0;i<expr_str_size-1;++i)
	{
		if(isdigit(expr_str[i]))
		{
			int number = readIntFromStr(expr_str+i);
			while(isdigit(expr_str[i]))
				++i;
			--i;
			/*handle new number*/
			POSTFIXCELL new_cell;
			new_cell.type=POSTFIX_NUMBER_T;
			new_cell.val=number;
			stack_numbers[stack_numbers_p++]=new_cell;
		}
		else
		{
			/*handle new operator*/
			int oper = expr_str[i];
			int precedence = getOperatorPrecedence(oper);
			if(oper == '(' || oper == ')')
			{
				if(oper == '(')
				{
					++stack_operators_p;
					stack_operators[stack_operators_p]=oper;
				}
				else
				{
					while(stack_operators[stack_operators_p]!='(')
					{
						POSTFIXCELL new_cell;
						new_cell.type=POSTFIX_OPERATOR_T;
						new_cell.val=stack_operators[stack_operators_p];
						stack_numbers[stack_numbers_p++]=new_cell;
						--stack_operators_p;
					}
					--stack_operators_p;
				}
				
			}
			else
			{
				while(precedence<=getOperatorPrecedence(stack_operators[stack_operators_p]))
				{
					POSTFIXCELL new_cell;
					new_cell.type=POSTFIX_OPERATOR_T;
					new_cell.val=stack_operators[stack_operators_p];
					stack_numbers[stack_numbers_p++]=new_cell;
					--stack_operators_p;
				}
				++stack_operators_p;
				stack_operators[stack_operators_p]=oper;
			}
		}
	}
	while(stack_operators_p!=0)
	{
		POSTFIXCELL new_cell;
		new_cell.type=POSTFIX_OPERATOR_T;
		new_cell.val=stack_operators[stack_operators_p];
		stack_numbers[stack_numbers_p++]=new_cell;
		--stack_operators_p;
	}
}
void printPostfix()
{
	for(int i=0;i<stack_numbers_p;++i)
	{
		if(stack_numbers[i].type==POSTFIX_NUMBER_T)
			printf("%d ",stack_numbers[i].val);
		else
			printf("%c ",(char)stack_numbers[i].val);
	}
}

/*--------------------THIS PART HANDLES CONVERTING EXPRESSION TO POSTFIX*/

/*--------------------CONVERTING POSTFIX TO EXPRESSION TREE-------------*/
typedef struct bet
{
	int val;
	struct bet *left;
	struct bet *right;
} BET;
#define STACK_LIMIT 2024
BET* build_stack[STACK_LIMIT];
int build_stack_p=0;
void convertPostfixToBET()
{
	for(int i=0;i<stack_numbers_p;++i)
	{
		POSTFIXCELL tmp_cell = stack_numbers[i];
		if(tmp_cell.type==POSTFIX_NUMBER_T)
		{
			BET* tmp_bet=(BET*)malloc(sizeof(BET));
			tmp_bet->val=tmp_cell.val;
			tmp_bet->left=0;
			tmp_bet->right=0;
			build_stack[build_stack_p++]=tmp_bet;
		}
		else
		{
			BET* left_bet = build_stack[build_stack_p-2];
			BET* right_bet = build_stack[build_stack_p-1];
			build_stack_p-=2;
			BET* tmp_bet=(BET*)malloc(sizeof(BET));
			tmp_bet->val=tmp_cell.val;
			tmp_bet->left=left_bet;
			tmp_bet->right=right_bet;
			build_stack[build_stack_p++]=tmp_bet;			
		}		
	}
	/*BET should be at build_stack[0]*/
}

void printBET(BET * r,int space)
{
	if(r->left!=0)
	{
		printf("(%c ",r->val);
		printBET(r->left,1);
		printBET(r->right,0);
	}
	else
	{
		printf("%d",r->val);
		if(space)
			printf(" ");
	}
	if(r->left!=0)
	{
		printf(")");
	}
}

/*--------------------CONVERTING POSTFIX TO EXPRESSION TREE-------------*/


int main()
{

	readExpr();
	//printf("%s",expr_str);
	makePostfixExpr();
	//printf("\n");
	//printPostfix();
	//printf("\n");
	convertPostfixToBET();
	printBET(build_stack[0],0);
	
    return 0;
}
