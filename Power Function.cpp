#include<bits/stdc++.h>
using namespace std;
int pow(int x,int y)
{
    if(y==0)
        return 1;
    if(y%2==0)
        return pow(x,y/2)*pow(x,y/2);
    else
        return x*pow(x,y/2)*pow(x,y/2);
}
int main()
{
    cout<<pow(5,10)<<endl;

}
