#include<bits/stdc++.h>
using namespace std;
int lazy[1000]={0};
void construct(int a[],int segT[],int low,int high,int pos)
{
    if(low==high){        segT[pos]=a[low]; return ;}
    int mid=(high+low)/2;
    construct(a,segT,low,mid,2*pos+1);
    construct(a,segT,mid+1,high,2*pos+2);
    segT[pos]=min(segT[2*pos+1],segT[2*pos+2]);
    return ;

}

int  query(int segT[],int l,int h,int low,int high,int pos)
{
    if(lazy[pos]!=0)
    {
      segT[pos]+=lazy[pos];
        if(low!=high){

        lazy[2*pos+1]+=lazy[pos];

        lazy[2*pos+2]+=lazy[pos];}

        lazy[pos]=0;


    }

      if(low>high||l>high||h<low)
        return INT_MAX;


    if(l<=low&&h>=high)
        return segT[pos];

    int mid=(high+low)/2;
    return(min(query(segT,l,h,low,mid,2*pos+1),query(segT,l,h,mid+1,high,2*pos+2)));

}

void update(int segT[],int l,int h,int low,int high,int pos,int diff)
{
    if(lazy[pos]!=0)
    {
        segT[pos]+=lazy[pos];
        if(low!=high){

        lazy[2*pos+1]+=lazy[pos];

        lazy[2*pos+2]+=lazy[pos];}

        lazy[pos]=0;

        return;
    }
    if(low>high||low>h||high<l)
        return;

    if(l<=low&&h>=high)
    {
        segT[pos]+=diff;

        if(low!=high)
        {
            lazy[2*pos+1]+=diff;

        lazy[2*pos+2]+=diff;

        }
        return;
    }
    int mid=(low+high)/2;
    update(segT,l,h,low,mid,2*pos+1,diff);

    update(segT,l,h,mid+1,high,2*pos+2,diff);

    segT[pos]=min(segT[2*pos+1],segT[2*pos+2]);

}
int main()
{
  int n;
  cin>>n;//Input Length of Array
  int a[n];

  for(int i=0;i<n;i++)
    cin>>a[i];
     int l,h;
  cin>>l>>h;//Input Range

  int n2=2*n-1;
  int segT[n2];

  construct(a,segT,0,n-1,0);
 cout<<query(segT,l,h,0,n-1,0)<<endl;

 update(segT,0,4,0,n-1,0,10);

 cout<<query(segT,l,h,0,n-1,0)<<endl;

}


