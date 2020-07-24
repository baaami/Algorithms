#include <iostream>
#include <cstring>
#define MAX 101
using namespace std;
int n, k;
// dp[n][k] : n비트 중에서 인접한 비트의 개수가 k인 수열의 개수
int dp[MAX][MAX][2];		

int solution(int len, int total, int bit)
{
	// 기저 사례
	if (len >= n || total > k)
		return 0;
	if (len == n - 1 && total == k)
		return 1;
	int& result = dp[len][total][bit];
	if (result != -1)
		return result;

	return result = solution(len + 1, total, 0) + solution(len + 1, total + bit * 1, 1);
}

int main()
{
	int t; cin >> t;

	while (t--)
	{
		cin >> n >> k;
		memset(dp, -1, sizeof(dp));

		cout << solution(0, 0, 0) + solution(0, 0, 1) << endl;
	}
	return 0;
}