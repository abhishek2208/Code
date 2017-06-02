#include<bits/stdc++.h>
using namespace std;
int main()
{
    char s[10];
    cin>>s;
    stack<char> st;
    for(int i=0;i<strlen(s);i++)
        st.push(s[i]);

    int i=0;
    while(st.empty()==false)
    {
        s[i]=st.top();
        st.pop();
        i++;
    }
    cout<<s<<endl;
}
