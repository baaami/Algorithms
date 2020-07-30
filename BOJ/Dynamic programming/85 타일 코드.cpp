#include <iostream>
#include <cstring>
#define MAX 31
using namespace std;
int n; long long dp[MAX];
long long solution(int width)
{
	// 기저 사례
	if (width <= 1)
		return 1;

	long long& result = dp[width];
	if (result != -1)
		return result;

	// 밑변이 2인 경우 (2 * 2, 2 * 1), 밑변이 1인경우 ( 1 * 2 )
	result = 2 * solution(width - 2) + solution(width - 1);
	return result;
}

int main()
{
	cin >> n;
	memset(dp, -1, sizeof(dp));
	int result = 0;

	// (중복 + 중복 + 중복x + 중복x ) / 2 = 중복 + 중복x 이므로,

	// 홀수이면 가운데 1 * 2 짜리 하나가 있고 좌우 대칭인 경우
	if (n % 2)
		result = (solution(n) + solution(n / 2)) / 2;
	// 짝수이면 가운데 1 * 2 짜리 두 개 혹은 2 * 2짜리 하나 넣고 좌우 대칭
	// 2 * solution(n / 2 - 1)
	// 혹은 반으로 나누었을 때 양 옆이 대칭
	// solution(n / 2)
	else
		result = ((solution(n) + (solution(n / 2)) + 2 * solution(n / 2 - 1))) / 2;

	cout << result;

	return 0;
}