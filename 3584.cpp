#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int parent[10001] = {};
        int visited[10001] = {};
        int N;
        int a, b;
        cin >> N;
        for(int i=0;i<N-1;i++)
        {
            int x, y;
            cin >> x >> y;
            parent[y] = x;
        }
        cin >> a >> b;
        
        int now = a;
        while(now != 0)
        {
            visited[now] = 1;
            now = parent[now];
        }

        now = b;
        while(now != 0)
        {
            if(visited[now] == 1) 
            {
                cout << now << endl;
                break;
            }
            now = parent[now];
        }
    }
}