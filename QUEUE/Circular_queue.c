#include<stdio.h>
#include<stdlib.h>

#define size 5

int queue[size],front=-1,rear=-1;

void enqueue(int);
void dequeue();
void traverse();

int main()
{
  int x,ch;
  printf("\n \t\t welcome to linear queue ADT ");
  while(1)
  {
    printf("\n 1.enqueue");
    printf("\n 2.dequeue");
    printf("\n 3.traverse");
    printf("\n 4.exit");
    printf("\n enter your choice=");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:
              printf("\n enter element to insert=");
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
      default:
              printf("\n invalid choice");
    }
  }
return 0;
}

void enqueue(int x)
{
  if(front == (rear+1)%size)
    printf("\n over flow");
  else
  {
    rear = (rear + 1) % size;
    queue[rear]=x;
    if(front==-1)
      front++;
  }
}

void dequeue()
{
  int res;
  if(front == -1)
    printf("\n under flow");
  else
  {
    res=queue[front];
    printf("\n the deleted element is..%d",res);
    if(rear==front)
    {
      front=-1;
      rear=-1;
    }
    else
      front = (front + 1) % size;
  }
}

void traverse()
{
  if(front==-1)
    printf("\n the list is empty");
  else
  {
    for(int i=front;i<=rear;i++)
    {
      printf("\n %d",queue[i]);
    }
  }
}
