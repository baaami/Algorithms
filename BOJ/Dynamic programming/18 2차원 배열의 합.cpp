#include <iostream>
using namespace std;

int n, m, t;
int a[301][301];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long ans = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
		}
	}
	cin >> t;
	while (t--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = x1; i <= x2; i++)
		{
			for (int j = y1; j <= y2; j++)
			{
				ans += a[i][j];
			}
		}
		cout << ans << endl;
		ans = 0;
	}
	return 0;
}