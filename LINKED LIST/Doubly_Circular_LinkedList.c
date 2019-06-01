#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next,*prev;
}*root,*p,*foot;

void create(int);
void insert_Beg(int);
void insert_Mid(int,int);
void insert_End(int);
void delete_Beg();
void delete_Mid(int);
void delete_End();
void search(int);
void count();
void traverse_LR();
void traverse_RL();
void modify(int,int);
struct node *find(int);
struct node *find_previous(int);


int main()
{
  int x,ch,position;
  while(1)
  {
      printf("\n\n1.  CREATE");
      printf("\n2.  INSERT AT BEGNING");
      printf("\n3.  INSERT AT MIDDLE");
      printf("\n4.  INSERT AT END");
      printf("\n5.  DELETE AT BEGNING");
      printf("\n6.  DELETE AT MIDDLE");
      printf("\n7.  DELETE AT END");
      printf("\n8.  SEARCH");
      printf("\n9.  COUNT ELEMENT");
      printf("\n10. TRAVERSE LEFT TO RIGHT");
      printf("\n11. TRAVERSE RIGHT TO LEFT");
      printf("\n12. MODIFY");
      printf("\n13. EXIT");
      printf("\n\n \tEnter your choice = ");
      scanf("%d",&ch);
      switch(ch)
      {
        case 1:
            printf("\n\nEnter element to insert = ");
            scanf("%d",&x);
            create(x);
            break;
        case 2:
            printf("\n\nEnter element to insert = ");
            scanf("%d",&x);
            insert_Beg(x);
            break;
        case 3:
            printf("\n\nEnter element to insert = ");
            scanf("%d",&x);
            printf("\nEnter the position element to find it's address = ");
            scanf("%d",&position);
            insert_Mid(x,position);
            break;
        case 4:
              printf("\n\nEnter element to insert = ");
              scanf("%d",&x);
              insert_End(x);
              break;
        case 5:
              delete_Beg();
              break;
        case 6:
              printf("\nEnter the position element to find it's previous address = ");
              scanf("%d",&position);
              delete_Mid(position);
              break;
        case 7:
              delete_End();
              break;
        case 8:
              printf("\n\nEnter element to search = ");
              scanf("%d",&x);
              search(x);
              break;
        case 9:
              count();
              break;
        case 10:
              traverse_LR();
              break;
        case 11:
              traverse_RL();
              break;
        case 12:
              printf("\n\nEnter element to modify = ");
              scanf("%d",&x);
              printf("\nEnter the position element to find it's address = ");
              scanf("%d",&position);
              modify(x,position);
              break;
        case 13:
              exit(0);
      }
  }
  return 0;
}


void create(int element)
{
  root = (struct node *)malloc(sizeof(struct node));
  root->next = root;
  root->data = element;
  root->prev = root;
  foot = root;
}


void insert_Beg(int element) // wrong output
{

  if(root == NULL)
  {
    root = (struct node *)malloc(sizeof(struct node));
    root->next = root;
    root->data = element;
    root->prev = root;
    foot = root;
  }
  else
  {
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->next = root;
    temp->data = element;
    temp->prev = root->prev;
    root->prev = temp;
    foot->next = temp;
    root = temp;
  }
}


void insert_Mid(int element,int position)
{
  struct node *temp,*q;
  temp = (struct node *)malloc(sizeof(struct node));
  if(root == NULL)
    printf("\nList is empty : can't insert in middle");
  else                                                //be carefull we should not affect the root address, root address should always at 1st element.
  {
    q = find(position);
    temp->data = element;
    temp->next = q->next;
    temp->prev = q;
    q->next = temp;
  }
}


struct node *find(int position)
{
  p = root;
  while(p != NULL && p->data != position)
      p = p->next;
  return p;
}


void insert_End(int element)
{
  struct node *temp;
  temp = (struct node *)malloc(sizeof(struct node));
  if(root == NULL)
  {
    root = (struct node *)malloc(sizeof(struct node));
    root->next = NULL;
    root->data = element;
    root->prev = NULL;
  }
  else
  {
    p = root;
    while(p->next != root)
        p = p->next;
    p->next = temp;
    temp->data = element;
    temp->next = root;
    temp->prev = p;
    root->prev = temp;
    foot = temp;
  }
}


void delete_Beg()
{
  struct node *temp;
  temp = (struct node *)malloc(sizeof(struct node));
  if(root == NULL)
    printf("\nThe list is empty");
  else
  {
    temp = root;
    root = temp->next;
    root->prev = temp->prev;
    foot->next = root;
    printf("The deleted element is %d",temp->data);
    free(temp);
  }
}


void delete_Mid(int position)
{
  struct node *temp,*q;
  temp = (struct node *)malloc(sizeof(struct node));
  if(root == NULL)
    printf("\nList is empty");
  else
  {
    q = find_previous(position);
    temp = q->next;
    q->next = temp->next;
    temp->next->prev = q;
    printf("The deleted element is %d",temp->data);
    free(temp);
  }
}


struct node *find_previous(int position)
{
  p = root;
  while(p != NULL && p->next->data != position)
    p = p->next;
  return p;
}


void delete_End()
{
  struct node *temp;
  temp = (struct node *)malloc(sizeof(struct node));
  if(root == NULL)
    printf("\nThe list is empty");
  else
  {
    p = root;
    while(p->next->next != root)
        p = p->next;
    temp = p->next;
    p->next = temp->next;
    foot = p;
    root->prev = p;
    printf("The deleted element is %d",temp->data);
    free(temp);
  }
}


void search(int position)
{
  struct node *q;
  if(root == NULL)
    printf("\nThe list is empty");
  else
  {
    q = find(position);
    if(q != NULL)
      printf("\nElement found");
    else
      printf("\nElement not found");
  }
}


void traverse_LR()
{
  if(root == NULL)
    printf("\nThe list is empty");
  else
  {
    p = root;
    printf("\n");
    do
    {
      printf("%d  ",p->data);
      p = p->next;
    }while(p != root);
  }
}


void traverse_RL()
{
  if(root == NULL)
    printf("\nThe list is empty");
  else
  {
    p = root;
    printf("\n");
    while(p->next != root)
    {
      p = p->next;
    }
    do
    {
      printf("%d  ",p->data);
      p = p->prev;
    }while(p != foot);
  }
}

void count()
{
  int count=0;
  if(root == NULL)
    printf("\nThe list is empty");
  else
  {
    p = root;
    do
    {
      count++;
      p = p->next;
    }while(p != root);
    printf("\nThere are %d nodes in the linked list",count);
  }
}

void modify(int element,int position)
{
  struct node *q;
  if(root == NULL)
    printf("\nThe list is empty");
  else
  {
    q = find(position);
    if(q != NULL)
      q->data = element;
    else
      printf("\nNo such element is in the list");
  }
}
