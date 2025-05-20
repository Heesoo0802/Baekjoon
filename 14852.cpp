#include <iostream>
#define k 1000000007
#define int long long
using namespace std;
int N;
int dp[1000001][2];
signed main()
{
    cin >> N;
    dp[1][0] = 2;
    dp[1][1] = 1;
    dp[2][0] = 7;
    dp[2][1] = 3;
    if(N<=2) 
    {
        cout << dp[N][0];
        return 0;
    }
    for(int i=3;i<=N;i++)
    {
        dp[i][0] = ((dp[i-1][0] * 2) % k + (dp[i-1][1] * 2) % k + dp[i-2][0]) % k;
        dp[i][1] = (dp[i-1][0] + dp[i-1][1]) % k;
    }
    cout << dp[N][0] % k;
}