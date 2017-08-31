#include<bits/stdc++.h>
#include<string.h>
using namespace std;
int main()
{

char a[10000];
char b[10000];

cin>>a;
cin>>b;

int dp[strlen(b)+1][strlen(a)+1];

for(int i=0;i<strlen(a)+1;i++)
    dp[0][i]=0;


for(int i=0;i<strlen(b)+1;i++)
    dp[i][0]=0;


    for(int i=1;i<strlen(b)+1;i++)
    {
        for(int j=1;j<strlen(a)+1;j++)
        {
            if(b[i]==a[j])
                dp[i][j]=1+dp[i-1][j-1];

             else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }

    cout<<dp[strlen(b)][strlen(a)];


}
