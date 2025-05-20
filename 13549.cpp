#include <iostream>
#include <queue>
#define int long long 
using namespace std;
int N, K;
int visited[100001];
int dx[2] = {1, -1};
queue <int> q;
signed main()
{
    cin >> N >> K;
    if(K == 0)
    {
        cout << N << endl;
        return 0;
    }
    visited[N] = 1;
    q.push(N);
    while(!q.empty())
    {
        int now = q.front();
        q.pop();

        int next = now * 2;
        if(next > 0 && next <= 100000)
        {
            if(visited[next] == 0 || (visited[next] != 0 && visited[now] < visited[next]))
            {
                q.push(next);
                visited[next] = visited[now];
            }
        }

        for(int s=0;s<2;s++)
        {
            int next = now + dx[s];
            if(next <= 0 || next > 100000) continue;
            if(visited[next] == 0 || (visited[next] != 0 && visited[now] < visited[next]))
            {
                q.push(next);
                visited[next] = visited[now] + 1;
            }
        }
    }
    cout << visited[K] - 1;
}