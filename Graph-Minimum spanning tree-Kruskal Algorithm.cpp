#include <cmath>
#include<ext/pb_ds/priority_queue.hpp>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int find_parent(int parent[],int i)
{
    if(parent[i]==-1)
       return i;
    return find_parent(parent,parent[i]);
}
void union_of_edge(int parent[],int x,int y)
{
    int xx=find_parent(parent,x);
    int yy=find_parent(parent,y);
    if(xx!=yy)
       parent[xx]=yy;
}

struct edge
{
    int u,v,w;
};

int main() {
    int n,m,u,v,w;
    //n # of vertices,m # of edges
//4 6  <-n,m
// 1 2 5   <- vertices with weight u,v,w  
// 1 3 3
// 4 1 6
// 2 4 7
// 3 2 4
// 3 4 5
    cin>>n>>m;
    priority_queue<pair<int,pair<int,int>>>q;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>w;
        u--;
        v--;
        q.push({-w,{u,v}});
    }
    edge sorted[m];
    for(int i=0;i<m;i++)
    {
        pair<int,pair<int,int>> temp = q.top();
        sorted[i].w=(-1*temp.first);
        sorted[i].u=temp.second.first;
        sorted[i].v=temp.second.second;
        q.pop();
    }
    
    vector<int> weight;
    int parent[n];
    for(int j=0;j<n;j++)
         parent[j]=-1;
    for(int i=0;i<m;i++)
    {   
        int x=find_parent(parent,sorted[i].u);
        int y=find_parent(parent,sorted[i].v);
        
        if(x!=y)
        {
            weight.push_back(sorted[i].w);
            union_of_edge(parent,x,y);
        }
    }
    int sum=0;
    for(int i=0;i<weight.size();i++)
    {
        sum+=weight[i];
    }
    cout<<"Cost of Minimum spanning tree of Graph:::"<<sum;
    return 0;
}
