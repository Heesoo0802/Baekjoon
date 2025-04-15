#include <iostream>
#include <queue>
#define int long long 
using namespace std;
struct counter
{
    int cn; //counter number
    int ts; //time sum
};
struct comp
{
    bool operator()(counter a, counter b)
    {
        if(a.ts == b.ts) return a.cn > b.cn;
        return a.ts > b.ts; //priority queue front = min
    }
};
signed main()
{
    int n, c;
    cin >> n >> c;
    priority_queue <counter, vector<counter>, comp> pq;
    for(int i=0;i<c;i++)
    {
        int time;
        cin >> time;

        if(i<n) // i = 0 ~ n-1
        {
            pq.push({i+1, time});
            cout << i+1 << " ";
        }
        else
        {
            counter top = pq.top();
            pq.pop();
            pq.push({top.cn, top.ts + time});
            cout << top.cn << " ";
        }
    }
}