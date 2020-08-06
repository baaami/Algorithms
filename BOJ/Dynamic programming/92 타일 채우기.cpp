#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 31
using namespace std;
// https://www.acmicpc.net/problem/2133
/*
	제약 조건

	1. 홀수일 때는 타일을 만들 수 없다.
*/
int n;
int dp[MAX];

int solution(int width)
{
	// 기저 사례
	if (width % 2 == 1)
		return 0;
	else if (width == 0)
		return 1;
	else if (width == 2)
		return 3;

	int& result = dp[width];
	if (result != -1)
		return result;

	result = 3 * solution(width - 2);

	// 각 각 고유모양이 2개씩있다.
	for (int i = 0; i <= width - 4; i++)
		result += 2 * solution(i);

	return result;
}

int main()
{
	cin >> n;
	memset(dp, -1, sizeof(dp));
	cout << solution(n);
	return 0;
}