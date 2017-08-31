#include<bits/stdc++.h>
using namespace std;
int main()
{

   int n;
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++)
    cin>>a[i];


    int dp[n][n];
    int dp_s[n][n];

    for(int i=0;i<n;i++)
      {

       dp[i][i]=a[i];
       dp_s[i][i]=0;
       }

    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<n-i+1;j++)
        {
            int k=j+i-1;
          dp[j][k]=max(a[j]+dp_s[j+1][k],a[k]+dp_s[j][k-1]);
          dp_s[j][k]=min(dp[j+1][k],dp[j][k-1]);
        }

    }

    cout<<dp[0][n-1]<<endl;
}


