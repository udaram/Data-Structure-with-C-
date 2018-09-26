/*
*******************************
  Q.3::-Create two circular linked lists and find their maximum numbers. Merge the
two circular linked lists such that the maximum number of 2nd circular linked list
immediately follows the maximum number of the 1st circular linked list.
Input:
12 -> 28 -> 18 -> 25 -> 19 -> NULL
5 -> 24 -> 12 -> 6 -> 15 -> NULL
Output: 12 -> 28 -> 24 -> 12 -> 6 -> 15 -> 5 -> 18 -> 25 -> 19 -> NULL
*******************************
*/

#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node *link;
  
    //constructer
    node(int d)
    {
        data=d;
        link=NULL;
    }
};

class circularList
{
    public:
    node *head,*tail;
    public:
    //constructor
    circularList()
    {
        head=tail=NULL;
    }
    //functionn for insertion of elements circular List
    void insertIntoList(int element)
    {
        node *temp=new node(element);
        if(head==NULL)
        {
            tail=head=temp;
            temp->link=head;
        }
        else
        {
            temp->link=head;
            tail->link=temp;
            tail=temp;
        }
    }
    //function to dispaly circular List
    void display()    
    {
        node *temp=NULL;
        temp=head;
        if(head==NULL)
        {
            
            cout<<"Circular List is Empty!!!";
            return;
        }
        cout<<temp->data<<"->";
        temp=temp->link;
        while(temp!=head)
        {
            cout<<temp->data<<" -> ";
            temp=temp->link;
        }
    }
    /*function too merge to lists
    By finding the position of max term in each of the list 
    here we are merging them just by changing a few links  
    */ 
    void merge(node *max1,node *max2)
    {   node *temp1,*temp2;
        temp1=max1->link;
        temp2=max2;
        max1->link=max2;
        while(temp2->link!=max2)
        {
            temp2=temp2->link;
        }
        temp2->link=temp1;
    }
    //to get position of max element 
    node* maxElement()
    {
        node *temp=NULL,*p=NULL;
        p=head;
        temp=head->link;
        
        while(temp!=head)
        {
            if(temp->data > p->data)
               p=temp;
            temp=temp->link;
        }
        return p;
    }  
};

//int main()
int main()
{
    int choice,l,data;
    circularList c1,c2,c3;
    node *max1,*max2;
    while(1)
    {
        //List of operations
        cout<<"\nChoose Operation You whould like to perform"
            <<"\n1.Insertion in list"
            <<"\n2.Display List"
            <<"\n3.Merge two list"
            <<"\n4.Exit::::";
        cin>>choice;
        //switch to work according to user choice
        switch(choice)
        {
            case 1:cout<<"\nEnter element:";
                   cin>>data;
                   cout<<"In which list you want to insert element[1,2]::";
                   cin>>l;
                   if(l==1)
                   {
                       c1.insertIntoList(data);
                   }
                   else if(l==2)
                   {
                       c2.insertIntoList(data);
                   }
                   else
                   cout<<"Invalid List Choice!!!";
                   break;
            case 2:cout<<"\nList 1::";
                   c1.display();
                   cout<<"NULL";
                   cout<<"\nList 2::";
                   c2.display();
                   cout<<"NULL";
                   break;
            case 3:c1.maxElement();
                   max1=c1.maxElement();
                   max2=c2.maxElement();
                   c1.merge(max1,max2);
                   cout<<"\nList after Merge::";
                   c1.display();
                   break;
            case 4:exit(0);
            default:cout<<"\nINVALID CHOICE!!!!";
        }
    }    
    return 0;
}



