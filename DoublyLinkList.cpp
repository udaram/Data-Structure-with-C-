#include <iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    node *prev,*next;
};
node *head=NULL,*tail=NULL;
void insertion_at_end(int);
void display_rev();
void insertion_at_pos(int data,int pos);
void display();
void delete_node(int);
int main()
{   int data,choice,pos;
    A:
    cout <<"\nEnter your choice"
         <<"\n1.Insertion at end of list"
         <<"\n2.Insertion at position"
         <<"\n3.Deletion from position"
         <<"\n4.Display List in reverse order"
         <<"\n5.Display list"
         <<"\n6.Exit\n";
    cin>>choice;
    switch(choice)
    {
        case 1:cout<<"\nEnter the data to insert:";
               cin>>data;
               insertion_at_end(data);
               goto A;
        case 2:cout<<"\nEnter data::";
               cin>>data;
               cout<<"Enter Position::";
               cin>>pos;
               insertion_at_pos(data,pos);
               goto A;
        case 3:cout<<"\nEnter Position::";
               cin>>pos;
               delete_node(pos);
               goto A;
        case 4:display_rev();
               goto A;
        case 5:display();
               goto A;
        case 6:exit(0);
        default:cout<<"\nInvalid input";
               goto A;
    }
    return 0;
}
void insertion_at_end(int data)
{
    node *ptr=NULL;
    ptr=new node;
    ptr->data=data;
    if(head==NULL)
    {
        ptr->prev=ptr->next=NULL;
        head=tail=ptr;
    }
    else
    {
        tail->next=ptr;
        ptr->prev=tail;
        ptr->next=NULL;
        tail=ptr;
    }
}
void display()
{
    node *p=NULL;
    p=head;
    cout<<"\nList is::";
    if(p==NULL)
    {
        cout<<"\nList is Empty";
        return;
    }
    while(p!=NULL)
    {
        cout<<" -> "<<p->data;
        p=p->next;
    }
}
void display_rev()
{
    node *p=NULL;
    p=tail;
    cout<<"\nList is::";
    if(p==NULL)
    {
        cout<<"\nList is Empty";
        return;
    }
    while(p!=NULL)
    {
        cout<<" -> "<<p->data;
        p=p->prev;
    }
}
void insertion_at_pos(int data,int pos)
{
    node *p=NULL,*temp=NULL;
    p=head;
    temp=new node;
    temp->data=data;
    int count=0;
    if(pos==0)
    {
        temp->prev=NULL;
        head->prev=temp;
        temp->next=head;
        head=temp;
        return;
    }
    while(p!=NULL && count!=pos-1)
    {
        count++;
        p=p->next;
    }
    if(p==NULL||p->next==NULL)
    {
        cout<<"\nInvalid position";
    }
    else
    {
        temp->next=p->next;
        p->next->prev=temp;
        p->next=temp;
        temp->prev=p;
    }
}
void delete_node(int pos)
{
    int count=0;
    node *p=NULL,*q=NULL;
    p=head;
    if(p==NULL)
    {
        cout<<"\nList is Empty";
        return;
    }
    if(pos==0)
    {
        cout<<"\nDeleted data is::"<<head->data;
        head=head->next;
        head->prev=NULL;
        delete p;
        return;
    }
    while(p!=NULL && count!=pos-1)
    {
        count++;
        p=p->next;
    }
    if(p==NULL ||p->next==NULL)
    {
        cout<<"\nInvalid Position";
        return;
    }
    else
    if(p->next->next==NULL)
    {   cout<<"\nDeleted data is::"<<p->next->data;
        q=p->next;
        p->next=NULL;
        tail=p;
        delete q;
    }
    else
    {
        q=p->next->next;
        cout<<"\nDeleted data is::"<<p->next->data;
        p->next=q;
        q->prev=p;
    }
}

