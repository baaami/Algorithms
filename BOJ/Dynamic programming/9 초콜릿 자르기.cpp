#include <iostream>

using namespace std;

int dp[90001];

int main()
{
	int n, m; 
	int a, b;
	scanf("%d %d", &n, &m);
	int t = n * m;

	dp[1] = 0;
	
	for (int i = 2; i <= t; i++)
	{
		a = i / 2;
		b = i - a;
		dp[i] = dp[a] + dp[b] + 1;
	}

	cout << dp[t];
	return 0;
}