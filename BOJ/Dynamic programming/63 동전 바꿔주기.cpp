#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int t, k;
pair<int, int> p[100];
int dp[10001][101];

int solution(int cash, int idx)
{
	// 기저 사례
	if (cash == 0) return 1;
	if (idx >= k) return 0;
	int& result = dp[cash][idx];
	if (result != -1)
	{
		return result;
	}

	result = 0;
	// 해당 동전을 사용하지 않는 경우(i == 0) ~ n(i == p[idx].second) 개 사용하는 경우까지 돌려주기
	for (int i = 0; i <= p[idx].second; i++)
	{
		// cash는 음수가 되면 안되므로
		if (cash - (p[idx].first * i) >= 0)
			// 모든 경우의 수를 찾는 경우 기저 사례에서 정답인 경우 1을 return해줘서 전부 더해주는 방식 사용
			result += solution(cash - (p[idx].first * i), idx + 1);
	}

	return result;
}

int main()
{
	cin >> t >> k;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < k; i++)
	{
		cin >> p[i].first >> p[i].second;
	}
	cout << solution(t, 0);
	return 0;
}