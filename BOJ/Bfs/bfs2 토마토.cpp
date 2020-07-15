#include <iostream>
#include <queue>
#define MAX 100 + 1
using namespace std;
struct loc{
	int x;
	int y;
	int z;
	int day;
}typedef location;
int a[MAX][MAX][MAX];
bool check[MAX][MAX][MAX];
int dx[] = { 1, -1, 0, 0, 0, 0 };
int dy[] = { 0, 0, 1, -1, 0, 0 };
int dz[] = { 0, 0, 0,  0 ,1,-1 };
// https://www.acmicpc.net/problem/7569
// 1 : 익은 토마토
// 0 : 익지 않은 토마토
// -1 : 토마토가 들어있지 않은 칸
// 상자가 위아래로도 있다.

int m, n, h
int main()
{
	location cur;
	queue<location> q;
	int ans = 0;
	// 토마토가 격자에 있는 경우 전부 익었는지 확인해줄 변수
	int cnt = 0;
	cin >> m >> n >> h;
	for (int k = 0; k < h; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> a[i][j][k];
				if (a[i][j][k] == 1)
				{
					cur.x = i; cur.y = j; cur.z = k; cur.day = 0;
					q.push(cur);
				}
				if (a[i][j][k] != 0)
				{
					cnt++;
					check[i][j][k] = true;
				}
			}
		}
	}
	// 더이상 익을 토마토가 없는 경우
	if (cnt == n * m * h)
	{
		cout << ans;
		return 0;
	}

	while (!q.empty())
	{
		int _x = q.front().x;
		int _y = q.front().y;
		int _z = q.front().z;
		int _day = q.front().day;
		q.pop();

		for (int k = 0; k < 6; k++)
		{
			int next_x = _x + dx[k];
			int next_y = _y + dy[k];
			int next_z = _z + dz[k];
			int next_day = _day + 1;
			if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m && next_z >= 0 && next_z < h)
			{
				if (check[next_x][next_y][next_z] != true)
				{
					cnt++;
					check[next_x][next_y][next_z] = true;
					cur.x = next_x;
					cur.y = next_y;
					cur.z = next_z;
					cur.day = next_day;
					q.push(cur);
				}
			}
		}
	}

	if (cnt < n * h * m)
		cout << -1;
	else {
		cout << cur.day;
	}
	return 0;
}