#include<stdio.h>
#include<stdlib.h>

struct queue
{
  int data;
  struct queue *next;
}*front,*rear,*q;     // we use front and rear for holding the address of nodes only, it cant hold the data and next of structure

void enqueue(int);
void dequeue();
void traverse();

int main()
{
  int x,ch;
  while(1)
  {
      printf("\n1.enqueue");
      printf("\n2.dequeue");
      printf("\n3.traverse");
      printf("\n4.exit");
      printf("\n\n\tenter your choice = ");
      scanf("%d",&ch);
      switch(ch)
      {
        case 1:
              printf("\n\nenter element to insert = ");
              scanf("%d",&x);
              enqueue(x);
              break;
        case 2:
              dequeue();
              break;
        case 3:
              traverse();
              break;
        case 4:
              exit(0);
              break;
        default:
              printf("\n\n........INVALID CHOICE........");
      }
  }
  return 0;
}

void enqueue(int x) // there is no overflow in linked list since dynamic memory allocation.
{
  struct queue *newnode;
  newnode = (struct queue *)malloc(sizeof(struct queue));
  if(q == NULL)
  {
    q = (struct queue *)malloc(sizeof(struct queue));
    q->data = x;
    q->next = NULL;
    front = q;
    rear = q;
  }
  else
  {
    newnode->data = x;
    newnode->next = NULL;
    rear->next = newnode;
    rear = newnode;
  }
}

void dequeue()
{
  if(front == NULL)
    printf("\nunderflow : no element is present in queue");
  else
  {
    if(front->next == NULL)
    {
      printf("\nthe deleted element is %d",front->data);
      front = NULL;
      rear = NULL;
    }
    else
    {
      struct queue *temp;
      temp = (struct queue *)malloc(sizeof(struct queue));
      temp = front;
      printf("\nthe deleted element is %d",temp->data);
      front = temp->next;
      free(temp);
    }
  }
}

void traverse()
{
  if(rear == NULL || front == NULL)
    printf("\nno element is present in queue");
  else
  {
    q = front;
    while(q != NULL)
    {
      printf("%d  ",q->data);
      q = q->next;
    }
  }
}
