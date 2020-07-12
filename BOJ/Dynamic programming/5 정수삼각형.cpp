#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
int a[501][501];
int _max = -1;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> a[i][j];
		}
	}
	
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i; ++j)
		{
			if (j == 1) a[i][j] += a[i - 1][j];
			else if (j == n) a[i][j] += a[i - 1][j - 1];	// 오버 플로우 방지용
			else a[i][j] += max(a[i - 1][j], a[i - 1][j - 1]);
		}
	}

	for (int i = 1; i <= n; i++)
	{
		_max = max(_max, a[n][i]);
	}
	cout << _max;
	return 0;
}