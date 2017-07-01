#include<bits/stdc++.h>
using namespace std;
int V;
vector<int> *edge;

void addEdge(int u,int v)
{
    edge[u].push_back(v);
}

bool dfs(int s,bool *visited,bool *visiting)
{

    visiting[s]=true;
   // cout<<s<<endl;
    for(int i=0;i<edge[s].size();i++)
    {
        if(visiting[edge[s][i]]==true)
            return true;
        if(visited[edge[s][i]]==false&& dfs(edge[s][i],visited,visiting))
           return true;
    }
    visiting[s]=false;
    visited[s]=true;

    return false;

}
int main()
{
    V=6;
   edge =new vector<int>[V];
   addEdge(0, 1);
    addEdge(1, 2);
    addEdge(2, 3);
    addEdge(3, 4);
    addEdge(4, 5);
   // addEdge(3, 5);
    //addEdge(4,5);

    bool *visited=new bool[V];
    bool *visiting=new bool[V];
    for(int i=0;i<V;i++)
        {
        visited[i]=false;
        visiting[i]=false;
        }

 for(int i=0;i<V;i++)
 {
     if(visited[i]!=true){
            if(dfs(i,visited,visiting)==true)
            {cout<<"Yes"<<endl;
            break;}
            else
                cout<<"No";
     }

 }
}


