#include <iostream>
#include <cstring>
using namespace std;
int a[1001];
int dp[10001];
int main()
{
	int n; cin >> n;
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++) cin >> a[i];

	dp[1] = 1;
	// 점프했을 때 아무곳도 못가는 경우면 끝내줘야한다.
	for (int i = 1; i < n; i++)
	{
		if (dp[i] == 0) break;
		for (int j = 1; j <= a[i]; j++)		// 갈 수 있는 칸
		{
			if (i + j > 1000) break;
			if (dp[i + j] > dp[i] + 1 || dp[i + j] == 0)
			{
				dp[i + j] = dp[i] + 1;
			}
		}
	}
	if (dp[n] == 0) cout << -1;
	else cout << dp[n] - 1;
	return 0;
}