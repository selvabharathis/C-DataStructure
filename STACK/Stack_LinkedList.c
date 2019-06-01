#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
}*top,*top_duplicate;

void push(int);
void pop();
void peek();
void traverse();

int main()                        // Program starts from here
{
  int x,choice;
  while(1)
  {
      printf("\n1.\tPUSH\n2.\tPOP\n3.\tPEEK\n4.\tTRAVERSE\n5.\tEXIT");
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
          traverse();
          break;
        case 5:
          exit(0);
      }
    }
}



void push(int x)                                          // There is no overflow condition because of dynamic memory allocation.
{
  if(top == NULL)
  {
    top = (struct node *)malloc(sizeof(struct node));
    top->next = NULL;
    top->data = x;
  }
  else
  {
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->next = top;
    temp->data = x;
    top = temp;
  }
}

void pop()
{
  top_duplicate = top;
  if(top_duplicate == NULL)
    printf("\nThe stack is empty : UNDERFLOW\n");
  else
  {
    top_duplicate = top_duplicate->next;
    printf("\nThe deleted element is %d\n",top->data);
    free(top);
    top = top_duplicate;
  }
}

void peek()
{
  if(top->next == NULL)
    printf("\n Stack is empty : UNDERFLOW\n");
  else
    printf("\n The top element of the stack is = %d\n",top->data);
}

void traverse()
{
  top_duplicate = top;
  if(top_duplicate == NULL)
    printf("\n Stack is empty : UNDERFLOW\n");
  else
  {
    printf("\n");
    while(top_duplicate != NULL)
    {
      printf("%d  ",top_duplicate->data);
      top_duplicate = top_duplicate->next;
    }
    printf("\n");
  }
}
