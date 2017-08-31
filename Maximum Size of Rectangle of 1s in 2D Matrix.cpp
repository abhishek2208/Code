#include<bits/stdc++.h>
using namespace std;
int find_area(int dp[],int n)
{
int h=INT_MAX;
int Max=INT_MIN;
int l=0;

for(int i=0;i<n;i++)
{

    if(dp[i]>0&&h==0)
    {
         h=dp[i];
    l++;
    Max=max(Max,l*h);
    }
    else if(dp[i]>0)
    {
        h=min(dp[i],h);
        l++;

    Max=max(Max,l*h);
    }
    else if(dp[i]==0)
    {
        h=0;l=0;
    }
}
return Max;

}
int main()
{
    int n;
    cin>>n;
    int a[n][n];
    int dp[n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
         cin>>a[i][j];

        }
    }

    for(int i=0;i<n;i++)
        dp[i]=a[0][i];

    int Max=find_area(dp,n);

  for(int i=1;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
           if(a[i][j]==1)
            dp[j]++;
           else
            dp[j]=0;

        }

        Max=max(Max,find_area(dp,n));
    }

    cout<<Max<<endl;
}
