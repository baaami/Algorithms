#include <iostream>
#include <algorithm>
#include <cstring>
#define  MAX 50000
using namespace std;
int total, sub;
int seat[MAX + 1];
int dp[3][MAX + 1];		// n 개의 객차까지 k개의 소형기관차가 최대로 운송할 수 있는 손님의 수
// https://www.acmicpc.net/problem/2616
// 기관사가 끌고 가던 객차의 수와 각 객차에 타고 있던 손님의 수.
// 소형 기관차가 최대로 끌 수 있는 객차의 수가 주어질 때
// 소형 기관차 3대가 최대로 운송할 수 있는 손님의 수를 구하여라
// ( 소형 기관차는 번호가 연속적으로 이어진 객차를 끌 수 있다. )

// 알고리즘
// 해당 칸을 끌고 가지 않거나
// 해당 칸을 최대 끌 수 있는만큼 끌고 간다.

int solution(int trainnum, int idx)			// train number, n 객차까지
{
	// 기저 사례
	if (trainnum == 3 || idx >= total) return 0;

	int& result = dp[trainnum][idx];
	if (result != -1) return result;

	result = 0;

	if (idx + sub - 1 <= total)
	{
		int x, y = 0;
		for (x = idx; x < idx + sub; x++)
		{
			y += seat[x];
		}
		// idx 번째 객차를 안 고르는 경우, 고르는 경우
		// 최댓값을 찾는 경우 다음과 같이 연산을 통해서 return해서 큰 값을 result에 넣어준다.
		result = max(solution(trainnum, idx + 1), solution(trainnum + 1, idx + sub) + y);
	}
	return result;
}

int main()
{
	cin >> total;
	for (int i = 1; i <= total; ++i)
		cin >> seat[i];
	cin >> sub;

	memset(dp, -1, sizeof(dp));
	cout << solution(0, 1);

	return 0;
}