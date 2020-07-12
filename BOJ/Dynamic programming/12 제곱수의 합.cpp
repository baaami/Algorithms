#include <iostream>
#include <algorithm>
using namespace std;
int n;
int dp[100001];

// 0이 8 개면 1억으로, 시간초과조심
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	dp[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j * j <= i; j++)
		{
			if (dp[i] > dp[i - j * j] + 1 || dp[i] == 0)
			{
				dp[i] = dp[i - j * j] + 1;
			}
		}
	}
	cout << dp[n];
	
	return 0;
}