#include<bits/stdc++.h>
using namespace std;
int main()
{

  int graph[5][5] = {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };

  int spt[5][5];

  for(int i=0;i<5;i++)
  {
      for(int j=0;j<5;j++)
      {
          if(i==j)
            spt[i][j]=0;
          else if(graph[i][j]>0)
          spt[i][j]=graph[i][j];
          else
            spt[i][j]=1000;
      }
  }




  for(int i=0;i<5;i++)
  {
      for(int j=0;j<5;j++)
      {
          for(int k=0;k<5;k++)
          {
               if(spt[j][i]+spt[i][k]<spt[j][k])
                spt[j][k]=spt[j][i]+spt[i][k];
          }
      }
  }

   for(int i=0;i<5;i++)
  {
      for(int j=0;j<5;j++)
      {
          cout<<spt[i][j]<<"   ";
      }
      cout<<endl;
  }

}
