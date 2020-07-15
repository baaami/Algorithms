#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int MAX = 1000;
int n, m;
int arr[MAX][MAX];
int dp[MAX][MAX];

int get_area()
{
	int side = 0;	// 현재 변의 최대 길이
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			// 세방향 확인할 수없는 경우
			if (i == 0 || j == 0)
				dp[i][j] = arr[i][j];
			else if (arr[i][j] == 1)
				// 왼쪽, 왼쪽위, 위 방향을 확인 한 후 최소값 + 1
				dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j - 1]), dp[i - 1][j]) + 1;
			side = max(side, dp[i][j]);
		}
	}
	return side * side;
}

int main()
{
	scanf("%d %d", &n, &m);
	if (n < 1 || n > 1000 || m < 1 || m >1000)
		exit(-1);

	for (int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			scanf("%1d", &arr[i][j]);

	printf("%d\n", get_area());
	return 0;
}