#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 1001
using namespace std;
int n;
int people[MAX]; 
int dp[MAX];				\
int solution(int age)
{
	if (age == n + 1) return 0;

	int& result = dp[age];
	if (result != -1)
		return result;

	result = 0;
	int low = 10001, high = -1;

	for (int i = age; i <= n; i++)
	{
		low = min(low, people[i]);
		high = max(high, people[i]);

		result = max(result, (high - low) + solution(i + 1));
	}
	return result;
}

/*
	문제

	선생님이 조를 잘 짜야하고, 학생들의 점수가 주어졌을 때, 조가 잘 짜여진 정도의 최댓값을 구해야한다.
	잘하는 학생들과 덜 잘하는 학생들을 같은 조로 묶어야 한다.

	제약 조건

	1. 같은 조에 속하게 된 학생들의 나이 차이가 많이 날 경우에 오히려 부정적인 효과가 난다.
	2. 나이차이가 가장 안나면서, 점수 차이가 많이나야 한다.
	
	평가 지표
	
	잘 짜여진 정도 : 가장 점수가 높은 학생의 점수, 가장 점수가 낮은 학생의 점수 차이
*/

int main()
{
	cin >> n; memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; i++)
		cin >> people[i];

	cout << solution(1);

	return 0;
}