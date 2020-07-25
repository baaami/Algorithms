#include <iostream>
#include <algorithm>
#include <cstring>
#define MAXINF 987654321
#define MAX 100001
using namespace std;
int n, t;
int graph[MAX][4];		// (1, 1) 부터 시작할 것이다.
int dp[MAX][4];			// idx행, column열까지 가능 최소 비용
/*
	삼각 그래프

	의미 : N 행 3 열로 이루어진 그래프
	목표 : 1행 가운데 정점 -> N행 가운데 정점까지의 최소 비용을 계산

	제약

	1. 간선이 아니라 정점에 비용이 있음 ( 제약(?) 은 아니고 조건 )
*/

// 아래, 오른쪽 아래, 왼쪽 아래, 오른쪽
int dx[] = { 1, 1, 1, 0 };
int dy[] = { 0, 1, -1, 1 };
int solution(int idx, int column)
{
	// 기저 사례
	if (idx > n || column > 3) return MAXINF;

	// 도착
	if (idx == n && column == 2) return graph[n][2];

	int& result = dp[idx][column];
	if (result != -1)
		return result;

	result = MAXINF;
	// 가는 방향이 총 4개 
	for (int k = 0; k < 4; k++)
	{
		int next_x = idx + dx[k];
		int next_y = column + dy[k];

		// 그래프 범위 내에 있는 경우
		if (next_x >= 1 && next_x <= n && next_y >= 1 && next_y <= 3)
		{
			 result = min(result, graph[idx][column] + solution(next_x, next_y));
		}
	}
	return result;
}

int main()
{
	int test_case = 0;
	int onemore;
	while (1)
	{
		cin >> n;
		if (n == 0)
			break;
		// 정점 비용 값을 담아봅시다
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= 3; j++)
				cin >> graph[i][j];

		memset(dp, -1, sizeof(dp));
		cout << ++test_case << ". " << solution(1, 2) << endl;
	}

	return 0;
}