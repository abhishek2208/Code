#include<bits/stdc++.h>
using namespace std;
 int V;
 int find_min(int spt[],int dist[])
 {
     int Min=INT_MAX;
     int index;
     for(int i=0;i<V;i++)
     {
         if(spt[i]==0&&dist[i]<Min)
         {
             Min=dist[i];
             index=i;
         }
     }
     return index;
 }
int main()
{
V=5;
  int graph[5][5] = {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };
int spt[V];
int dist[V];

for(int i=0;i<V;i++)
   {
       dist[i]=INT_MAX;
       spt[i]=0;
   }

dist[0]=0;


 for(int i=0;i<V;i++)
 {
     int a=find_min(spt,dist);

 spt[a]=1;

 for(int j=0;j<V;j++)
 {
     if(graph[a][j]>0&&spt[j]==0&&dist[a]!=INT_MAX&&dist[a]+graph[a][j]<dist[j])
     {
         dist[j]=dist[a]+graph[a][j];

     }
 }




}

for(int i=1;i<V;i++)
{
    cout<<dist[i]<<endl;
}


}






