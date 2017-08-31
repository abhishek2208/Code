#include<bits/stdc++.h>
using namespace std;
 int V;
 int find_min(int mst[],int key[])
 {
     int Min=INT_MAX;
     int index;
     for(int i=0;i<V;i++)
     {
         if(mst[i]==0&&key[i]<Min)
         {
             Min=key[i];
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
int mst[V];
int key[V];
int parent[V];

for(int i=0;i<V;i++)
   {
       key[i]=INT_MAX;
       mst[i]=0;
   }

key[0]=0;
parent[0]=-1;

 for(int i=0;i<V;i++)
 {
     int a=find_min(mst,key);

 mst[a]=1;

 for(int j=0;j<V;j++)
 {
     if(graph[a][j]>0&&mst[j]==0&&graph[a][j]<key[j])
     {
         key[j]=graph[a][j];
         parent[j]=a;

     }
 }




}

for(int i=1;i<V;i++)
{
    cout<<parent[i]<<" "<<i<<" "<<graph[parent[i]][i]<<endl;
}


}





