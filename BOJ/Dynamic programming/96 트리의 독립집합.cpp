#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define MAX 10001
using namespace std;
int n;
int vertex[MAX];			// 정점의 가중치
vector<int> edge[MAX];		// 그래프
// dp[idx][0 or 1] : idx 노드를 선택하는 경우, 선택 안하는 경우
int dp[MAX][2];
vector<int> ans;
/*
	문제 설명

	1. 독립 집합의 크기가 최대인 독립 집합을 구하는 것
	2  독립 집합이란, 부분 집합 S에 속한 모든 정점쌍이 서로 인접하지 않은 S를 독립집합이라고 한다.

	조건

	1. dp로 최대값을 찾는데 그 경로를 얻어와야 한다.

	추적을 할 때는 만약 현재 노드를 사용하고 있다면 다음 노드는 무조건 사용되지 않고 있을 것이고,


	현재 노드가 사용되고 있지 않다면,
	이때는 dp값을 확인하여 다음 값을 사용할 때 dp값이 더 높다면 다음값을 사용해주고
	그렇지 않다면 다음 값을 사용하지 않는 방식으로 추적을 해나간다.

*/

int solution(int prev, int cur, bool state)
{
	int& result = dp[cur][state];
	if (result != -1)
		return result;

	if (state)
	{
		result = vertex[cur];
	}
	else {
		// 이 노드를 선택 안한 경우
		result = 0;
	}
	for (int i = 0; i < edge[cur].size(); i++)
	{
		int next_node = edge[cur][i];
		if (next_node == prev)
			continue;
		// 이 노드를 선택한 경우
		if (state)
		{
			result += solution(cur, next_node, 0);
		}
		else {
			// 이 노드를 선택 안한 경우
			result += max(solution(cur, next_node, 0), solution(cur, next_node, 1));
		}
	}

	return result;
}

void tracking(int prev, int cur, bool state)
{
	// state에 들어온다는 것은 그 정점을 고른다는 것이 최대라는 의미이다.
	if (state)
	{
		ans.push_back(cur);
		for (auto next : edge[cur])
		{
			if (next == prev)
				continue;
			tracking(cur, next, 0);
		}
	}
	else {
		for (auto next : edge[cur])
		{
			if (next == prev)
				continue;
			if (dp[next][1] >= dp[next][0])
				tracking(cur, next, 1);
			else
				tracking(cur, next, 0);
		}
	}
}

int main()
{
	memset(dp, -1, sizeof(dp));

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> vertex[i];

	for (int i = 0; i < n - 1; i++)
	{
		int v, e; cin >> v >> e;
		edge[v].push_back(e);
		edge[e].push_back(v);
	}

	int temp1 = solution(-1, 1, 0);				// 노드 1을 포함 x
	int temp2 = solution(-1, 1, 1);				// 노드 1을 포함

	// dp는 1정점부터 각 노드의 정점까지의 독립집합 최댓값이다.
	// 그러므로 그 최댓값을 따라가면서 트래킹하면 된다.
	if (temp1 > temp2)
	{
		tracking(-1, 1, 0);
	}
	else {
		tracking(-1, 1, 1);
	}
	
	sort(ans.begin(), ans.end());

	cout << max(temp1, temp2) << endl;
	for (auto i : ans)
		cout << i << " ";

	return 0;
}