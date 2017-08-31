#include<bits/stdc++.h>
using namespace std;
int main()
{
    char a[10000];
    cin>>a;
    int l=strlen(a);

    int dp[l][l];
    for(int i=0;i<l;i++)
        dp[i][i]=0;

    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<n-i+1;j++)
        {
            int e=j+i-1;
            int Min=INT_MAX;
            for(int k=j+1;k<e;k++)
            {
                Min=min(min,d[j])

            }
        }
    }
}
