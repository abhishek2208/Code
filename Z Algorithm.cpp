#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    string pat;

    cin>>pat;
    cin>>s;

string a=pat+"$"+s;

int l1=s.length();
int l2=pat.length();
int n=a.length();

int z[n];
int l=0,r=0;
for(int i=1;i<n;i++)
{

    if(i>r)
    {
        l=r=i;

        while(r<n&&a[r-l]==a[r])
            r++;

        z[i]=r-l;
        r--;


    }
    else
        {

    int k=i-l;

    if(z[k]<r-i+1)
        z[i]=z[k];

    else
    {
        l=i;
         while(r<n && a[r-l]==a[r])
            r++;

        z[i]=r-l;
        r--;

    }

        }

}

for(int i=1;i<n;i++)
{
       if(z[i]>=l2)
    cout<<i-l2-1<<endl;
}





}
