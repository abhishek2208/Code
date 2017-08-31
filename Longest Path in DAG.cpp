#include<bits/stdc++.h>
using namespace std;
int V;
vector< pair<int,int> > *edge;

void addEdge(int u,int v,int w)
{
    edge[u].push_back(make_pair(v,w));
}

void topologicalSort(int s,bool visited[],stack<int> &st)
{

    visited[s]=true;
    for(int i=0;i<edge[s].size();i++)
    {
        if(visited[edge[s][i].first]!=true)
        topologicalSort(edge[s][i].first,visited,st);
    }
    st.push(s);

}
int main()
{
    V=6;
   edge =new vector< pair<int,int> >[V];
    addEdge(0, 1, 5);
    addEdge(0, 2, 3);
    addEdge(1, 3, 6);
    addEdge(1, 2, 2);
    addEdge(2, 4, 4);
    addEdge(2, 5, 2);
    addEdge(2, 3, 7);
    addEdge(3, 5, 1);
    addEdge(3, 4, -1);
    addEdge(4, 5, -2);


    bool *visited=new bool[V];
    for(int i=0;i<V;i++)
        visited[i]=false;

stack<int> st;
 for(int i=0;i<V;i++)
 {
     if(visited[i]!=true)
            topologicalSort(i,visited,st);

 }
  int d[V];
 for(int i=0;i<V;i++)
    d[i]=INT_MIN;

    d[1]=0;


while(!st.empty())
{
 int a= st.top();
 st.pop();
 for(int i=0;i<edge[a].size();i++)
 {
     if(d[edge[a][i].first]<d[a]+edge[a][i].second)
        d[edge[a][i].first]=d[a]+edge[a][i].second;
 }
}

for(int i=0;i<V;i++)
{

    cout<<d[i]<<endl;
}
}



