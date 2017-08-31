#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    int dp[n];


    for(int i=0;i<n;i++)
        dp[i]=INT_MAX;

        dp[0]=0;

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(j<=i+a[i])
            dp[j]=min(dp[j],dp[i]+1);

        }
    }
    for(int i=0;i<n;i++)
        cout<<dp[i]<<endl;


    cout<<dp[n-1]<<endl;
}
