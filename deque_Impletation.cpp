/*
********************************************************************************************
  Q7.::-
  NOTE:-(b,c,d) part of Q7 are emplemented together in this programm file.
  (b) Write the code for the deque interface. That is, show the struct and function definitions
  (c) Write the code for the deque implementation. That is, show how the functions defined
  above will work.
  (d) Write a small client program to test whether your implementation works correctly.
********************************************************************************************
*/


#include<iostream>
using namespace std;
struct deque 
{
    int data;
    deque *next;
    deque *prev;
};

//function declarations
void insertFirst(int data);
void insertLast(int data);
int Removefirst();
int RemoveLast();
int first();
int last();
bool isEmpty();
void display();

deque *head=NULL,*tail=NULL;//Global object of sturct for deque
int size=0;//variable to track the size of Deque
//main() function
int main()
{
    int data, choice;
    char ch='y';

    while(ch=='y'||ch=='Y')
    {
        
        cout<<"\nChoose Any operation which would you like to perform:::"
            <<"\n1.Insertion At  Beganing of Deque"
            <<"\n2.Insertion At End of Deque"
            <<"\n3.Remove Element from Begining"
            <<"\n4.Remove element from end"
            <<"\n5.First Element"
            <<"\n6.Last Element"
            <<"\n7.Size of Deque"
            <<"\n8.Check empty ness of Deque"
            <<"\n9.Display the Deque"
            <<"\n10.exit::::::";
        cin>>choice;
        switch(choice)
        {
            
          case 1:cout<<"\nEnter the data:::"; 
                cin>>data;
                insertFirst(data);  //function call to insert data at begining of Deque 
                break;
         case 2:cout<<"\nEnter the data:::"; 
                cin>>data;
                insertLast(data);  //function call to insert data at End of Deque 
                break;
          case 3:cout<<"\nRemoved element is ::"<<Removefirst();//To remove element from begining 
                break;
          case 4:cout<<"\nRemoved element is ::"<<RemoveLast();//To remove element from end 
                break;
          case 5:cout<<"\nFirst Element ::"<<first(); //to get first element of Deque
                break;
          case 6:cout<<"\nLast Element ::"<<last(); //to get last element of Deque
                break;
          case 7:cout<<"\nSize of Deque::"<<size;//to get size of Deque
                break;
          case 8:cout<<"\nYour Deque is Empty::(1=TRUE,0=FALSE)::"<<isEmpty();   //check emptyness of Deque
                break;
          case 9:cout<<"\nDeque is ::";
                display();
                break;    
          case 10:exit(0);  //to exit from  the program
          default:cout<<"\nINVALID CHOICE";  //to handle exceptions like invalid choice
        }
    }     
   return 0; 
}

//function definition to inser at the begining of Deque
void insertFirst(int data)
{
    deque *temp=new deque;//creating a node
    temp->data=data;
    temp->next=NULL;
    temp->prev=NULL;
    //if Deque is empty make head and tail pointing to temp otherwise change the links and make new head = temp;
    if(head == NULL)
    {
        head=tail=temp;
    }
    else
    {
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
    size++;//increase the size of Deque by +1
}

//function to insert  at end of deque 
void insertLast(int data)
{
    deque *temp=new deque;//creating a node
    temp->data=data;
    temp->next=NULL;
    temp->prev=NULL;
    //if Deque is empty make head and tail pointing to temp otherwise change the links and make new tail= temp;
    if(tail == NULL)
    {
        head=tail=temp;
    }
    else
    {
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
    }
    size++;//increase the size of Deque by +1
}

//Function definition to remove first element 
int Removefirst()
{   //if Deque is empty through error
    if(head==NULL)
    {
        cout<<"Deque is empty!!!";
        return -1;
    }
    int element;//to store removed data
    element=head->data;
    head=head->next;
    head->prev=NULL;
    size--;//Decrease size by 1
    return element;
}
//Function definition to remove Last Element of Deque 
int RemoveLast()
{   //if Deque is empty through error
    if(tail==NULL)
    {
        cout<<"Deque is empty!!!";
        return -1;
    }
    int element;//to store removed data
    element=tail->data;
    tail=tail->prev;
    tail->next=NULL;
    size--;//Decrease size by 1
    return element;
}
    
//function to return first Element
int first()
{
    if(head==NULL)
    {
        cout<<"Deque is empty!!!";
        return -1;
    }
    return head->data;
}
//function to return last Element
int last()
{
    if(tail==NULL)
    {
        cout<<"Deque is empty!!!";
        return -1;
    }
    return tail->data;
}

//function to check emptyness of Deque
bool isEmpty()
{
    if(size==0)
        return true;
    return false;
}

//Function to diplay the Deque
void display()
{
    deque *temp=NULL;
    temp=head;
    if(temp == NULL)
    {
        cout<<"\nDeque is Empty!!";
        return;
    }    
    else
    while(temp!=NULL)
    {
        cout<<" <=> "<<temp->data;
        temp=temp->next;
    }
    cout<<"<=>";
}
