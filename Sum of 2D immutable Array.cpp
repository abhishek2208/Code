#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n][n];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    }
    int dp[n][n];
    dp[0][0]=a[0][0];
    for(int i=1;i<n;i++)
    {
        dp[0][i]=a[0][i]+dp[0][i-1];
        dp[i][0]=a[i][0]+dp[i-1][0];

    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            dp[i][j]=dp[i-1][j]+dp[i][j-1]+a[i][j]-dp[i-1][j-1];
        }
    }

     for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<dp[i][j]<<" ";

            cout<<endl;
    }


}
