#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 1001
#define MOD 1000000
using namespace std;
//https://www.acmicpc.net/problem/1563
int n;
// dp[n][i][j] , n일 중에 i번 지각, "연속" j 번 결석을 한 경우
// 배열은 전부 가독성 좋게 인덱스 1부터 시작하기로 했다.
long long dp[MAX][3][4];
/*
	O : 출석, L : 지각, A : 결석

	개근상 못 받는 조건

	-> 지각을 두 번 이상 or 결석 세 번 연속으로 한 사람

	1 학기는 N일이다.
	-> N이 주어졌을 때 개근상을 받을 수 있는 출결정보의 개수를 세는 프로그램을 작성하라

	접근 방식

	1. 출석, 지각 , 결석을 각 각 보기 편하게 0 , 1 , 2 의 숫자로 바꾼다.

	2. N중에 1이 총 두 번 or 2가 연속 3번 있는 경우 개근 상을 못 받는다.
*/

long long solution(int day, int late, int absent)
{
	if (day == n)
	{
		if (late == 2 || absent == 3)
			return 0;
		else
			// 개근상 받는 경우
			return 1;
	}
	// 개근상 못 받는 경우
	if (late == 2 || absent == 3) return 0;

	long long& result = dp[day][late][absent];
	if (result != -1)
		return result;

	result = 0;
	// 결석을 한 경우
	//result += solution(day + 1, late, absent + 1);
	// 결석은 연속적이어야하므로 결석하지 않은 날 (지각 or 정상 출석)
	// 은 결석을 0으로 초기화해준다.
	// 지각을 한 경우
	//result += solution(day + 1, late + 1, 0);
	// 지각, 결석 둘다 안한 경우
	//result += solution(day + 1, late, 0);
	
	return result += (solution(day + 1, late, absent + 1) + solution(day + 1, late + 1, 0)
		+ solution(day + 1, late, 0)) % MOD;
}

int main()
{
	cin >> n;
	memset(dp, -1, sizeof(dp));
	// 첫날 정상 출석한 경우, 지각한 경우, 결석한 경우를 전부 더해준다.
	cout << (solution(1, 0, 0) + solution(1, 0, 1) + solution(1, 1, 0)) % MOD;
	return 0;
}