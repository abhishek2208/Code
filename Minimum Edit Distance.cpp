#include<bits/stdc++.h>
using namespace std;
int main()
{
    char a[10000];
    char b[10000];

    cin>>a;
    cin>>b;
    int l1=strlen(a);
    int l2=strlen(b);

int dp[l2+1][l1+1];

for(int i=0;i<l1;i++)
    dp[0][i]=i;
for(int i=1;i<l2;i++)
    dp[i][0]=i;


for(int i=1;i<l2+1;i++)
{
    for(int j=1;j<l1+1;j++)
    {
        if(b[i-1]==a[j-1])
            dp[i][j]=dp[i-1][j-1];
        else
            dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));

    }
}
for(int i=1;i<l2+1;i++)
{
    for(int j=1;j<l1+1;j++)
    {
        cout<<dp[i][j]<<" ";

    }
    cout<<endl;
}


cout<<dp[l2][l1]<<endl;
}
