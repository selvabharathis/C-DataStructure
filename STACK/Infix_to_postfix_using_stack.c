/*
*   ALGORITHM
*
* If the input character is an operand, place it on to the output.
* If the character is an operator push it on to the output.
* If the stack operator has a higher or equal priority than input operator, then pop that operator from stack and place it on to output.
* If the character is left paranthesis, push it onto the stack.
* If the character is right paranthesis, pop all the operator from the stack till it encounter the left paranthesis.
* Discard the both paranthesis in the output.
*
*   EVALUATION ORDER
*
* Brackets or paranthesis
* Exponentiation
* Multiplication
* Division
* Addition
* Subtraction
*
*   EXAMPLE : A+(B*C-(D/E^F)*G)*H
*
*                 CHARACTER                     STACK                        OUTPUT
*
*                     A                                                        A
*
*                     +                         +                              A
*
*                     (                         +(                             A
*
*                     B                         +(                             AB
*
*                     *                         +(*                            AB
*
*                     C                         +(*                            ABC
*
*                     -                         +(-                            ABC*
*
*                     (                         +(-(                           ABC*
*
*                     D                         +(-(                           ABC*D
*
*                     /                         +(-(/                          ABC*D
*
*                     E                         +(-(/                          ABC*DE
*
*                     ^                         +(-(/^                         ABC*DE
*
*                     F                         +(-(/^                         ABC*DEF
*
*                     )                         +(-                            ABC*DEF^/
*
*                     *                         +(-*                           ABC*DEF^/
*
*                     G                         +(-*                           ABC*DEF^/G
*
*                     )                         +                              ABC*DEF^/G*-
*
*                     *                         +*                             ABC*DEF^/G*-
*
*                     H                         +*                             ABC*DEF^/G*-H
*
*                                               +                              ABC*DEF^/G*-H*
*
*                                                                              ABC*DEF^/G*-H*+
*
*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

#define SIZE 100



char stack[SIZE];
int top = -1;



void push(char item)
{
	if(top >= SIZE-1)
		printf("\nStack Overflow.");
	else
		stack[++top] = item;
}


char pop()
{
	char item ;

	if(top < 0)
	{
		printf("stack under flow: invalid infix expression");
		getchar();
    exit(1);
	}
	else
	{
		item = stack[top--];
		return item;
	}
}



int is_operator(char symbol)
{
	if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
		return 1;
	else
  	return 0;
}



int precedence(char symbol)
{
	if(symbol == '^')
		return(3);
	else if(symbol == '*' || symbol == '/')
		return(2);
	else if(symbol == '+' || symbol == '-')
		return(1);
	else
		return(0);
}


void InfixToPostfix(char infix_exp[], char postfix_exp[])
{
	int i, j;
	char item;
	char x;

	push('(');
	strcat(infix_exp,")");

	i=0;
	j=0;
	item=infix_exp[i];

	while(item != '\0')
	{
		if(item == '(')
			push(item);
		else if( isdigit(item) || isalpha(item))
			postfix_exp[j++] = item;
		else if(is_operator(item) == 1)
		{
			x=pop();
			while(is_operator(x) == 1 && precedence(x)>= precedence(item))
			{
				postfix_exp[j++] = x;
				x = pop();
			}
			push(x);
      push(item);
		}
		else if(item == ')')
		{
			x = pop();
			while(x != '(')
			{
				postfix_exp[j++] = x;
				x = pop();
			}
		}
		else
		{
			printf("\nInvalid infix Expression.\n");
			getchar();
			exit(1);
		}
		i++;
    item = infix_exp[i];
	}
	if(top>0)
	{
		printf("\nInvalid infix Expression.\n");
		getchar();
		exit(1);
	}
  postfix_exp[j] = '\0';
}


int main()
{
	char infix[SIZE], postfix[SIZE];
	printf("\nEnter Infix expression : ");
	gets(infix);
  InfixToPostfix(infix,postfix);
	printf("Postfix Expression: ");
	puts(postfix);

	return 0;
}
