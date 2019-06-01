/*
Given a string expression, write a program to examine whether the pairs and the orders of "{","}","(",")","[","]"
are correct in expression. For example, the program should print true for exp = "[()]{}{[()()]()}" and false for
exp = "[(])" using stack.
*
*   ALGORITHM
*
*  Traverse the expression string.
*  If the current character is a starting bracket then push it to stack.
*  If the current character is a closing bracket then pop from the stack and if the popped character is the matching
*     starting bracket then it's balanced, else parenthesis are not balanced.
*  After complete traversal, if there is some starting bracket left in stack then it's not balanced.
*/
#include<stdio.h>                 // header file

#define SIZE 5                    // Global declaration
int top=-1,res;
char stack[SIZE];

char match(char);
void push(char);
char pop();

int main()                        // Program starts from here
{
  char str[100],x,z;
  int flag = 0;
  gets(str);
  for(int i=0 ; str[i] ; i++)
  {
    if(str[i] == '[' || str[i] == '(' || str[i] == '{')
      push(str[i]);
    else if(str[i] == ']' || str[i] == ')' || str[i] == '}')
    {
      x = pop();
      z = match(x);
      if(z == str[i])
        continue;
      else
      {
        flag = 1;
        break;
      }
    }
  }
  if(top == -1 && flag != 1)
    printf("\nBalanced");
  else
    printf("\nNot Balanced");

}

char match(char c)
{
  switch(c)
  {
    case '{': return '}'; break;
    case '(': return ')'; break;
    case '[': return ']'; break;
    default : break;
  }
}

void push(char x)                            //modules/function of stack operations
{
  if(top>=SIZE-1)
    printf("\nstack is full : overflow");
  else
    stack[++top] = x;
}

char pop()
{
  if(top == -1)
    printf("\nstack is empty : underflow");
  else
  return  stack[top--];
}
