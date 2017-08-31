#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  char a[n][n];
  for(int i=0;i<n;i++)
  {
      for(int j=0;j<n;j++)
      {
         cin>>a[i][j];
      }
  }

  int h[n][n];
  int v[n][n];

  if(a[0][0]=='X')
  {
      h[0][0]=1;
      v[0][0]=1;
  }
  else
  {
      h[0][0]=0;
      v[0][0]=0;
  }

  for(int i=1;i<n;i++)
  {
      if(a[0][i]=='X')
  {
      v[0][i]=1;
      h[0][i]=h[0][i-1]+1;
  }
      else
  {
      v[0][i]=0;
      h[0][i]=0;
  }
  if(a[i][0]=='X')
  {
      v[i][0]=v[i-1][0]+1;
      h[0][i]=1;
  }
  else
  {
      v[0][0]=0;
      h[0][0]=0;
  }


  }

  for(int i=1;i<n;i++)
  {
      for(int j=1;j<n;j++)
      {
          if(a[i][j]=='X')
          {
              v[i][j]=v[i-1][j]+1;
               h[i][j]=h[i][j-1]+1;

          }
          else{
            v[i][j]=0;
            h[i][j]=0;
          }
      }
  }
  int Max=INT_MIN;

  for(int i=n-1;i>=0;i--)
  {
      for(int j=n-1;j>=0;j--)
      {
          int k=min(v[i][j],h[i][j]);

          if(k>Max)
          {
              while(k>Max)
              {
                  if(h[i-k+1][j]>=k&&v[i][j-k+1]>=k)
                  {
                      Max=k;
                  }
                  else
                    k--;
              }


          }
      }
  }



cout<<Max<<endl;

}
