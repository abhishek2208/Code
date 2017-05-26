#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    int max_diff=a[1]-a[0];
    int min_elm=a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]-min_elm>max_diff)
            max_diff=a[i]-min_elm;
        if(a[i]<min_elm)
            min_elm=a[i];

    }

    cout<<max_diff<<endl;

}
