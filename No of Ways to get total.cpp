#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,s;
    cin>>n>>s;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    int dp[n][s+1];

    for(int i=0;i<s+1;i++)
    {
        if(i%a[0]==0)
            dp[0][i]=1;
        else
            dp[0][i]=0;

    }

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<s+1;j++)
        {
            if(a[i]>j)
                dp[i][j]=dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j]+dp[i][j-a[i]];
        }
    }

for(int i=0;i<n;i++)
    {
        for(int j=0;j<s+1;j++)
        {
          cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}

