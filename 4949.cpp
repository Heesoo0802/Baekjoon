#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main()
{
    while(1)
    {
        string arr;
        stack <int> st;
        int check = 1;
        getline(cin, arr);
        if(arr == ".") return 0;
        for(int i=0;;i++)
        {
            if(arr[i]=='(') st.push(1);
            else if(arr[i]=='[') st.push(2);
            else if(arr[i]==')')
            {
                if(!st.empty() && st.top()==1) st.pop();
                else check = 0;
            }
            else if(arr[i]==']')
            {
                if(!st.empty() && st.top()==2) st.pop();
                else check = 0;
            }

            if(arr[i]=='.' && arr[i+1]==0) break;
        }
        if(check==1 && st.empty()) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}