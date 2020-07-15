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

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == 0 && j == 0) continue;

			for (int k = 1; k <= j; k++)
			{
				if (k + a[i][k] == j)
				{
					dp[i][j] += dp[i][k];
				}
			}

			for (int k = 1; k <= i; k++)
			{
				if (k + a[k][j] == i)
				{
					dp[i][j] += dp[k][j];
				}
			}
		}
	}

	cout << dp[n - 1][n - 1] << '\n';
	return 0;
}