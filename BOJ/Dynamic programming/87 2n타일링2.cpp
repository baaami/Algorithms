#include <iostream>
#include <cstring>
#include <algorithm>
#define MOD 10007
#define MAX 1001
// https://www.acmicpc.net/problem/11726
int n, t;
long long dp[MAX];
using namespace std;

long long solution(int width)
{
	if (width <= 1)
		return 1;

	long long& result = dp[width];
	if (result != -1)
		return result;

	result = 0;
	return result = (((solution(width - 2) * 2) % MOD)  + (solution(width - 1) % MOD)) % MOD;
}

int main()
{
	cin >> n;
	memset(dp, -1, sizeof(dp));
	cout << solution(n) << endl;


	return 0;
}