#include<stdio.h>
#include<stdlib.h>

struct DLL
{
    int data;
    struct DLL*prev;
    struct DLL*next;
};
struct DLL*first,*last=NULL;

void display()
{
    struct DLL *temp;
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

void insert_at_the_beginning(int element)
{
    struct DLL *Newnode;
    Newnode=(struct DLL*)malloc(sizeof(struct DLL));
    Newnode->data=element;
    Newnode->prev=NULL;
    Newnode->next=NULL;
    if(first==NULL)
    {
        first=last=Newnode;
    }
    else{
        Newnode->next=first;
        first->prev=Newnode;
        first=Newnode;
    }
    printf("%d WAS INSERTED!\n",first->data);
}

int insert_at_the_end(int element)
{
    struct DLL *Newnode;
    Newnode=(struct DLL*)malloc(sizeof(struct DLL));
    Newnode->data=element;
    Newnode->prev=NULL;
    Newnode->next=NULL;
    if(first==NULL)
    {
        first=last=Newnode;
    }
    else{
        last->next=Newnode;
        Newnode->prev=last;
        last=Newnode;
    }
    printf("%d WAS INSERTED!\n",last->data);
}

int insert_at_the_specific_position(int element,int POS)
{
    struct DLL*Newnode, *temp, *tempp;
    int i;
    Newnode=(struct DLL*)malloc(sizeof(struct DLL));
    Newnode->data=element;
    Newnode->prev=NULL;
    Newnode->next=NULL;
    if(POS<=0)
    {
        printf("INVALID POSITION!");
    }
    else if(POS==1 || first==NULL)
        insert_at_the_beginning(element);
    else{
        temp=first;
        for(i=1;(i<POS-1)&&(temp->next!=NULL);i++)
    {
        temp=temp->next;
    }
    if(temp==last)
    {
        insert_at_the_end(element);
    }
    else{
        tempp=temp->next;
        temp->next=Newnode;
        Newnode->prev=temp;
        tempp->prev=Newnode;
        Newnode->next=tempp;
    }
    }
printf("%d WAS INSERTED!\n",Newnode->data);
}

void delete_from_beginning()
{
    struct DLL *temp;
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
        first->prev=NULL;
        printf("%d WAS DELETED!\n",temp->data);
        free(temp);
    }
}

void delete_from_end()
{
    struct DLL *temp;
    if(first == NULL)
     printf("LIST IS EMPTY!\n");
    else if(first->next==NULL){
        temp=first;
        first=last=NULL;
        printf("%d IS GOING TO BE DELETED!\n",temp->data);
        free(temp);
    }
    else{
        temp=last;
        last=temp->prev;
        last->next=NULL;
        printf("%d WAS DELETED!\n",temp->data);
        free(temp);
    }
}
void delete_at_specific_position(int POS)
{
    struct DLL *temp, *tempp;
    int i;
    if(POS<=0 || first==NULL)
    {
        printf("INVALID DELETION!");
    }
    else if(POS==1 || first->next==NULL){
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
            (tempp->next)->prev=temp;
            printf("%d WAS DELETED!\n",tempp->data);
            free(tempp);
        }
    }
}



int main()
{
    insert_at_the_beginning(20);
    insert_at_the_beginning(30);
    insert_at_the_beginning(40);
    display();
    insert_at_the_end(1);
    insert_at_the_end(2);
    insert_at_the_end(3);
    display();
    insert_at_the_specific_position(100,1);
    insert_at_the_specific_position(200,2);
    display();
    delete_from_beginning();
    display();
    delete_from_end();
    display();
    delete_at_specific_position(3);
    display();
    return 0;
}