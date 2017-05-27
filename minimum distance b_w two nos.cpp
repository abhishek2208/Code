#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
        int n1,n2;
        cin>>n1>>n2;
        int prev,minDist=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==n1||arr[i]==n2)
                prev=i;
            break;
        }
        for(int i=prev+1;i<n;i++)
        {
            if((arr[i]==n1||arr[i]==n2)&&arr[prev]!=arr[i]&&i-prev<=minDist)
            {
                minDist=i-prev;
                prev=i;
            }

        }
        cout<<minDist<<endl;



}
