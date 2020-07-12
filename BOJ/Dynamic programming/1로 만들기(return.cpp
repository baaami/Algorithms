#include <iostream>
#include <algorithm>
#define MAX 1000000
using namespace std;

int dp[MAX + 1];

int main()
{
	int n; cin >> n;
	dp[0] = MAX + 1;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;

	for (int i = 5; i <= n; i++)
	{
		int num1(0), num2(0), num3(0);
		num1 = i - 1;
		if (i % 2 == 0)
		{
			num2 = i / 2;
		}
		if (i % 3 == 0)
		{
			num3 = i / 3;
		}
		dp[i] = min(min(dp[num1], dp[num2]), dp[num3]) + 1;
	}
	
	cout << dp[n];
	return 0;
}