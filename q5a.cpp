/*
***************************************************************************************
Q5.Given a Binary tree and a number N, write a program to find the N-th node in the
Postorder traversal of the given Binary tree.
NOTE:-Here I have entered a tree user need not to enter that only for the sack of simplicity.
***************************************************************************************
*/

#include<iostream>
using namespace std;

struct node{
   int data;
   node * left,*right;
};

//function declarations

node* create_node(int data);
void node_post(node *root,int n);
int main()
{
     int N;
     node *root=NULL,*temp=NULL;
     temp=create_node(1);
     //first element in tree
     root=temp;
     temp=create_node(2);
     root->left=temp;
     
     temp=create_node(5);
     root->left->right=temp;
     
     temp=create_node(4);
     root->left->left=temp;
     
     temp=create_node(9);
     root->left->left->right=temp;
     
     temp=create_node(8);
     root->left->left->left=temp;
     
     temp=create_node(3);
     root->right=temp;
     
     temp=create_node(6);
     root->right->left=temp;
     
     temp=create_node(7);
     root->right->right=temp;
     
     /*
     prentered tree looks like this
                     1
                   /   \
                  2     3
                 / \   /  \
                4   5 6    7
              /   \
             8     9
     */
     
     cout<<"\nWhich node you would like to print in postorder traversal of given tree::";
     cin>>N;
     node_post(root,N);
     
     return 0;
}

//function to create a node 
node* create_node(int data)
{
     node *p=new node;
     p->data=data;
     p->left=p->right=NULL;
     return p;
}

//function definition to find N-th node element in post-order traversal of binary-tree
void node_post(node *root,int n)
{
     static int f=0;
     if(root==NULL)
       return ;
     if(f<=n)
     {
       node_post(root->left,n);
       node_post(root->right,n);
       f++;
       if(n==f)
          cout<<"Element is::"<< root->data;
         
     }
}

