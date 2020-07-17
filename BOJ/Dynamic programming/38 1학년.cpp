#include <iostream>
using namespace std;
int a[101] = { 0 };
long long dp[101][21] = { 0 };
int main()
{
	int n; cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	dp[1][a[1]]++;
	for (int i = 2; i < n; i++)
	{
		for (int j = 0; j <= 20; j++)
		{
			if (dp[i - 1][j])			// 0 ~ 20중 지금 까지 계산해오던 부분만 계산 해나가면 된다.
			{							// 결국 여기서는 j 값이 계산해오던 값이들이다.
				if (j + a[i] <= 20) dp[i][j + a[i]] += dp[i - 1][j];
				if (j - a[i] >= 0) dp[i][j - a[i]] += dp[i - 1][j];
			}
		}
	}

	cout << dp[n - 1][a[n]] << endl;
	return 0;
}
/*
11
8 3 2 4 8 7 2 4 0 8 8
*/