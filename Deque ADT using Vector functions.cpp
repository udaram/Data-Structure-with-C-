/* 
***********************************************
Q.4:Implement the Deque ADT using Vector functions
***********************************************
*/
#include<iostream>
#include<vector>
using namespace std;
void display(vector<int>v);
int main()
{
    vector<int> deque;
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
                deque.insert(deque.begin(),data);  //function call to insert data at begining of Deque 
                break;
         case 2:cout<<"\nEnter the data:::"; 
                cin>>data;
                deque.push_back(data);  //function call to insert data at End of Deque 
                break;
          case 3:cout<<"\nElement has been Removed";
                deque.erase(deque.begin());//To remove element from begining 
                break;
          case 4:cout<<"\nElement has been Removed";
                deque.pop_back();//To remove element from end 
                break;
          case 5:cout<<"\nFirst Element ::"<<deque.front(); //to get first element of Deque
                break;
          case 6:cout<<"\nLast Element ::"<<deque.back(); //to get last element of Deque
                break;
          case 7:cout<<"\nSize of Deque::"<<deque.size();//to get size of Deque
                break;
          case 8:cout<<"\nYour Deque is Empty::(1=TRUE,0=FALSE)::"<<deque.empty();   //check emptyness of Deque
                break;
          case 9:cout<<"\nDeque is ::";
                display(deque);
                break;    
          case 10:exit(0);  //to exit from  the program
          default:cout<<"\nINVALID CHOICE";  //to handle exceptions like invalid choice
        }
    }     
   return 0; 
}
//display function to dispaly the deque 
void display(vector<int>v)
{
    vector<int>::iterator vec=v.begin();
    while(vec != v.end())
    {
        cout<<"->"<<*vec;
        vec++;
    }
}

