#include<stdio.h>
#include<stdlib.h>
struct SLL
{
    int data;
    struct SLL *next;
};
struct SLL *first, *last = NULL;
void display()
{
    struct SLL *temp;
    if(first==NULL)
       printf("LIST IS EMPTY");
    else{
        temp=first;
        while(temp!=NULL)
        {
            printf("%d->", temp->data);
            temp=temp->next;
        }
        printf("NULL\n");
    }
}
void insert_at_beginning(int element)
{
  struct SLL *Newnode;
  Newnode=(struct SLL*)malloc(sizeof(struct SLL));
  Newnode->data=element;
  Newnode->next=NULL;
  if (first == NULL)
  {
    first=last=Newnode;
  }
  else{
    Newnode->next=first;
    first=Newnode;
  }
  printf("%d WAS INSERTED!\n",first->data);
}

void insert_at_end(int element)
{
  struct SLL *Newnode;
  Newnode = (struct SLL*)malloc(sizeof(struct SLL ));
  Newnode->data=element;
  Newnode->next=NULL;
  if (first == NULL)
  {
    first=last=Newnode;
  }
  else{
    last->next=Newnode;
    last=Newnode;
  }
  printf("%d WAS INSERTED AT THE END!\n",last->data);
}

void inesrt_at_specific_position(int element, int POS)
{
  struct SLL *Newnode, *temp;
  Newnode = (struct SLL*)malloc(sizeof(struct SLL ));
  Newnode->data=element;
  Newnode->next=NULL;
  int i;
  if(POS<=0)
  {
    printf("INVALID POSITION");
  }
  else if(POS==1 || first == NULL){
    insert_at_beginning(element);
  }
  else{
    temp=first;
    for(i=1;i<POS-1&&(temp->next!=NULL);i++)
    {
        temp=temp->next;
    }
    if(temp==last)
    {
        insert_at_end(element);
    }
    else{
     Newnode->next=temp->next;
     temp->next=Newnode;
    }
  }
  printf("%d WAS INSERTED!\n",Newnode->data);
}
void delete_from_beginning()
{
    struct SLL *temp;
    if(first == NULL)
     printf("LIST IS EMPTY!\n");
    else if(first->next==NULL){
        temp=first;
        first=last=NULL;
        printf("%d IS GOING TO BE DELETED!\n",temp->data);
        free(temp);
    }
    else{
        temp=first;
        first=first->next;
        printf("%d WAS DELETED!\n",temp->data);
        free(temp);
    }
    
}
void delete_from_end()
{
    struct SLL *temp;
    if(first == NULL)
     printf("LIST IS EMPTY!\n");
    else if(first->next==NULL){
        temp=first;
        first=last=NULL;
        printf("%d IS GOING TO BE DELETED!\n",temp->data);
        free(temp);
    }
    else{
        temp=first;
        while(temp->next!=last){
            temp=temp->next;
        }
        last=temp;
        temp=temp->next;
        printf("%d WAS DELETED!\n",temp->data);
        free(temp);
        last->next=NULL;
    }
}
void delete_at_specific_position(int POS)
{
    struct SLL *temp, *tempp;
    int i;
    if(POS<=0 || first==NULL)
    {
        printf("INVALID DELETION!");
    }
    else if(POS==1){
        delete_from_beginning();
    }
    else{
        temp=first;
        for(i=1;(i<POS-1)&&(temp->next!=last);i++)
        {
            temp=temp->next;
        }
        if(temp->next==last)
        {
            delete_from_end();
        }
        else{
            tempp=temp->next;
            temp->next= tempp->next;
            printf("%d WAS DELETED!\n",tempp->data);
            free(tempp);
        }
    }
}


int main()
{
    insert_at_beginning(10);
    insert_at_beginning(30);
    insert_at_beginning(23);
    insert_at_beginning(50);
    display();
    insert_at_end(20);
    insert_at_end(50);
    insert_at_end(200);
    insert_at_end(500);
    display();
    inesrt_at_specific_position(45,5);
    display();
    delete_from_beginning();
    display();
    delete_from_end();
    display();
    delete_at_specific_position(2);
    display();
    return 0;
}