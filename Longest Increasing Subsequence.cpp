#include<bits/stdc++.h>
#include<stdlib.h>
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
       dp[i]=1;

        cout<<endl;

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[j]<a[i])
                dp[i]=max(dp[i],1+dp[j]);
        }
    }

    for(int i=0;i<n;i++)
        cout<<dp[i]<<" ";

}
