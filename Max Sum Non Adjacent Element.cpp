#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    int inc=a[0];
    int exc=0;
    for(int i=1;i<n;i++)
    {
        int exc_new=max(exc,inc);
        inc=exc+a[i];
        exc=exc_new;

    }
    cout<<max(exc,inc);
}
