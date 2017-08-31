#include<bits/stdc++.h>
using namespace std;

int findMax(int arr[],int n)
{
    int Max=arr[0];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum=sum+arr[i];

        if(sum>Max)
            Max=sum;
        if(sum<0)
            sum=0;
    }
    return Max;
}
int main()
{
int n;
cin>>n;
int a[n][n];
int arr[n];

for(int i=0;i<n;i++)
    arr[i]=0;

for(int i=0;i<n;i++)
{
    for(int j=0;j<n;j++)
    {
        cin>>a[i][j];
    }

}
int index=0;
int l=0,r=0;
int Max=INT_MIN;
int curr;
while(l!=n)
{

    for(int i=0;i<n;i++)
    arr[i]=0;

while(r!=n)
{
   for(int i=0;i<n;i++)
   {
     arr[i]=a[i][r]+arr[i];
   }
   curr=findMax(arr,n);
   Max=max(Max,curr);
   cout<<Max<<endl;
r++;
}

while(l!=r)
{
   for(int i=0;i<n;i++)
   {
     arr[i]=arr[i]-a[i][l];
   }
   curr=findMax(arr,n);
   Max=max(Max,curr);
l++;
cout<<Max<<endl;

}
index++;
l=index;
r=index;

}


cout<<Max<<endl;






}

