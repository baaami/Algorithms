#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define MININF -98765321
#define MAX 101
using namespace std;
// n 개의 수로 이루어진 1차원 배열
// m 개의 구간을 선택해서 구간에 속한 수들의
int n, m;
int a[MAX];
// dp[i][m][2] 는 i 위치를 m 구간에 [1] 포함시킨 경우,[0] 안 포함시킨경우
int dp[MAX][MAX / 2][2];

void initialize()
{
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX / 2; j++)
			for (int k = 0; k < 2; k++)
				dp[i][j][k] = MININF;
}

int solution(int idx, int term, bool choice)
{
	// 조건 충족 ( 구간을 다 채운 경우 )
	if (term == m) return 0;

	// 기저 사례
	if (idx == n + 1)
	{
		// 마지막 구간을 고르면 조건 충족
		if (term == m - 1 && choice)
		{
			return 0;
		}
		else {
			// 못 고르면 최솟값 내보내기
			return -32768 * 100;
		}
	}

	int& result = dp[idx][term][choice];
	if (result != MININF)
		return result;

	// 새로운 구간 ( choice안 한 경우)
	if (!choice)
	{
		// 그냥 지나치기 , idx부터 시작하기
		return result = max(solution(idx + 1, term, false), a[idx] + solution(idx + 1, term, true));
	}
	else {
		// 구간 끝내기 (idx - 1 까지만 선택한 경우) , 기존 구간에 추가하기
		return result = max(solution(idx + 1, term + 1, false), a[idx] + solution(idx + 1, term, true));
	}
}

int main()
{
	cin >> n >> m;
	// MININF를 쓰는 이유는 구간값이 -32768까지 주어지기때문
	// memset(dp, -1, sizeof(dp)); <- -1이하는 memset이 적용이 불가하다.
	initialize();
	// m개의 구간을 선택해서 구간에 속한 수들의 총합이 최대가 되게 해야한다.
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	cout << solution(1,0,false) << endl;
}