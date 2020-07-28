#include <iostream>
#include <algorithm>
#include <cstring>
#define MAXLEN 201
#define INF 987654321
using namespace std;
int n, k;
int map[MAXLEN];
// 주어진 조건 하에 dp[left][right]는 [left, right] 구간의 전구 색을 전부 
// 같은 색으로 만들 수 있는 경우의 최솟값
int dp[MAXLEN][MAXLEN];
/*
	1. 목표 : 모든 전구의 색이 하나로 같아질 때까지 최소 몇번 전구의 색을 바꾸어야 하는지를 구하자.

	2. 조건

	각 전구의 색깔을 바꿀 수 있는데, 하나의 전구 색을 바꾸는 경우!

	-> 색이 바뀌는 전구에 인접한 전구가 같은 색이면, 이 전구의 색도 같이 바뀌게 되며
	   인접한 전구가 다른 색이 나올 때까지 계속 바뀌게 된다
*/

int solution(int left, int right)
{
	if (left == right) return 0;
	int& result = dp[left][right];
	if (result != -1)
		return result;
	result = INF;
	for (int i = left; i < right; i++)
	{
		int temp = (map[left] != map[i + 1] ? 1 : 0);
		result = min(result, solution(left, i) + solution(i + 1, right) + temp);
	}
	return result;
}

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> map[i];
	memset(dp, -1, sizeof(dp));
	cout << solution(1, n);
	return 0;
}