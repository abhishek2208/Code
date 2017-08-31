#include<bits/stdc++.h>
using namespace std;


int main()
{

    int n;
    cin>>n;
      int T[1000];
      memset(T,0,1000);

    T[0]=1;
    T[1]=1;

    for(int i=2;i<n;i++)
    {
        for(int j=0;j<i;j++)
            T[i]+=T[j]*T[i-j-1];
    }
    cout<<T[n-1];
}
