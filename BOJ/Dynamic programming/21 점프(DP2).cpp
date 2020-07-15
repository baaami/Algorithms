#include <iostream>
// 중복된 검사를 너무 많이하는 문제이다.
using namespace std;
int n;
int a[100][100];
long long dp[100][100];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}

	dp[0][0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] == 0) continue;
			if (j + a[i][j] < n)
			{
				dp[i][j + a[i][j]] += dp[i][j];
			}

			if (i + a[i][j] < n)
			{
				dp[i + a[i][j]][j] += dp[i][j];
			}
		}
	}

	cout << dp[n - 1][n - 1] << '\n';
	return 0;
}