#include<stdio.h>                 // header file

#define SIZE 5                    // Global declaration
int stack[SIZE],top=-1,res;

int main()                        // Program starts from here
{
  int x,choice;
  do
  {
      printf("\n1.\tPUSH\n2.\tPOP\n3.\tPEEK\n4.\tSEARCH\n5.\tTRAVERSE\n6.\tEXIT");
      printf("\n Enter your choice = ");
      scanf("%d",&choice);
      switch(choice)
      {
        case 1:
          printf("\n Enter element to push/insert into the stack = ");
          scanf("%d",&x);
          push(x);
          break;
        case 2:
          pop();
          break;
        case 3:
          peek();
          break;
        case 4:
          printf("\n Enter element to search = ");
          scanf("%d",&x);
          search(x);
          break;
        case 5:
          traverse();
          break;
        case 6:
          exit(0);
      }
  } while(choice != 7);
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
    printf("\nThe deleted element is = %d",stack[top--]);
}

void peek()
{
  if(top == -1)
    printf("\nstack is empty : underflow");
  else
    printf("\nThe top element in stack is = %d",stack[top]);
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

void search(int x)
{
  if(top == -1)
    printf("\nstack is empty : underflow");
  else
  {
    for(int i=top ; i>=0 ; i--)
    {
      if(x == stack[i])
        printf("\nElement found at %d index",i);
    }
  }
}
