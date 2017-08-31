#include<bits/stdc++.h>
using namespace std;

int root(int x,int *id)
{
    while(id[x]!=x)
    x=id[x];

    return x;

}

void union_(int x,int y,int *id )
{
    int x1=root(x,id);
    int y1=root(y,id);

    id[x1]=y1;

}

int main()
{
   int v,e;
   cin>>v>>e;
   int src,des,w;
   pair<int ,pair<int,int> > p[e];
   for(int i=0;i<e;i++)
   {
       cin>>src>>des>>w;
       p[i]=make_pair(w,make_pair(src,des));
   }


    int *id=new int[v];
    for(int i=0;i<v;i++)
        {
        id[i]=i;

        }


sort(p,p+e);
int min_wt=0;
 for(int i=0;i<e;i++)
 {
     int r1=root(p[i].second.first,id);
     int r2=root(p[i].second.second,id);
     if(r1!=r2)
     {
         cout<<p[i].second.first<<" "<<p[i].second.second<<endl;
        union_(r1,r2,id);
        min_wt=min_wt+p[i].first;
     }


}

cout<<min_wt<<endl;

}




