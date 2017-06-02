#include<bits/stdc++.h>
using namespace std;
stack <int > sortedInsert(stack <int > st,int item)
{
    if(st.empty()==true||st.top()<item)
    st.push(item);

    else{
    int a=st.top();
    st.pop();
    st=sortedInsert(st,item);
    st.push(a);

    }
    return st;

}

stack <int> sort_stack(stack <int > st)
{
    if(st.empty()!=true){
    int a=st.top();
    st.pop();
    st=sort_stack(st);
    st=sortedInsert(st,a);
    }
    return st;
}
int main()
{
    int s[10];

    stack<int > st;
    for(int i=0;i<10;i++){
        cin>>s[i];
        st.push(s[i]);
        }

        st=sort_stack(st);


 while(st.empty()==false)
    {
        int a=st.top();
        st.pop();
       cout<<a<<endl;
    }



}

