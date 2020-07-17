#include <iostream>
#include <cstring>
using namespace std;
int n, m, k;
int a[16][16];
int dp[16][16];
int main()
{
	cin >> n >> m >> k;
	if (k)
	{
		int mid_i, mid_j;
		// 1번째 칸부터 n*m 칸 까기 차례로 채웁니다.
		int count = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				count++;
				// 현재 칸이 k번째 칸이면 mid_i, mid_j를 갱신해줍니다.
				if (count == k) {
					mid_i = i;
					mid_j = j;
				}
			}
		}
		dp[1][1] = 1;
		for (int i = 1; i <= mid_i; i++) {
			for (int j = 1; j <= mid_j; j++) {
				if (i == 1 && j == 1) continue;
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		int mid = dp[mid_i][mid_j];

		memset(dp, 0, sizeof(dp));
		dp[mid_i][mid_j] = 1;
		for (int i = mid_i; i <= n; i++)
		{
			for (int j = mid_j; j <= m; j++)
			{
				if (i == mid_i && j == mid_j) continue;
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		cout << mid * dp[n][m];
	}
	else {
		dp[1][1] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (i == 1 && j == 1) continue;
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		cout << dp[n][m];
	}
	return 0;
}