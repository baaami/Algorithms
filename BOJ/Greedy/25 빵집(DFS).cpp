#include <iostream>

using namespace std;

int r, c;
char a[10001][501];
bool check[10001][501];
int cnt = 0;
bool dfs(int i, int j)
{
	if (j == c - 1)
	{
		return true;
	}
	int dx[] = { -1, 0 , 1 };
	int dy[] = { 1, 1, 1 };
	for (int k = 0; k < 3; k++)
	{
		int x = i + dx[k];
		int y = j + dy[k];
		if (0 <= x && x < r && 0 <= y && y < c)
		{
			if (check[x][y] == false && a[x][y] == '.')			// 이면 탐색
			{
				check[i][j] = true;
				bool flag = dfs(x, y);
				if (flag) return flag;
			}
		}
	}
	return false;			// 여기까지 오면 잘못된 부분
}
int main()
{
	cin >> r >> c;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> a[i][j];
			check[i][j] = false;
		}
	}

	for (int i = 0; i < r; i++) cnt += dfs(i, 0);

	cout << cnt << endl;
	return 0;
}