#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> *edge,int u,int v)
{
    edge[u].push_back(v);
}

void dfs(vector<int> *edge,int s,bool *visited)
{
    cout<<s<<" ";
    visited[s]=true;
    for(int i=0;i<edge[s].size();i++)
    {
        if(visited[edge[s][i]]!=true)
            dfs(edge,edge[s][i],visited);
    }

}
int main()
{
    int V;
    vector<int> *edge;
    cin>>V;
   edge =new vector<int>[V];
   for(int i=0;i<V-1;i++)
   {

       int a,b;
       cin>>a>>b;
       addEdge(edge,a,b);
   }

    bool *visited=new bool[V];
    for(int i=0;i<V;i++)
        visited[i]=false;

 for(int i=0;i<V;i++)
 {
     if(visited[i]!=true)
            dfs(edge,i,visited);

 }
}

