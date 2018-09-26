/*
************************************************************
   Q5.Program to reverse a stack using recursion
   Your Stack is ::null <- 1 <- 2 <- 3 <- 4 <- 5 <- 6
   Stack after reverse::null<- 6 <- 5 <- 4 <- 3 <- 2 <- 1
************************************************************
*/   
#include<iostream>
#include<stdlib.h>
using namespace std;

//Declaration of node class 
class Node{
   public:
      char data;
      Node *next;
      Node(char data)
      {
         data=data;
         next=NULL;
      }    
};
class Stack{
   public:
   Node *top;
   Stack()
   {
      top=NULL;
   }   
   //Function to push element into the stack
   void push(char element)
   {
      //to create a new temporary Node
      Node *temp=new Node(element);  
      /*if stack is empty than we will point the top to new created node
      otherwise we will store the address of previous top in temp & then point the top to temp
      */
      temp->data =element;
      if(top == NULL)
         top=temp;
      else
      {
         temp->next=top;
         top=temp;
      }
   }
   //Function to display elements of stack
   void display(Node *p)
   {
      // if stack is EMPTY through a message "It is empty"
      if(p==NULL)
      {
      //cout<<"\nSTACK IS EMPTY";
         return;
      }
      //display stack elements one by one
      display(p->next);
      cout<<" <- "<<p->data;
   }
   //recursive function to reverse the stack 
   void reverse(Node* p)
   {
      Node* temp;
      if(p->next==NULL)
      {
         top=p;
         return;
      }
      reverse(p->next);
      temp=p->next;
      p->next=NULL;
      temp->next=p;
   }
   //function to check empty ness of stack
   bool isempty()
   {
      if(top==NULL)
         return true;
      return false;
   }
};
   
//Function main()    
int main()
{
   char data,ch='y';
   int choice;
   Stack s;//Declaration a object of class stack
   while(ch=='y'||ch=='Y')
   {
      cout<<"\nChoose Any operation which would you like to perform:::"
          <<"\n1.Insertion in stack"
          <<"\n2.Display stack"
          <<"\n3.reverse the stack"
          <<"\n4.check imptyness of Program"
          <<"\n5.exit::::::";
      cin>>choice;
      switch(choice)
      {
          case 1:cout<<"\nEnter the data:::"; 
                 cin>>data;
                 s.push(data);  //function call for push operation 
                 break;
          case 2:cout<<"\nYour Stack is ::null";
                 s.display(s.top);  //display a stack 
                 break;
          case 3:s.reverse(s.top);    //reverse of stack by recursion
                 cout<<"\nOperation has been Done successfully!!!!";
                 cout<<"\nStack after reverse::null";
                 s.display(s.top);
                 break;
          case 4:cout<<"\nYour stack is Empty::"<<s.isempty();   //check emptyness of stack
                 break;
          case 5:exit(0);  //to end the program
          default:cout<<"\nINVALID CHOICE";  //to handle exceptions like invalid choice
         
      }
   }     
   return 0;
}
