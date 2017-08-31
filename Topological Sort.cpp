#include<bits/stdc++.h>
using namespace std;
int V;
vector<int> *edge;S

void addEdge(int u,int v)
{
    edge[u].push_back(v);
}

void topologicalSort(int s,bool visited[],stack<int> &st)
{

    visited[s]=true;
    for(int i=0;i<edge[s].size();i++)
    {
        if(visited[edge[s][i]]!=true)
        topologicalSort(edge[s][i],visited,st);
    }
    st.push(s);

}
int main()
{
    V=6;
   edge =new vector<int>[V];
   addEdge(5, 2);
    addEdge(5, 0);
    addEdge(4, 0);
    addEdge(4, 1);
    addEdge(2, 3);
    addEdge(3, 1);

    bool *visited=new bool[V];
    for(int i=0;i<V;i++)
        visited[i]=false;

stack<int> st;
 for(int i=0;i<V;i++)
 {
     if(visited[i]!=true)
            topologicalSort(i,visited,st);

 }
while(!st.empty())
{
 cout<<st.top()<<endl;
 st.pop();
}
}


