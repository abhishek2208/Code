#include<bits/stdc++.h>
using namespace std;
int V;
vector<int> *edge;

void addEdge(int u,int v)
{
    edge[u].push_back(v);
}

void dfs(int s,bool visited[])
{
    visited[s]=true;
    for(int i=0;i<edge[s].size();i++)
    {
        if(visited[edge[s][i]]!=true)
            dfs(edge[s][i],visited);
    }

}
int main()
{
    V=4;
   edge =new vector<int>[V];
   addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(2, 0);
    addEdge(2, 3);
    addEdge(3, 3);


    bool *visited=new bool[V];
    for(int i=0;i<V;i++)
        visited[i]=false;


int last=0;

 for(int i=0;i<V;i++)
 {
     if(visited[i]!=true){
            dfs(i,visited);
            last=i;
            }
 }

             for(int i=0;i<V;i++)
        visited[i]=false;

        dfs(last,visited);

        for(int i=0;i<V;i++)
        {

        if(visited[i]==false)
        {
        cout<<" No";
        return 0;
        }
        }

        cout<<" last"<<last<<endl;




 }



