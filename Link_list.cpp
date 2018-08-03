#include <iostream>
#include<stdlib.h>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *ptr=NULL,*head=NULL;
void insert_at_end(int data);
void insert_at_position(int pos,int data);
void delete_pos(int);
void reverse_list();
void display();
void reverse_print(node*);
void reverse_rec(node *);
void replace_node(int,int);
int main()
{
    int data,position,choice;
    node *p=NULL;
    a:
    cout<<"\nChoose any of following Operation"
        <<"\n1.Insert at the end of list"
        <<"\n2.Insert at position"
        <<"\n3.delete from particular position"
        <<"\n4.Replace any node"
        <<"\n5.Reverse the List"
        <<"\n6.Display List"
        <<"\n7.Print List in Reverse order"
        <<"\n8.exit\n";
    cin>>choice;
    switch(choice)
    {
        case 1:cout<<"\n enter data::";
               cin>>data;
               insert_at_end(data);
               goto a;
               break;
        case 2:cout<<"\n enter data:: ";
               cin>>data;
               cout<<"Enter position::";
               cin>>position;
               insert_at_position(position,data);
               goto a;
               break;
        case 3:cout<<"\nEnter Position::";
               cin>>position;
               delete_pos(position);
               goto a;
               break;
        case 4:cout<<"\nEnter Position::";
               cin>>position;
               cout<<"\n enter data:: ";
               cin>>data;
               replace_node(data,position);
               goto a;
               break;
        case 5://reverse_list();
               p=head;
               reverse_rec(p);
               goto a;
               break;
        case 6:display();
               goto a;
               break;
        case 7:p=head;
               cout<<"\nList In Reverse Order::";
               reverse_print(p);
               goto a;
               break;
        case 8:exit(0);
               break;
        default :
               cout<<"Invalid input";
               goto a;
    }


}
void insert_at_end(int data)
{
    node *p=NULL;
    p=new node;
    p->data=data;
    p->next=NULL;

    if(head==NULL)
        head=ptr=p;
    else
    {
    ptr->next=p;
    ptr=p;
    }
}
void display()
{
    node *p=NULL;
    p=head;
    if(p==NULL)
        cout<<"\nList is Empty";
    else
    {
    cout<<"\nList is::-> ";
    while(p!=NULL)
    {
        cout<<p->data<<" -> ";
        p=p->next;
    }
    }
}
void insert_at_position(int pos,int data)
{
    node *p=NULL,*pp=NULL;
    pp=new node;
    pp->data=data;
    p=head;
    int count=0;
    if(pos==0)
    {
        pp->next=head;
        head=pp;
        return;
    }
    while(count!=pos-1&&p!=NULL)
    {
        count++;
        p=p->next;
    }
    if(pos>count&&p==NULL)
    {
        cout<<"Invalid Input";
    }
    else
    {
        pp->next=p->next;
        p->next=pp;
    }

}

void delete_pos(int pos)
{
    int count=0;
    node *p=NULL,*q=NULL;
    p=head;
    if(p==NULL)
        cout<<"\nList is Empty";
    else
    {
        if(pos==0)
        {
            cout<<"Delete Element is::"<<head->data;
            delete p;
            head=head->next;
        }
        else
        {
            while(count!=pos-1&&p!=NULL)
            {
                  count++;
                  p=p->next;
            }
            if(p->next==NULL)
                  cout<<"\nInvalid Position";
            else
            {
            cout<<"Deleted Element is::"<<p->next->data;
            q=p->next;
            p->next=p->next->next;
            delete q;
            }
        }
    }

}
void replace_node(int data,int pos)
{
    int count=0;
    node *p=NULL;
    p=head;
    if(p==NULL)
        cout<<"\nList is Empty";
    else
    {
        while(pos!=count&&p!=NULL)
        {
            count++;
            p=p->next;
        }
        if(p==NULL)
            cout<<"\nInvalid Position";
        else
            p->data=data;
    }
}
void reverse_list()
{
    node *p=NULL,*temp=NULL,* prev=NULL;
    p=head;

    while(p!=NULL)
    {
        temp=p->next;
        p->next=prev;
        prev=p;
        p=temp;
    }
    head=prev;
    cout<<"\nReversed List::";
    display();
}
void reverse_print(node *p)
{
    if(p==NULL)
        return;
    reverse_print(p->next);
    cout<<" -> "<<p->data;
}
//reverse by recursion
void reverse_rec(node *p)
{
    if(p->next==NULL)
    {
        head=p;
        return;
    }
    reverse_rec(p->next);
    node *q=p->next;
    q->next=p;
    p->next=NULL;
}

