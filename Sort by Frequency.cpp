#include<bits/stdc++.h>
using namespace std;

bool compare(const pair<int, pair<int,int> >&i, const pair<int, pair<int,int> >&j)
{
    if (i.first!=j.first) return (i.first >j.first);
    else return (i.second.second<j.second.second);
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    pair<int,int>p1[n];
    for(int i=0;i<n;i++)
        p1[i]=make_pair(a[i],i);

    sort(p1,p1+n);


    pair<int,pair <int,int> >p2[n];

    int c=1;
    int j=0;
    int index=p1[0].second;
    for(int i=0;i<n;i++)
        {
            if(p1[i].first==p1[i+1].first)
                c++;
            else{
                p2[j]=make_pair(c,make_pair(p1[i].first,index));
                c=1;
                index=p1[i+1].second;
                j++;
            }


         }
         sort(p2,p2+j,compare);

         for(int i=0;i<j;i++)
            {
                for(int k=0;k<p2[i].first;k++)
                    cout<<p2[i].second.first<<" ";
            }



}

