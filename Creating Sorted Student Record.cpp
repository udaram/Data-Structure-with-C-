/*
*********************************************************************************
Q4.-
  NOTE::-
  1.In this program i am sorting the students by thier name during insertion.
    So user have to insert the name and programm will automatically sort it by name.
    For insertion i have defined the function like insertion at begining and 
    anywhere in list.i have used all these functions during sorting of list.
  2.Program is case sensitive so during entering name enter name either capital alphabet or small
    so that it can sort the names perfectly 
*********************************************************************************
*/
#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

//function definition
struct studNode* studentinfo();//function to get student studentinfo
void insertStudent(studNode*);//insert student list
void Studentlist();//function to display list of students
void search(string name);//search a student in a list
void deleteStudent(string name);//to delete student from list
//Struct definition
struct studNode
{
    
    string name;
    int age;
    string program;
    struct studNode * link;
};

studNode *head=NULL;//global objects of structure
int size=0; //to track the size of list of students
//Function main()
int main()
{
    studNode *p=NULL;
    int choice;
    string name;
    while(1)
    {   //choices for user
        cout<<"\nChoose Opretion you would like to perform"
            <<"\n1.Insert a student in list"
            <<"\n2.List of students::"
            <<"\n3.Search a student in list"
            <<"\n4.Delete a student"
            <<"\n5.exit:::::";
        cin>>choice;
        //switch to select users choice /oprartion whic he want to perform 
        switch(choice)
        {
            case 1:p=studentinfo();
                   insertStudent(p);
                   break;
            case 2:cout<<"\nLIST OF STUDENT ::";
                   Studentlist();
                   break;
            case 3:cout<<"\nEnter student name::";
                   cin>>name;
                   search(name);
                   break;
            case 4:cout<<"\nEnter name of student whom you want to delete from list::";
                   cin>>name;
                   deleteStudent(name);
                   cout<<"\nNew updated List of Student ::";
                   Studentlist();
                   break;
            case 5:exit(0);
            default :cout<<"\nINVALID CHOICE!!!!!";
        }
    }
    return 0;
}

//Function to get student data from user
studNode* studentinfo()
{
    studNode *temp=new studNode;
    cout<<"\nEnter Student data::";
    cout<<"\nNAME::";
    cin>>temp->name;
    cout<<"AGE::";
    cin>>temp->age;
    cout<<"PROGRAM::";
    cin>>temp->program;
    temp->link=NULL;
    
    return temp;
}
//insert student details in list in with sorting by name
void insertStudent(studNode *p)
{
    int f=0;
    studNode *temp=NULL;
    temp=head;
    if(head==NULL)
    {
        head=p;
        size++;
    }
    else if(p->name.compare(head->name)<0)
    {
        p->link=head;
        head=p;
    }
    else
    {
        while(f==0 && temp->link!=NULL)
        {
            if(p->name.compare(temp->name)==0)
            {
                p->link=temp->link;
                temp->link=p;
                f=1;  //counter that we found the position
                return;        
            }
            else if(p->name.compare(temp->link->name)<0)
            {
                p->link=temp->link;
                temp->link=p;
                f=1;   //counter that we found the position
                return;       
            }
            temp=temp->link;
        }
        temp->link=p;
    }
}
//to display student List
void Studentlist()
{
    studNode *temp=NULL;
    temp=head;
    if(temp==NULL)
    {
        cout<<"\nEmpty List!!!";
        return ;
    }
    int i=0;
    while(temp!=NULL)
    {
        cout<<"\n"<<++i<<"."<<temp->name;
        temp=temp->link;
    }
}
//search the student in list of students
void search(string name)
{
    studNode *temp=NULL;
    temp=head;
    if(head==NULL)
    {
        cout<<"Student Not Found";
        return;
    }
    while(temp!=NULL)
    {
        if(temp->name==name)
        break;
        temp=temp->link;
    }
    cout<<"\nNAME::"<<temp->name;
    cout<<"\nAGE::"<<temp->age;
    cout<<"\nPROGRAM::"<<temp->program;
    
}

//to delete student from list
void deleteStudent(string name)
{
    studNode *temp=NULL;
    temp=head;
    if(head==NULL)
    {
        cout<<"Student Not Found";
        return;
    }
    else
    if(head->name==name)
    {
        head=head->link;
        return;
    }
    else 
    {
        while(temp->link!=NULL)
        {
            if(temp->link->name==name)
            {
                temp->link=temp->link->link;
                
                return ;
            }
            temp=temp->link;
        }
        
    }
    cout<<"Student Not Found";
}

