#include<bits/stdc++.h>
using namespace std;
int main()
{
     int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

        int  sm[n],gt[n],minm=0,maxm=n-1;
        sm[0]=-1;
        gt[n-1]=-1;
        for(int i=1;i<n;i++)
        {
            if(arr[i]>arr[minm])
            {
                sm[i]=minm;
            }
            else
            {
                minm=i;
                sm[i]=-1;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            if(arr[i]<arr[maxm])
            {
                gt[i]=maxm;
            }
            else
            {
                maxm=i;
                gt[i]=-1;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(sm[i]!=-1&&gt[i]!=-1)
           {cout<<i<<endl;
            cout<<arr[sm[i]]<<" "<<arr[i]<<" "<<arr[gt[i]]<<endl;
            break;
           }
        }

}
