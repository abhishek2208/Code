#include<bits/stdc++.h>
using namespace std;
int main()
{
        int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
        int k;
        cin>>k;
        int curr_sum=a[0],start=0,flag=0;

        for(int i=1;i<=n;i++)
        {
            while(curr_sum>k&&start<i-1)
            {
                curr_sum=curr_sum-a[start];
                start++;
            }
            if(curr_sum==k)
            {
                cout<<start<<"to "<<i-1;
                flag=1;
                break;
            }

            curr_sum=curr_sum+a[i];


        }
        if(flag==0)
            cout<<"No Subarray"<<endl;


}
