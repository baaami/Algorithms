#include <iostream>
#include <cstring>
using namespace std;
int coin[21];
int dp[10001];
int main()
{
	int t; cin >> t;
	int n, m;
	while (t--)
	{
		memset(coin, 0, sizeof(coin));
		memset(dp, 0, sizeof(dp));
		cin >> n;
		int ans = 0;
		// n 가지 동전의 금액이 오름차순으로 정렬되어 주어진다.
		for (int i = 0; i < n; i++)
		{
			cin >> coin[i];	// 사용할 수 있는 화폐의 종류
		}
		cin >> m;			// coin에 있는 동전들로 만들 금액 m
		// 동전으로 만들 수 있는 모든 조합을 만들어본다?
		for (int i = 0; i < n; i++)
		{
			dp[coin[i]]++;
			for (int j = coin[i] + 1; j <= m; j++)
			{
				dp[j] = dp[j] + dp[j - coin[i]];
			}
		}
		cout << dp[m] << endl;
	}
	return 0;
}

