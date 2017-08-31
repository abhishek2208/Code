#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n,x;
    cin>>n>>x;

    int a[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }

    int i=0,j=n-1;

    while(i<n&&j>=0)
    {
        if(a[i][j]==x)
        {
            cout<<i<<" "<<j<<endl;
            return 0;
        }
        else if(a[i][j]>x)
        {
            j--;
        }
        else if(a[i][j]<x)
            i++;
    }
}
