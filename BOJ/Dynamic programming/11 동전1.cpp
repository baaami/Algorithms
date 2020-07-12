#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int coins[101];
int dp[100001] = { 0, };
int cnt = 0;

int main()
{
	// 경우의 수는 2^31 보다 작으므로 int형으로 사용해도 된다.
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> coins[i];
	}
	dp[0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = coins[i]; j <= k; j++)
		{
			if (j - coins[i] >= 0)
			{
				dp[j] += dp[j - coins[i]];			// 이 점화식이 어떻게 나왔는지
			}
		}
	}

	cout << dp[k];
	return 0;
}