#include<bits/stdc++.h>
using namespace std;

int main()
{
    int s[10];

    stack<int > st;
    for(int i=0;i<10;i++){
        cin>>s[i];
    }

    int span[10];
    span[0]=1;
    st.push(0);

    for(int i=1;i<10;i++)
    {
        while(st.empty()!=true&&s[st.top()]<s[i])
            st.pop();

        if(st.empty()==true)
            span[i]=i+1;
        else
            span[i]=i-st.top();

        st.push(i);
    }

    for(int i=0;i<10;i++)
        cout<<span[i]<<endl;







}


