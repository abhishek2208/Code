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


for(int i=0;i<n;i++)
    dp[i][i]=a[i];



int sum=0;
int Min=INT_MAX;
for(int i=2;i<=n;i++)
{
    for(int j=0;j<n-i+1;j++)
    {
        int k=j+i-1;
       sum=0;
       Min=INT_MAX;

        for(int m=j;m<=k;m++)
        {
            sum=sum+a[m];
            int p;
            if(m==j)
                p=dp[m+1][k];
            else if(m==k)
                p=dp[j][k-1];
            else
                p=dp[j][m-1]+dp[m+1][k];



            Min=min(Min,p);

        }

        dp[j][k]=sum+Min;
    }
}

cout<<dp[0][n-1]<<endl;

}
