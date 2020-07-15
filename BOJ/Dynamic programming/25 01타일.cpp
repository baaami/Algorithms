#include <cstdio>
#define MOD 15746
using namespace std;
long long dp[1000001];

int main()
{
	int n;
	scanf("%d", &n);
	
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++)
		dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
	
	printf("%lld\n", dp[n]);
	return 0;
}