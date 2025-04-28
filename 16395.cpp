#include <iostream>
using namespace std;
int f(int N, int K)
{
    if(N < K) return 0;
    if(N < 0 || K < 0) return 0;
    if(K == 0 || N == K) return 1;
    return f(N-1, K-1) + f(N-1, K);
}
int main()
{
    int n, k;
    cin >> n >> k;
    cout << f(n-1, k-1);
}