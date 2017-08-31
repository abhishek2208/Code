#include<bits/stdc++.h>
using namespace std;
void permute(char a[],int l,int r)
{
  if(l==r)
    cout<<a<<endl;
  for(int i=l;i<=r;i++)
  {
  swap(a[l],a[i]);
  permute(a,l+1,r);
  swap(a[l],a[i]);
  }
}
int main()
{
    char a[1000];
    cin>>a;

       permute(a,0,strlen(a)-1);



}
