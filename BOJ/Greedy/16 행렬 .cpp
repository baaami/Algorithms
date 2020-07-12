#include <iostream>
#include <vector>

using namespace std;

int a[50][50];
int b[50][50];

void conv(int i, int j)
{
	for(int c = i; c < i + 3; c++)
	{
		for (int d = j; d < j + 3; d++)
		{
			if (a[c][d] == 1)
			{
				a[c][d] = 0;
			}
			else {
				a[c][d] = 1;
			}
		}
	}
	return;
}

int main()
{
	int n, m; cin >> n >> m;
	int cnt(0);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &a[i][j]);			// 정수 1개씩 받아온다.
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%1d", &b[i][j]);			// 정수 1개씩 받아온다.
		}
	}
	
	for (int i = 0; i < n - 2; i++)
	{
		for (int j = 0; j < m - 2; j++)
		{
			if (a[i][j] != b[i][j])
			{
				conv(i, j);
				cnt++;
			}
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] != b[i][j])
			{
				cout << -1;
				return 0;
			}
		}
	}

	cout << cnt << endl;

	return 0;
}