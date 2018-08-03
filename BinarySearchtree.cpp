#include <iostream>
#include<stdlib.h>
#include<queue>
using namespace std;
struct node{
int data;
node* left;
node* right;
};
node* create_node(int);
node* insert_node(node*,int);
int find_min(node* root);
int find_max(node* root);
bool search_node(node *,int);
int height(node*);
void level_order_traversal(node* root);
void preorder(node*);
void inorder(node*);
void postorder(node*);
node* delete_node(node*,int);
int inorder_successor(node*,int);
node* find_inorder(node*,int);
int main()
{
    node *root=NULL;
    int ch,data;
    a:
    cout<<"\nchoose function"
        <<"\n1.Insertion"
        <<"\n2.Searching"
        <<"\n3.Max and Min element"
        <<"\n4.Height  of tree"
        <<"\n5.level order traversal"
        <<"\n6.Breadth order traversal"
        <<"\n7.Delete a node "
        <<"\n8.Inorder successor of data"
        <<"\n9.exit";
    cin>>ch;
    switch(ch)
    {
        case 1:cout<<"\nEnter the data::";
               cin>>data;
               root=insert_node(root,data);
               goto a;
        case 2:cout<<"\ndata to search";
               cin>>data;
               cout<<"\nNode found::"<<search_node(root,data);
               goto a;
        case 3:cout<<"\nMax is ::"<<find_max(root);
               cout<<"\nMin is ::"<<find_min(root);
               goto a;
        case 4:cout<<"\nhieght is::"<<height(root);
               goto a;
        case 5:cout<<"\nLevel order traversal::";
               level_order_traversal(root);
               goto a;
        case 6:cout<<"\nPreorder traversal:: ";
               preorder(root);
               cout<<"\nInorder traversal:: ";
               inorder(root);
               cout<<"\nPostorder traversal:: ";
               postorder(root);
               goto a;
        case 7:cout<<"\nEnter data to be deleted::";
               cin>>data;
               delete_node(root,data);
               goto a;
        case 8:cout<<"\nEnter data whose inorder successor you want to find out::";
               cin>>data;
               cout<<"\nInorder Successor of "<<data<<"is"<<inorder_successor(root,data);
               goto a;
        case 9:exit(0);
       default:cout<<"\ninvalid input";
                    goto a;
    }
    return 0;
}
node* create_node(int data)
{
    node* ptr=new node();
    ptr->data=data;
    ptr->left=ptr->right=NULL;
    return ptr;
}
node* insert_node(node* root,int data)
{
    if(root==NULL)
    {
        root=create_node(data);
    }
    else if(root->data>=data)
        root->left=insert_node(root->left,data);
    else
        root->right=insert_node(root->right,data);
    return root;
}
bool search_node(node*root,int data)
{
    if(root==NULL)
return false;
else
if(data>root->data)
    search_node(root->right,data);
else if(data<root->data)
    search_node(root->left,data);
else if(root->data==data)
    return true;

}
int find_min(node* root)
{
    if(root==NULL)
        return -1;
    else
    if(root->left==NULL)
        return root->data;
    else
        find_min(root->left);
}
int find_max(node* root)
{
    if(root==NULL)
        return -1;
    else
    if(root->right==NULL)
        return root->data;
    else
        find_max(root->right);
}
int height(node* root)
{
    if(root==NULL)
        return -1;
    return max(height(root->left),height(root->right))+1;
}
void level_order_traversal(node* root)
{
    if(root==NULL)return;
    queue<node*>s;
    s.push(root);
    while(!s.empty())
    {
        node* newnode=s.front();
        cout<<" "<<newnode->data;
        s.pop();
        if(newnode->left!=NULL)
            s.push(newnode->left);
        if(newnode->right!=NULL)
            s.push(newnode->right);
    }
}
void preorder(node* root)
{
    if(root==NULL)return;
    cout<<" "<<root->data;
    preorder(root->left);
    preorder(root->right);
}
void inorder(node* root)
{
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<" "<<root->data;
    inorder(root->right);
}
void postorder(node* root)
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<" "<<root->data;
}
node* delete_node(node* root,int data)
{
    if(root==NULL)
        return root;
    else if(data>root->data)
        root->right=delete_node(root->right,data);
    else if(data<root->data)
        root->left=delete_node(root->left,data);
    else
    {
        //no child
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            root=NULL;
            return root;
        }
        else if(root->left==NULL)   //only one child
        {
            node* temp=root;
            root=root->right;
            delete temp;
            return root;
        }
        else if(root->right==NULL)  //only child
        {
            node* temp=root;
            root=root->left;
            delete temp;
            return root;
        }
        else //two child
        {
            int num=find_min(root->right);
            root->data=num;
            root->right=delete_node(root->right,num);
            return root;
        }
    }
}

int inorder_successor(node* root,int data)
{
    node* current=find_inorder(root,data);
    if(current==NULL)
        return -1;
    if(current->right!=NULL)   //if right of cuurent node is not null
    {
        data=find_min(current->right);
        return data;
    }
    else   //if right of current node is null
    {
        node* successor=NULL;
        node* ancestor=root;
        while(ancestor!=current)
        {
            if(current->data<ancestor->data)
            {
                 successor=ancestor;
                 ancestor=ancestor->left;
            }
            else
                 ancestor=ancestor->right;
        }
        return successor->data;;
    }

}
//function to search node for which we want to find successor
node* find_inorder(node* root,int data)
{
    if(root==NULL)
        return root;
    if(root->data==data)
        return root;
    else if(data>root->data)
        find_inorder(root->right,data);
    else if(data<root->data)
        find_inorder(root->left,data);
}

