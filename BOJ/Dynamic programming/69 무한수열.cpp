#include <iostream>
#include <map>
using namespace std;
// 0 <= n <= 10^12
long long n, p, q;
map<long long, long long> dp;

long long solution(long long N)
{
	if (dp.count(N))
	{
		return dp[N];
	}
	else
		return dp[N] = solution(N / p) + solution(N / q);
}

int main()
{
	cin >> n >> p >> q;

	// n이 10^12이 되면 dp 배열 크기를 초과할것이다.
	dp[0] = 1;
	cout << solution(n);
	return 0;
}