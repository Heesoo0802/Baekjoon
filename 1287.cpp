#include <iostream>
#include <stack>
#include <queue>
#define int long long 
using namespace std;
signed main()
{
    string s;
    cin >> s;
    string t;

    stack <char> st;
    queue <int> num;
    
    int check = 0; //앞이 숫자이면 1, 문자이면 0
    int cnt = 0;
    for(int i=0;s[i]!=0;i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            if(check==0)
            {
                t.push_back('X');
                cnt = s[i]-'0';
                check = 1;
            }
            else cnt = 10 * cnt + s[i] - '0';
        }
        else
        {
            if(check==1)
            {
                num.push(cnt);
                check = 0;
            }
            if(s[i]=='(') 
            {
                st.push('(');
                if(s[i+1]==0 || s[i+1]==')') 
                {
                    cout << "ROCK";
                    return 0;
                }
            }
            else if(s[i]==')')
            {
                bool found = false;
                while(!st.empty())
                {
                    if(st.top()=='(')
                    {
                        st.pop(); 
                        found = true;
                        break;
                    }
                    t.push_back(st.top()); st.pop();
                }
                if(found == false)
                {
                    cout << "ROCK";
                    return 0;
                }
            }
            else if(s[i]=='*' || s[i]=='/')
            {
                while(!st.empty())
                {
                    if(st.top()=='*' || st.top()=='/')
                    {
                        t.push_back(st.top()); st.pop();
                    }
                    else break;
                }
                st.push(s[i]);
            }
            else if(s[i]=='+' || s[i]=='-')
            {
                while(!st.empty() && st.top()!='(')
                {
                    t.push_back(st.top()); st.pop();
                }
                st.push(s[i]);
            }
        }
    }
    
    if(check==1) num.push(cnt);

    while(!st.empty())
    {
        if(st.top()=='(')
        {
            cout << "ROCK";
            return 0;
        }
        t.push_back(st.top()); st.pop();
    }

    stack <int> calc;
    for(int i=0;t[i]!=0;i++)
    {
        if(t[i] == 'X')
        {
            calc.push(num.front());
            num.pop();
        }
        else
        {
            if(calc.size()<2)
            {
                cout << "ROCK";
                return 0;
            }
            int y = calc.top(); calc.pop();
            int x = calc.top(); calc.pop();
            if(t[i]=='*') calc.push(x*y);
            else if(t[i]=='/') 
            {
                if(y==0)
                {
                    cout << "ROCK";
                    return 0;
                }
                calc.push(x/y);
            }
            else if(t[i]=='+') calc.push(x+y);
            else calc.push(x-y);
        }
    }
    if(calc.size()!=1)
    {
        cout << "ROCK";
        return 0;
    }
    cout << calc.top();
}