#include <iostream>
#define int long long
using namespace std;
int N;
int dp[31][2];
signed main()
{
    cin >> N;
    if(N%2 != 0)
    {
        cout << "0" << endl;
        return 0;
    }
    dp[2][0] = 3;
    dp[2][1] = 1;

    for(int i=4;i<=N;i+=2)
    {
        dp[i][1] = dp[i-2][0] + dp[i-2][1];
        dp[i][0] =  dp[i-2][0] + dp[i][1] * 2;
    }
    cout << dp[N][0] << endl;
    return 0;
}