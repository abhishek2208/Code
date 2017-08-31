#include<bits/stdc++.h>
using namespace std;
int V;
vector<int> *edge;

void addEdge(int u,int v)
{
    edge[u].push_back(v);
}

void bfs(int s)
{
bool *visited=new bool[V];

for(int i=0;i<V;i++)
visited[i]=false;

queue<int> q;

q.push(s);
 visited[s]=true;


while(!q.empty())
{
    int a=q.front();
    q.pop();
    cout<<a<<" ";




    for(int i=0; i<edge[a].size();++i)
    {
        if(visited[edge[a][i]]!=true)
        {
            q.push(edge[a][i]);
            visited[edge[a][i]]=true;
        }


    }

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
    cout<<1<<endl;
    bfs(0);
}

