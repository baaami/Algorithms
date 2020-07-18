#include <iostream>
using namespace std;
// 0011, 1111, 1112, 1122, 2223 등 줄어들지 않는 숫자이다.
// n자리 수의 줄어들지 않는 수를 구해라
int n;
long long dp[65][10];			// 1 <= n <= 64
					// dp[n]은 n자리 수의 줄어들지 않는 수의 개수
int main()
{
	int t; cin >> t;
	for (int i = 0; i < 10; i++)
	{
		dp[1][i] = 1;
	}
	for (int i = 2; i <= 64; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 9; k >= j; k--)
			{
				dp[i][j] += dp[i - 1][k];
			}
		}
	}

	while (t--)
	{
		cin >> n;
		long long ans = 0;
		for (int i = 0; i < 10; i++)
		{
			ans += dp[n][i];
		}
		cout << ans << endl;
	}
	return 0;
}