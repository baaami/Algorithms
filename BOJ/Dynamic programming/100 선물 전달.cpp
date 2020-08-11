#include <iostream>
#include <cstdio>
using namespace std;

const long long MOD = 1000000000;

long long dp[1000002];

int main()
{
    dp[1] = 0;
    dp[2] = 1;
    int n;
    cin >> n;

    for (int i = 3; i <= n; i++)
        dp[i] = (i - 1) * (dp[i - 2] + dp[i - 1]) % MOD;
    cout << dp[n];
    return 0;
}
