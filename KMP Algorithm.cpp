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
    int lps[l2];
    lps[0]=0;
    int len=0,i=1,j;
  while(i<l2)
    {
        if(pat[len]==pat[i])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if(len!=0)
                len=lps[len-1];

            else
               {
                 lps[i]=0;
            i++;

               }
        }


    }
    i=0;j=0;
    while(i<l1)
    {
       if(pat[j]==a[i])
       {
           i++;
           j++;
       }
       if(j==l2)
       {
           cout<<"pattern found at "<<i-j<<endl;
           j=lps[j-1];
       }
       else if(i<l1&&pat[j]!=a[i])
       {
           if(lps[j]!=0)
           {
               j--;
           }
           else
            i++;
       }

    }

    for(i=0;i<l2;i++)
        cout<<lps[i]<<endl;
}
