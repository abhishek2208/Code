#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n],flag=0;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int k;
    cin>>k;

    sort(a,a+n);

    for(int i=0;i<n-2;i++)
    {
        int l=i+1;
        int r=n-1;
        while(l<r)
        {
            if(a[i]+a[l]+a[r]==k)
                {cout<<a[i]<<" "<<a[l]<<" "<<a[r]<<endl;
            flag=1;
            break;}
            else if(a[i]+a[l]+a[r]<k)
                l++;
            else
                r--;
        }
        if(flag==1)
            break;

    }
    if(flag==0)
        cout<<"No triplet"<<endl;
}
