#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,w;
        cin>>n;
        cin>>w;
        int val[n],wt[n];
        for(int i=0;i<n;i++)
            cin>>val[i];
         for(int i=0;i<n;i++)
            cin>>wt[i];

            int dp[n][w+1];

            for(int i=0;i<w+1;i++)
            {
                if(wt[0]>i)
                    dp[0][i]=0;
                else
                    dp[0][i]=val[0];

            }
            for(int i=1;i<n;i++)
            {
               for(int j=0;j<w+1;j++)
               {
                   if(wt[i]>j)
                    dp[i][j]=dp[i-1][j];
                   else
                    dp[i][j]=max((val[i]+dp[i-1][j-wt[i]]),dp[i-1][j]);

               }

            }
            cout<<dp[n-1][w]<<endl;


    }
}
