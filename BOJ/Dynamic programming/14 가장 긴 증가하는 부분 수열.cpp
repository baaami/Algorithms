#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[1001];
int dp[1001];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	// 길이가 가장 길어야 한다.
	for (int i = 1; i <= n; i++)
	{
		dp[i] = 1;
		for (int j = 1; j <= i; j++)
		{
			if (a[j] < a[i] && dp[i] < dp[j] + 1)
			{
				dp[i] = dp[j] + 1;
			}
		}
	}

	cout << *max_element(dp + 1, dp + n + 1);
	return 0;
}