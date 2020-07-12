#include <iostream>
#include <cstring>
using namespace std;
int n, m;
int dp[31];

//void preCalculate()
//{
//	memset(dp, 0, sizeof(dp));
//	for (int i = 1; i < 31; i++)
//	{
//		dp[1][i] = i;			// west에 길이 하나일 때 East 만큼의 방법이있다.
//	}
//	for (int i = 2; i <= 30; i++)
//	{
//		for (int j = i; j <= 30; j++)
//		{
//			for (int k = j; k >= i; k--)
//			{
//				dp[i][j] += dp[i - 1][k - 1];
//			}
//		}
//	}
//}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;

	while (t--)
	{
		cin >> n >> m;
		for (int i = 0; i <= 30; i++)
		{
			dp[i] = 0;
		}
		dp[n] = 1;
		//dp[i] 는 i 개중 n개를 고르는 경우의 수
		for (int i = n + 1; i <= m; i++)
		{
			dp[i] = dp[i - 1] * i / (i - n);
		}

		cout << dp[m] << endl;
	}


	return 0;
}