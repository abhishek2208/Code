

//--------Leaders are Elements which is larger than all its elements on its right----------//


#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    int maximum=a[n-1];
    cout<<a[n-1]<<" ";
    for(int i=n-2;i>=0;i--)
    {
        if(a[i]>maximum){
            cout<<a[i]<<" ";
            maximum=a[i];
            }
    }
    return 0;

}
