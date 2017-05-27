#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
     cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    int Lmin[n],Rmax[n];

    Lmin[0]=a[0];
    Rmax[n-1]=a[n-1];

        for(int i=1;i<n;i++)
            Lmin[i]=min(a[i],Lmin[i-1]);

        for(int i=n-2;i>=0;i--)
        Rmax[i]=max(a[i],Rmax[i+1]);

        int i=0,j=0,maxDiff=INT_MIN;
         while(i<n&&j<n)

         {
             if(Lmin[i]<Rmax[j]){
                maxDiff=max(maxDiff,j-i);
                j++;
                }
                else
                    i++;
         }
         cout<<maxDiff<<endl;

}
