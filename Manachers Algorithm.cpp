#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;

    string a="#";
    for(int i=0;i<s.length();i++)
        a=a+s[i]+"#";

    for(int i=0;i<a.length();i++)
        cout<<a[i]<<" ";

cout<<endl;
        int arr[a.length()];

        for(int i=0;i<a.length();i++)
            arr[i]=0;

int c=0,r=0;
    for(int i=1;i<a.length();i++)
    {
        int mirror=c-(i-c);
        if(r>i)
        {
            arr[i]=min(r-i,arr[mirror]);
        }
        while(i+arr[i]+1<a.length()&& a[i+arr[i]+1]==a[i-arr[i]-1])
            arr[i]++;

        if(i+arr[i]>r)
        {
            r=i+arr[i];
            c=i;
        }



    }
    for(int i=0;i<a.length();i++)
           cout<< arr[i]<<" ";

}
