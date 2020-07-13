#include <iostream>
#include <cstring>
#define MAX 100
using namespace std;
int n;
int a[MAX + 1][MAX + 1];
bool check[MAX + 1][MAX + 1];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
void dfs(int i, int j, int limit)
{
	if (i < 0 || j < 0 || i >= n || j >= n) return;
	check[i][j] = true;
	for(int k = 0; k < 4; k++)
	{
		int x = i + dx[k];
		int y = j + dy[k];
		if (!check[x][y] && a[x][y] > limit)
		{
			dfs(x, y, limit);
		}
	}
}
int main()
{
	cin >> n;
	int cmax = -1;
	memset(check, false, sizeof(check));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
			if (a[i][j] > cmax) cmax = a[i][j];
		}
	}
	int limit = 0;
	int ans = 0;
	while (limit <= cmax)
	{
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				// 방문하지 않은 곳이고, 물이 차지 않은 안전 영역이면 방문
				if (!check[i][j] && a[i][j] > limit)
				{
					dfs(i, j, limit);
					cnt++;
				}
			}
		}
		if (cnt > ans) ans = cnt;
		memset(check, false, sizeof(check));
		limit++;
	}
	cout << ans;
	return 0;
}