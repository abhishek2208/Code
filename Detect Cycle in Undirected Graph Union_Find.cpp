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
    int src,des;
   pair<int ,int>p[e];
   for(int i=0;i<e;i++)
   {
       cin>>src>>des;
       p[i]=make_pair(src,des);
   }


    int *id=new int[v];
    for(int i=0;i<v;i++)
        {
        id[i]=i;

        }

 for(int i=0;i<e;i++)
 {
     int r1=root(p[i].first,id);
     int r2=root(p[i].second,id);
     cout<<r1<<" "<<r2<<endl;
     if(r1==r2)
     {
        cout<<" Yes"<<endl;
        return 0;
     }
     union_(r1,r2,id);

}
cout<<"No";
}



