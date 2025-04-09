#include <iostream>
#include <stack>
using namespace std;
int main()
{
    string s;
    stack <char> st;

    cin >> s;

    for(int i=0;s[i]!=0;i++)
    {
        if(s[i]>='A' && s[i]<='Z') 
        {
            cout << s[i];
            continue;
        }

        if(s[i]=='(') st.push(s[i]);
        else if(s[i]=='*' || s[i]=='/')
        {
            while(!st.empty() && (st.top()=='*' || st.top()=='/'))
            {
                cout << st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        else if(s[i]=='+' || s[i]=='-')
        {
            while(!st.empty() && st.top()!='(')
            {
                cout << st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        else if(s[i]==')')
        {
            while(!st.empty())
            {
                if(st.top()=='(')
                {
                    st.pop();
                    break;
                }
                cout << st.top();
                st.pop();
            }
        }
    }
    while(!st.empty())
    {
        cout << st.top();
        st.pop();
    }
}