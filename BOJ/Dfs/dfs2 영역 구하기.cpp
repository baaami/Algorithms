#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 100
using namespace std;
int m, n, k;
bool check[MAX + 1][MAX + 1];
int result = 0;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0, 1, -1 };
void dfs(int x, int y)
{
	result++;
	check[x][y] = true;
	for (int k = 0; k < 4; k++)
	{
		int next_x = x + dx[k];
		int next_y = y + dy[k];
		if (next_x < m && next_x >= 0 && next_y < n && next_y >= 0)
		{
			if (!check[next_x][next_y])
				dfs(next_x, next_y);
		}
	}
}

int main()
{
	int cnt = 0;
	vector<int> size;
	cin >> m >> n >> k;
	memset(check, false, sizeof(check));
	int x1, y1; int x2, y2;
	for (int i = 0; i < k; i++)
	{
		cin >> y1 >> x1 >> y2 >> x2;

		for (int j = y1; j < y2; j++)
		{
			for (int k = x1; k < x2; k++)
			{
				check[k][j] = true;
			}
		}
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			// 방문하지 않은 곳 방문 하기
			if (!check[i][j])
			{
				dfs(i, j);
				size.push_back(result);
				result = 0;
				cnt++;
			}
		}
	}

	cout << cnt << endl;
	sort(size.begin(), size.end());
	for (int i = 0; i < size.size(); i++)
	{
		cout << size[i] << " ";
	}
	return 0;
}