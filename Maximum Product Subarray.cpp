#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

        int max_prod_here=1;
        int min_prod_here=1;
        int max_prod=1;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==0)
            {
                max_prod_here=1;
                min_prod_here=1;
            }
            else if(arr[i]>0)
            {
                max_prod_here=max_prod_here*arr[i];
                min_prod_here=min(min_prod_here*arr[i],1);
            }
            else
            {
                int temp=max_prod_here;
                max_prod_here=max(min_prod_here*arr[i],1);
                min_prod_here=temp*arr[i];
            }
            if(max_prod<max_prod_here)
                max_prod=max_prod_here;
        }
        cout<<max_prod<<endl;

}
