#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[1001];
int dp1[1001];			// d[i]는 i 번째 수열까지 가장 큰 증가하는 부분 수열
int _max = -1;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		dp1[i] = a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (a[i] > a[j] && dp1[j] + a[i] > dp1[i])
			{
				dp1[i] = dp1[j] + a[i];
			}
		}
	}

	cout << *max_element(dp1 + 1, dp1 + n + 1);
	return 0;
}