#include<bits/stdc++.h>
using namespace std;

 int board[8][8]={{0,0,0,0,0,0,0,0},
     {0,0,0,0,0,0,0,0},
     {0,0,0,0,0,0,0,0},
     {0,0,0,0,0,0,0,0},
     {0,0,0,0,0,0,0,0},
     {0,0,0,0,0,0,0,0},
     {0,0,0,0,0,0,0,0},
     {0,0,0,0,0,0,0,0}};

bool safe(int board[][8],int r,int c)
{



int i,j;


for(int i=r;i>=0;i--)
{
    if(board[i][c])
        return false;
}
    for(i=r,j=c;i>=0,j>=0;i--,j--)
    {
       if(board[i][j])
                return false;
    }



     for(i=r,j=c;i>=0,j<8;i--,j++)
    {
             if(board[i][j])
                return false;
    }


return true;

}
bool queen(int board[][8],int row)
{
    if(row>=8)
        return true;

    for(int i=0;i<8;i++)
    {
        if(safe(board,row,i))
        {
            board[row][i]=1;

            if(queen(board,row+1))
                return true;

            board[row][i]=0;
        }
    }
    return false;

}
int main()
{



    if(queen(board,0))
        cout<<"Yes"<<endl;

for(int i=0;i<8;i++)
{
    for(int j=0;j<8;j++)
    {
        cout<<board[i][j]<<" ";
    }
    cout<<endl;
}
}
