#include <iostream>
#include <queue>
using namespace std; int dp[41];
int main()
{
	int ans = 1;
	int n, m, index; cin >> n >> m;
	queue<int> vip;
	for (int i = 1; i <= m; i++)
	{
		int value; cin >> value;
		vip.push(value);
	}
	dp[0] = 1; dp[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	index = 1;
	int until, bit;
	while (!vip.empty())
	{
		until = vip.front(); vip.pop();
		ans *= dp[until - index];			// 비트 개수
		index = until + 1;
	}

	ans *= dp[n + 1 - index];
	cout << ans;
	return 0;
}