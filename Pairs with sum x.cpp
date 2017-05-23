#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n],k;
    for(int i=0;i<n;i++)
        cin>>a[i];

    cin>>k;

    int hMap[1000];
    memset(hMap,0,1000);

    for(int i=0;i<n;i++)
    {
        if(k-a[i]>0&&hMap[k-a[i]]==1)
            cout<<a[i]<<" "<<k-a[i]<<endl;

        hMap[a[i]]=1;
    }
    return 0;
}
