#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    stack<int> s;
    s.push(a[0]);
    for(int i=1;i<n;i++)
    {
        int next=a[i];
        if(s.empty()!=true){
        int element=s.top();
        s.pop();
        while(element<next)
        {
            cout<<element<<" next is "<<next<<endl;


            if(s.empty()==true) break;
            element=s.top();
            s.pop();
        }

        if(element>next)
        s.push(element);
        }

        s.push(next);


    }

    while(s.empty()!=true)
    {
         cout<<s.top()<<" next is "<<-1<<endl;
         s.pop();

    }

    return 0;
}
