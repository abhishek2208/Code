#include<bits/stdc++.h>
using namespace std;

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

    if(l<=low&&h>=high)
        return segT[pos];
    if(low>high||l>high||h<low)
        return INT_MAX;
    int mid=(high+low)/2;
    return(min(query(segT,l,h,low,mid,2*pos+1),query(segT,l,h,mid+1,high,2*pos+2)));

}

void update(int segT[],int l,int h,int low,int high,int pos,int diff)
{
    if(l>h||l>high||h<low)
        return;
    if(low==high)
    {
        segT[pos]+=diff;
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

