#include <stdio.h>
int get_max(int x, int y) { return x > y ? x : y; }
int get_min(int x, int y) { return x < y ? x : y; }
int a[3];
int dp[100001][3];
int dp2[100001][3];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d %d", &a[0], &a[1], &a[2]);
		dp[i][0] = get_max(dp[i - 1][0], dp[i - 1][1]) + a[0];
		dp[i][1] = get_max(get_max(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]) + a[1];
		dp[i][2] = get_max(dp[i - 1][1], dp[i - 1][2]) + a[2];

		dp2[i][0] = get_min(dp2[i - 1][0], dp2[i - 1][1]) + a[0];
		dp2[i][1] = get_min(get_min(dp2[i - 1][0], dp2[i - 1][1]), dp2[i - 1][2]) + a[1];
		dp2[i][2] = get_min(dp2[i - 1][1], dp2[i - 1][2]) + a[2];
	}
	printf("%d %d\n", get_max(get_max(dp[n][0], dp[n][1]), dp[n][2]), get_min(get_min(dp2[n][0], dp2[n][1]), dp2[n][2]));
	return 0;
}
