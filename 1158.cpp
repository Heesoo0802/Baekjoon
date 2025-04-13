#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int N, K;
    cin >> N >> K;
    queue <int> q;
    for(int i=1;i<=N;i++) q.push(i);
    int cnt = 0;
    queue <int> ans;
    while(!q.empty())
    {
        cnt++;
        int x = q.front();
        q.pop();
        if(cnt%K==0) ans.push(x);
        else q.push(x);
    }
    cout << "<";
    int length = ans.size();
    for(int i=0;i<length-1;i++)
    {
        cout << ans.front() << "," << " ";
        ans.pop();
    }
    cout << ans.front() << ">";
}