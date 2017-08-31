#include<bits/stdc++.h>
using namespace std;
class graph
{
    int V;
    vector<int> *edge;
public:
    graph(int v);
  void   addEdge(int u,int v);
    void bfs(int s);

};
graph::graph(int V)
{
    this->V=V;
    edge = new vector<int>[V];
}
void graph::addEdge(int u,int v)
{
    edge[u].push_back(v);
}
void graph::bfs(int s)
{
bool *visited=new bool[V];

for(int i=0;i<V;i++)
visited[i]=false;

queue<int> q;

q.push(s);
 visited[s]=true;

vector<int>:: iterator i;
while(!q.empty())
{
    int a=q.front();
    q.pop();
    cout<<a<<" ";




    for(i=edge[a].begin(); i!=edge[a].end();++i)
    {
        if(visited[*i]!=true)
        {
            q.push(*i);
            visited[*i]=true;
        }


    }

}

}

int main()
{
    graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.bfs(0);


}
