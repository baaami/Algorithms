#include <iostream>
#define MOD 1000000003
#define MAX 1000
using namespace std;
int n, k; int dp[MAX + 1][MAX + 1];
int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		dp[i][0] = 1;
		dp[i][1] = i;								// dp[i][1]은 i가 된다.
	}
	// i 번째 칸을 칠하는 경우 = dp[i - 2][j - 1]
	// i 번째 칸을 안 칠하는 경우 = dp[i - 1][j]
	// dp[i][j] = dp[i - 2][j - 1] + dp[i - 1][j]
	for (int i = 2; i <= n; i++)
	{
		for (int j = 2; j <= n; j++)
		{
			dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % MOD;
		}
	}

	// n번째 칸을 칠하는 경우
	// 1번칸, n - 1번째 칸을 칠하면 안되니까 2 ~ N - 2번째 칸 까지  K - 1 개의 색을 인접하지 않게 칠하는 경우이므로
	// n - 3인 이유는 n개의 색상환중에 1, n - 1, n 을 뺀 나머지 색들 중  k - 1개가 색칠되어야 하므로
	// dp[N - 3][K - 1] 이다.

	// n번째 칸을 칠하지 않는 경우
	// 1 ~ (N - 1) 번째 칸까지 K개의 색을 인접하지 않게 색칠하는 경우이므로
	// dp[n - 1][k]
	cout << (dp[n - 3][k - 1] + dp[n - 1][k]) % MOD;
	return 0;
}