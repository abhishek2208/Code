#include<bits/stdc++.h>
using namespace std;
bool not_common(const pair<int,pair<int,int> > p1,const pair<int,pair<int,int> > p2)
{
    if((p1.second.first!=p2.second.first)&&(p1.second.first!=p2.second.second)&&(p1.second.second!=p2.second.first)&&(p1.second.second!=p2.second.second))
       return true;

       return false;

}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int x;
    cin>>x;
    int s=n*(n-1)/2;
    int k=0;
    pair<int,pair<int,int> > p[s];
    for(int i=0;i<n-1;i++)
    {

        for(int j=i+1;j<n;j++)
        {
            p[k]=make_pair(a[i]+a[j],make_pair(a[i],a[j]));
            k++;
        }
    }
    sort(p,p+s);
    int l=0,r=n-1;


    while(l<r)
    {
        if(p[l].first+p[r].first==x&&not_common(p[l],p[r])==true)
           {
               cout<<p[l].second.first<<" "<<p[l].second.second<<" "<<p[r].second.first<<" "<<p[r].second.second<<endl;
               r--;l++;
               }
        else if(p[l].first+p[r].first>x)
            r--;
        else
            l++;
    }
}
