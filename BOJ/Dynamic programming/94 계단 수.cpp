#include <iostream>
#include <cstring>
#include <algorithm>
#define MAXLEN 100
#define MOD 1000000000
using namespace std;

int n;
// 0 ~ 9까지 모두 나왔는는지 체크
int check = (1 << 10);

// n번째 위치에 0 ~ 9까지 중 숫자가 k일 때 모두 포함된 계단 수가 총 몇개있는지 구하는 함수
int dp[MAXLEN + 1][1 << 10][10];

int solution(int len, int state, int next)
{
	if (len == n)
	{
		// 모든 수가 들어가 있다면 정답
		if ((((check - 1) << 1) + 1 == state))
			return 1;
		else
			return 0;			// 기저 사례
	}

	int& result = dp[len][state][next];
	if (result != -1)
		return result;
	result = 0;

	if (next == 0)
		result += solution(len + 1, state | (1 << 1), 1);
	else if (next == 9)
		result += solution(len + 1, state | (1 << 8), 8);
	else
		result += ((solution(len + 1, state | (1 << next + 1), next + 1))) +
		solution(len + 1, state | (1 << next - 1), next - 1);

	result %= MOD;


	return result;
}

int main()
{
	cin >> n;

	int result = 0;

	for (int i = 1; i <= 9; i++)
	{
		memset(dp, -1, sizeof(dp));
		result += solution(1, 1 << 10 | (1 << i), i);

		result %= MOD;
	}

	cout << result;
	return 0;
}
