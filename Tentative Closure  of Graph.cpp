#include<bits/stdc++.h>
using namespace std;
int V;
vector<int> *edge;

void addEdge(int u,int v)
{
    edge[u].push_back(v);
}

void dfs(int s,int v,bool **tc)
{

    tc[s][v]=true;


    for(int i=0;i<edge[v].size();i++)
    {
        if(tc[s][edge[v][i]]!=true)
            dfs(s,edge[v][i],tc);
    }

}
int main()
{
    cin>>V;
   edge =new vector<int>[V];
   addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(2, 0);
    addEdge(2, 3);
    addEdge(3, 3);
    addEdge(4,5);

    bool **tc;
    tc=new bool*[V];

    for(int i=0;i<V;i++)
        tc[i]=new bool[V];

    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
         tc[i][j]=false;
    }


 for(int i=0;i<V;i++)
 {
     dfs(i,i,tc);

 }
 for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
         cout<<tc[i][j]<<" ";

         cout<<endl;
    }


}


