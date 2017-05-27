#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];

    for(int i=0;i<n;i++)
        cin>>a[i];


        int maxm=INT_MIN;
        int minm=INT_MAX;
        int hMap[10000],flag=0;;
        memset(hMap,0,10000);

        for(int i=0;i<n;i++)
        {
            if(a[i]<minm)
                minm=a[i];
            if(a[i]>maxm)
                maxm=a[i];

            if(hMap[a[i]]==0)
                hMap[a[i]]=1;

                else
                {
                    flag=1;break;}




        }
        if(maxm-minm+1==n&&flag==0)
            cout<<"Consecutive"<<endl;
        else
            cout<<"Non Consecutive"<<endl;


}
