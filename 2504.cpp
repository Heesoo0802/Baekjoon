#include <iostream>
#include <stack>
using namespace std;
int main()
{
    string s;
    cin >> s;

    int ans = 0;
    stack <int> st;
    for(int i=0;s[i]!=0;i++)
    {
        if(s[i]=='(') st.push(-1);
        else if(s[i]=='[') st.push(-2);
        else if(s[i]==')')
        {
            int k = 0;
            while(!st.empty() && st.top()!= -1 && st.top()!=-2)
            {
                k += st.top();
                st.pop();
            }
            if(!st.empty() && st.top()==-1) 
            {
                st.pop();
                if(k == 0) k = 1;
                k *= 2;
                st.push(k);
            }
            else 
            {
                cout << "0" << endl;
                return 0;
            }
        }
        else
        {
            int k = 0;
            while(!st.empty() && st.top()!= -1 && st.top()!=-2)
            {
                k += st.top();
                st.pop();
            }
            if(!st.empty() && st.top()==-2) 
            {
                st.pop();
                if(k == 0) k = 1;
                k *= 3;
                st.push(k);
            }
            else 
            {
                cout << "0" << endl;
                return 0;
            }
        }
    }

    while(!st.empty())
    {
        if(st.top()==-1 || st.top()==-2)
        {
            cout << "0";
            return 0;
        }
        else 
        {
            ans += st.top();
            st.pop();
        }
    }
    cout << ans << endl;
    return 0;
}