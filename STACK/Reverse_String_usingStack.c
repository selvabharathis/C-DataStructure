#include<stdio.h>

#define SIZE 1000
char stack[SIZE][SIZE];
int top=0,res,right=-1;

int main()
{
  char str[1000];
  scanf("%[^\n]s",str);
  for(int i=0 ; str[i] ; i++)
    push(str[i]);
  traverse();

}

void push(char x)
{
  if(top>=SIZE-1)
    printf("\nstack is full : overflow");
  else
  {
    stack[top][++right] = x;
    if(x == ' ')
    {
      stack[top][++right] = '\0';
      right = -1;
      top++;
    }
  }
}




void traverse()
{
  if(top == 0)
    printf("\nstack is empty : underflow");
  else
  {
    printf("\nreverse of the string is = ");
    for(int i=top ; i>=0 ; i--)
      printf("%s ",stack[i]);
  }
}
