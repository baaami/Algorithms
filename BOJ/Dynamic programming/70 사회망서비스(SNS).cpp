#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define MAX 1000001
using namespace std;
int n, u, v;
vector<int> a[MAX];
vector<int> oneway[MAX];
int dp[MAX][2];			// 노드가 n이 0(early adaptor)아닐 때 총 최소 early adaptor 수
						// 노드가 n이 1(early adaptor)일 때 총 최소 early adaptor 수
bool visited[MAX];
/*
	LOGIC

	1. 트리라는 가정이 있으므로 루트부터 시작해서 확인해본다.
	2. 단방향 그래프로 바꿔준다.

	3. 현재 노드가 early adaptor라면 다음 노드는 early adaptor이어도 되고 아니어도 된다.
	4. 현재 노드가 early adaptor 아니라면 다음 노드는 early adaptor이어야 한다.
*/

void make_oneway_graph(int curnode)
{
	// 방문 도장찍기
	visited[curnode] = true;

	// 현재 그려진 그래프 돌면서 단방향 그래프로 바꿔주기
	for (int i = 0; i < a[curnode].size(); i++)
	{
		// 다음 노드 값을 저장
		int nextnode = a[curnode][i];
		// 그 노드가 방문 도장 찍은 노드인가?
		if (!visited[nextnode])
		{
			// 루트에서 말단노드(leaf node)로 부터 내려오고 있으므로 이런 식으로 넣어준다면,
			// 단방향 그래프가 생성된다.
			oneway[curnode].push_back(nextnode);
			// 방문하지 않았다면 방문하러 가기
			make_oneway_graph(nextnode);
		}
	}
}

// 아이디어 얻어다니는 인싸
int inssa(int curnode, bool early)
{
	int& result = dp[curnode][early];
	if (result != -1)
		return result;

	// 위 LOGIC의 3, 4번 조건을 사용 
	if (early)
	{
		// 현재 노드가 early adaptor이기 때문에 result에 1값을 넣어준다
		result = 1;
		// 단방향 그래프를 탐색해본다.
		for (int i = 0; i < oneway[curnode].size(); i++)
		{
			int nextnode = oneway[curnode][i];
			result += min(inssa(nextnode, true), inssa(nextnode, false));
		}
	}
	else {
		// 인싸가 아니면 내 다음 친구는 반드시 인싸이어야 한다.
		result = 0;
		for (int i = 0; i < oneway[curnode].size(); i++)
		{
			int nextnode = oneway[curnode][i];
			result += inssa(nextnode, true);
		}
	}


	return result;
}

int main()
{
	cin >> n;
	memset(dp, -1, sizeof(dp));
	// 간선 연결 (그래프 그리는 부분)
	for (int i = 0; i < n - 1; i++)
	{
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	make_oneway_graph(1);			// 루트부터 시작

	cout << min(inssa(1, true), inssa(1, false));
	return 0;
}