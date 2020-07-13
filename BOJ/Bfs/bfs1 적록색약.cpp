#include <iostream>
#include <queue>
#include <vector>
#include <cstring>		// memset
#define MAX 100
using namespace std;

int n;
char a[MAX + 1][MAX + 1];
bool check[MAX + 1][MAX + 1];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

void bfs(int _x, int _y)
{
	queue<pair<int, int>> q;
	check[_x][_y] = true;
	q.push(make_pair(_x, _y));
	// 현재 위치 색깔
	char color = a[_x][_y];

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int k = 0; k < 4; k++)
		{
			int next_x = x + dx[k];
			int next_y = y + dy[k];

			if (next_x < n && next_x >= 0 && next_y < n && next_y >= 0)
			{
				if (!check[next_x][next_y] && color == a[next_x][next_y])
				{
					check[next_x][next_y] = true;
					q.push(make_pair(next_x, next_y));
				}
			}
		}
	}
}

int main()
{
	cin >> n;
	char input;
	int cnt = 0;
	memset(check, false, sizeof(check));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!check[i][j])
			{
				bfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt << " ";
	memset(check, false, sizeof(check));
	cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] == 'G')
				a[i][j] = 'R';
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!check[i][j])
			{
				bfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}