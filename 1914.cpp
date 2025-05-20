#include <iostream>
#include <vector>
#include <iterator>
#define int long long
using namespace std;
vector <int> v;
int N;
string rst;
void g(int num, int start, int move, int end)
{
    if(num == 0) return;
    g(num-1, start, end, move);
    rst += to_string(start) + " " + to_string(end) + "\n";
    g(num-1, move, start, end);
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    int memo = N;
    v.push_back(1);
    while(N--)
    {
        int now, next = 0;
        for(int i=v.size()-1;i>=0;i--)
        {
            now = v[i] * 2;
            now += next;

            next = now / 10;
            v[i] = now % 10;
        }
        if(next != 0) v.insert(v.begin(), next);
    }
    for(int i=v.size()-1;i>=0;i--)
    {
        if(v[i] > 0) 
        {
            v[i]--;
            break;
        }
        else v[i] = 9;
    }
    for(int i=0;i<v.size();i++)
    {
        cout << v[i];
    }
    cout << '\n';
    if(memo<=20) 
    {
        g(memo, 1, 2, 3);
        cout << rst;
    }
}