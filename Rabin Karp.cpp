#include<bits/stdc++.h>
using namespace std;
int main()
{
    char a[100000];
    char pat[100000];


     cin>>pat;
     cin>>a;

     int l1=strlen(a);
     int l2=strlen(pat);

int d=26;
int q=13;
int j;
int h=1;
for(int i=0;i<strlen(pat)-1;i++)
{
    h=h*d;
}
int p=0;
int t=0;

for(int i=0;i<strlen(pat);i++)
{
    p=p*d+pat[i];
    t=t*d+a[i];

}
int i=0;
for(i=0;i<=l1-l2;i++)
{


    if(p==t)
    {

        for(j=0;j<l2;j++)
        {
            if(pat[j]!=a[i+j])
                break;

        }

         if(j==l2)
         cout<<"Pattern Found"<<i<<endl;



    }
      if(i<l1-l2)
    {
        t=(t-a[i]*h)*d+a[i+l2];
    }
}

return 0;


}
