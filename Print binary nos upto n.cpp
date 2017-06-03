#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;

    queue<string> q;
    q.push("1");
    while(n--)
    {
        cout<<q.front()<<endl;
        string s1=q.front();
        string s2=s1;
        q.pop();
        q.push(s1.append("0"));
        q.push(s2.append("1"));
    }
    return 0;
}
