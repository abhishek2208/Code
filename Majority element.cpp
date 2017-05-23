#include <bits/stdc++.h>
using namespace std;

int main() {
	//code

	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n],hMap[1000],flag=0;
	    for(int i=0;i<n;i++)
	    cin>>a[i];

	   memset(hMap,0,1000);

	    for(int i=0;i<n;i++)
	    {
	    hMap[a[i]]++;
	    if(hMap[a[i]]>n/2&&flag==0)
	    {
	    cout<<a[i]<<endl;
	    flag=1;
	    break;}

	    }
	    if(flag==0)
	    cout<<"NO Majority Element"<<endl;
	}
}
