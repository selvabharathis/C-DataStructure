#include<stdio.h>                 // header file

#define SIZE 50                    // Global declaration
int stack[SIZE],top=-1,res;

int main()                        // Program starts from here
{
  int x,choice,n,ele,pow=1,temp;
  scanf("%d",&n);
  temp = n;
  while(temp)
  {
    temp = temp / 10;
    pow = pow * 10;
  }
  pow = pow / 10;
  while(pow)
  {
    ele = n / pow ;
    push(ele);
    n = n % pow;
    pow = pow / 10;
  }
  traverse();

}

void push(int x)                            //modules/function of stack operations
{
  if(top>=SIZE-1)
    printf("\nstack is full : overflow");
  else
    stack[++top] = x;
}


void traverse()
{
  if(top == -1)
    printf("\nstack is empty : underflow");
  else
  {
    printf("\nReverse of the number is = ");
    for(int i=top ; i>=0 ; i--)
      printf("%d",stack[i]);
  }
}
