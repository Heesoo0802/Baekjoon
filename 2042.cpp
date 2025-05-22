#include <iostream>
#include <cmath>
#include <vector>
#define int long long
using namespace std;
int N, M, K;
int bsize;
vector <int> v;
vector <int> bucket;
void f(int a, int b, int c)
{
    if(a == 1) 
    {
        bucket[b/bsize] = bucket[b/bsize] - v[b] + c;
        v[b] = c;
        return;
    }
    else 
    {
        int sum = 0;
        for(int i=b;i<=c;)
        {
            if(i%bsize == 0 && i+bsize <= c) 
            {
                sum += bucket[i/bsize];
                i += bsize;
            }
            else 
            {
                sum += v[i];
                i++;
            }
        }
        cout << sum << endl;
        return;
    }
}
signed main()
{
    cin >> N >> M >> K;
    bsize = sqrt(N);
    v.resize(N);
    bucket.resize(N/bsize + 1);
    for(int i=0;i<N;i++)
    {
        cin >> v[i];
        bucket[i/bsize] += v[i];
    }
    while(M > 0 || K > 0)
    {
        int x, y, z;
        cin >> x >> y >> z;
        y--;
        if(x == 2) z--;
        f(x, y, z);
        if(x == 1) M--;
        else K--;
    }
}