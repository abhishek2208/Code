#include<bits/stdc++.h>
using namespace std;
int main()
{

    char a[10000];
    cin>>a;
    int n=strlen(a);
    int dp[n][n];

    for(int i=0;i<n;i++)
        dp[i][i]=1;

    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<n-i+1;j++)
        {
            int k=j+i-1;
            if(a[j]==a[k]&&i==2)
                dp[j][k]=2;
            else if(a[j]==a[k])
                dp[j][k]=dp[j+1][k-1]+2;
            else
                dp[j][k]=max(dp[j+1][k],dp[j][k-1]);
        }

    }

    cout<<dp[0][n-1]<<endl;
}

