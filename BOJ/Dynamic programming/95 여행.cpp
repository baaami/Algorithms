#include <iostream>
#include <algorithm>
#include <cstring>
#define INF 987654321
#define MAX 301
//https://www.acmicpc.net/problem/2157
using namespace std;
/*
	문제 설명

	1. N개의 섬들이 동쪽에서 서쪽으로 "순서대로" 위치해 있다.
	2. 여행 경로는 M개 이하의 도시를 1번에서 시작해서 N번 도시에서 끝나야 한다. ( M개의 도시에 포함됨 )
	3. 도시 번호가 증가하는 순서대로만 이동하기로 했다. ( 서쪽으로만 이동 )
	4. 도시마다 다른 도시로 갈 수 있는 곳이 정해져있다. 그리고 기내식 점수가 정해져있다.
	
	출력

	-> M개의 도시를 개설되어 있는 항로를 통해 가면서 먹게 되는 기내식 점수의 최댓값
*/

int n, m, k;
int a, b, c;
// route[i][j] : i -> j 로 갈 때, 기내식의 점수
int route[MAX][MAX];
// dp[i][j[vist]] : i -> j 로 갈 때까지 visit개의 도시를 지나간 경우 기내식의 최대 점수

// -> dp[cur][visit] : 현재 도시까지 vist개의 도시를 지나서 온 경우 기내식의 최대 점수
int dp[MAX][MAX];

int solution(int cur, int visit)
{
	// 기저 사례 : m개의 도시를 지났는데 n 도시에 도착하지 않은 경우
	if (visit == m && cur != n)
		return -INF;
	
	// 조건 충족
	if (cur == n)
		return 0;

	int& result = dp[cur][visit];
	if (result != -1)
		return result;
	
	result = 0;
	// 출발하는 곳에서 갈 수 있는 곳을 가본다. x
	// 한쪽방향으로만 갈 수 있다.
	for (int i = cur + 1; i <= n; i++)
	{
		// 항로가 없거나, 출발한 곳과 도착하는 곳이 같거나, 방문했던 도시라면 continue
		if (route[cur][i] == -1 || i == cur) continue;
		result = max(result, solution(i, visit + 1) + route[cur][i]);
	}

	return result;
}

int main()
{
	cin >> n >> m >> k;
	memset(dp, -1, sizeof(dp));
	memset(route, -1, sizeof(route));
	for (int i = 1; i <= k; i++)
	{
		cin >> a >> b >> c;
		// a 도시에서 b 도시로 갈 때 c 점수의 기내식을 먹을 수 있다.
		// route[1][3] 에서 중복이 일어나서 
		// 1번에서 3번으로 갈 수 있는 경로가 여러 개가 나올 수 있다는 점

		// a 에서 b로 가는 경로가 중복되어 있다면 더 기내식 점수가 높은 것만 넣는다.
		if (route[a][b] != -1)
		{
			route[a][b] = max(c, route[a][b]);
		}
		else {
			route[a][b] = c;
		}		
	}
	cout << solution(1, 1);

	return 0;
}