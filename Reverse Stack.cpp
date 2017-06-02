#include<bits/stdc++.h>
using namespace std;
stack<char> insertAtBottom(stack<char> st,int item)
{
    if(st.empty()==true)
    st.push(item);

    else{
            int a=st.top();
    st.pop();
    st=insertAtBottom(st,item);
    st.push(a);

    }
    return st;

}

stack<char> reverse_stack(stack<char> st)
{
    if(st.empty()!=true){
    int a=st.top();
    st.pop();
    st=reverse_stack(st);
    st=insertAtBottom(st,a);
    }
    return st;
}
int main()
{
    char s[10];
    cin>>s;
    stack<char> st;
    for(int i=0;i<strlen(s);i++)
        st.push(s[i]);

        st=reverse_stack(st);


         int i=0;
    while(st.empty()==false)
    {
        s[i]=st.top();
        st.pop();
        i++;
    }
    cout<<s<<endl;
    printstack(top);



}
