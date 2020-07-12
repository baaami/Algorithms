#include <iostream>
#include <vector>
#include <stack>
#define MAX 10001				// 가능한 총 NODE의 개수
using namespace std;
int min(int a, int b) { return (a < b) ? a : b; }
int id, d[MAX];					// 각 노드마다 고유한 번호를 할당해 줄 변수
bool finished[MAX];				// 현재 특정한 노드에 대한 dfs가 끝났는지 확인
								// 이유 : 현재 1 노드가 dfs가 끝나지 않은 상태여서 2,3 부모 노드가 1이된 것
vector<int> a[MAX];				// 노드마다 간선 연결 배열
vector<vector<int>> SCC;
stack<int> s;
		
// dfs는 총 정점의 개수만큼 실행
int dfs(int x)
{
	d[x] = ++id;		// 자기자신을 부모로 할당
	s.push(x);			// 스택에 자기 자신을 할당

	int parent = d[x];
	for (int i = 0; i < a[x].size(); i++)
	{
		int y = a[x][i];
		// 두 이웃을 나눠서 parent를 넣는다.
		if (d[y] == 0) parent = min(parent, dfs(y));		// 방문하지 않은 이웃
		else if (!finished[y]) parent = min(parent, d[y]);	// 처리 중인 이웃
	}

	if (parent == d[x])			// 부모 노드가 자기 자신인 경우
	{
		vector<int> scc;		// 현재 scc 그룹 한개를 담을 vector를 만든다.
		while (1)
		{
			int t = s.top();
			s.pop();
			scc.push_back(t);	
			finished[t] = true;
			if (t == x) break;			// 부모 노드가 나올 때 까지 pop을 해서 scc에 넣는다.
		}
		SCC.push_back(scc);
	}

	return parent;
}



int main()
{
	int v = 11;

	a[1].push_back(2);
	a[2].push_back(3);
	a[3].push_back(1);
	a[4].push_back(2);
	a[4].push_back(5);
	a[5].push_back(7);
	a[6].push_back(5);
	a[7].push_back(6);
	a[8].push_back(5);
	a[8].push_back(9);
	a[9].push_back(10);
	a[10].push_back(11);
	a[11].push_back(3);
	a[11].push_back(8);
	for (int i = 1; i <= v; i++)
	{
		if (d[i] == 0) dfs(i);
	}

	cout << "SCC의 개수 : " << SCC.size() << endl;

	for (int i = 0; i < SCC.size(); i++)
	{
		cout << i + 1 << "번째 SCC : ";
		for (int j = 0; j < SCC[i].size(); j++)
		{
			cout << SCC[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}