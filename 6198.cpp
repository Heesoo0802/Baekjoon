#include <iostream>
#include <stack>
#define int long long
using namespace std;
signed main()
{
    int N;
    cin >> N;

    int h[80010]={};
    for(int i=0;i<N;i++) cin >> h[i];

    int ans = 0;
    stack <int> st;
    for(int i=0;i<N;i++)
    {
        while(!st.empty() && h[st.top()] <= h[i])
        {
            st.pop();
        }
        ans += st.size();
        st.push(i);
    }
    cout << ans << endl;
    return 0;
}