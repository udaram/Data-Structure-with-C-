#include<iostream>
#include<list>
using namespace std;

class graph
{
   int vertices;  //no. of nodes/vertices
   list<int>*l;  //for adjency list
   public:
   graph(int vertices)
   {
       this->vertices=vertices;
       l=new list<int>[vertices];
   }
   
   void add_edge(int v,int w)
   {
       l[v].push_back(w);  //adding edge to graph
   }
   //startiing of traversal in  the graph
   void depth_first_search()
   {
       bool *visited=new bool[vertices];
       for(int i=0;i<vertices;i++)
       {
           visited[i]=false;
       }
       for(int i=0;i<vertices;i++)
          if(visited[i]==false)
             dfsutil(i,visited);
   }
   //recusive function to traverse the graph
   void dfsutil(int v,bool visited[])
   {
       visited[v]=true;
       cout<<v<<" ";
       list<int >::iterator i;
       for(i=l[v].begin();i!=l[v].end();i++)
         if(!visited[*i])
            dfsutil(*i,visited);
   }
   
};

int main()
{
    int n,v,w,choice;
    cout<<"Enter the size of Graph::";
    cin>>n;
    graph g(n);
    g.add_edge(0, 1); 
    g.add_edge(0, 2); 
    g.add_edge(1, 2); 
    g.add_edge(2, 0); 
    g.add_edge(2, 3); 
    g.add_edge(3, 3); 
  
    cout << "Following is Depth First Traversaln"; 
    g.depth_first_search(); 
  
    return 0; 
}
