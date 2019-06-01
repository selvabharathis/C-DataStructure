/*
you should reverse a stack but not using loop like while,for,etc..

The idea of the solution is to hold all values in function call stack until the stack becomes empty.
when the stack becomes empty, we insert all held items one by one at at bottom of the stack.
*/
#include<stdio.h>                 // header file

#define SIZE 50                    // Global declaration
int stack[SIZE],top=-1,res;

int main()                        // Program starts from here
{
  int n,a;
  printf("Enter how many element you want to enter to stack = ");
  scanf("%d",n);
  printf("Enter the elements\n");
  while(n--)
  {
    scanf("%d",a);
    push(a);
  }
  reverse();
  traverse();
}

void reverse()
{
  if(top != -1)
  {
    char x = peek();
    pop();
    reverse();
    insert(x);
  }
}
void insert(int x)
{
  if(top == 0)
    push(x);
  else
  {
    char a = peek();
    pop();
    insert(x);
    push(a);
  }
}
void push(int x)                            //modules/function of stack operations
{
  if(top>=SIZE-1)
    printf("\nstack is full : overflow");
  else
    stack[++top] = x;
}

void pop()
{
  if(top == -1)
    printf("\nstack is empty : underflow");
  else
    stack[top--];
}

int peek()
{
  if(top == -1)
    printf("\nstack is empty : underflow");
  else
    return stack[top];
}

void traverse()
{
  if(top == -1)
    printf("\nstack is empty : underflow");
  else
  {
    printf("\nelements present in stack are = ");
    for(int i=top ; i>=0 ; i--)
      printf("%d\t",stack[i]);
  }
}
