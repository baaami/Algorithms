#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAX 51
using namespace std;
// https://www.acmicpc.net/problem/1043
/*
	문제

	-> 이야기의 진실을 아는 사람들 앞에서는 진실을 말해야한다.
	-> 사람의 수 N, 이야기의 진실을 아는 사람이 주어진다.

	어떤 사람이 어떤 파티에서는 진실을 듣고, 또다른 파티에서는 과장된 
	이야기를 들었을 때도 지민이는 거짓말쟁이로 알려지게 된다. 지민이는 이런 일을 모두 피해야 한다.
	or
	과장된 말을 듣고 나중에 진짜 이야기를 하면 그것도 걸린다.

	출력 : 과장된 이야기를 들키지 않는 선에서 최대한 과장되게 이야기를 할 수 있는 파티 개수의 최댓값
*/

int n, m;
int nknown;
bool known[MAX];
vector<int> partyinfo[MAX];
int dp[MAX][MAX];

//////////////////////////////////// 아래 함수 3개는 Union Find 알고리즘을 위한 함수
// x의 부모 노드를 찾는 함수			<< 부모 노드를 갱신해주는 함수

// Union Find 알고리즘으로 서로 연결되어있나 확인해본다.
int parent[MAX];
int getParent(int parent[], int x)
{
	// 해당 부모 값과 x값이 같은 경우
	if (parent[x] == x) return x;			// 1로 모두 연결하면 이 부분을 통과하는 것은 1이될 것이다.
	// 최종 부모를 찾는 과정
	return parent[x] = getParent(parent, parent[x]);
}

// 두 부모 노드를 합치는 함수		<< 노드간에 연결해주는 함수
void unionParent(int parent[], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

// 같은 부모를 가지는지 확인		<< 노드간에 간선으로 이뤄져있는지 확인하는 함수
int findParent(int parent[], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);

	if (a == b) return 1;
	return 0;
}
//////////////////////////////////// 위 3개 함수는 Union Find 알고리즘을 위한 함수


int solution(int peopleidx, int partyidx)
{
	// 파티에서 거짓말할 수 있는 경우
	if (peopleidx == 0) return 1;

	int& result = dp[peopleidx][partyidx];
	if (result != -1)
		return result;

	result = 0;
	// 현재 peopleidx인 사람이 거짓말을 알고 있고
	if (known[peopleidx])
	{
		// 이 파티에 참가해있는 인원들을 확인해본다
		for (int i = 0; i < partyinfo[partyidx].size(); i++)
		{
			if (peopleidx == partyinfo[partyidx][i])
			{
				// 이 경우 거짓말을 할 수 없는 파티가 된다.
				return 0;
			}
		}
		// 파티에 참가해있는 인원중 없는 인원이라면 가능

		result = solution(peopleidx - 1, partyidx);
	}
	else {
		// 모르는 사람이라면 가능
		result = solution(peopleidx - 1, partyidx);
	}

	return result;
}

int main()
{
	cin >> n >> m;
	cin >> nknown;
	vector<int> knownclub;
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}
	for (int i = 1; i <= nknown; i++)
	{
		int people; cin >> people;
		knownclub.push_back(people);
		known[people] = true;
	}
	for (int i = 1; i <= m; i++)
	{
		int many, who; cin >> many;
		for (int j = 0; j < many; j++)
		{
			cin >> who;
			partyinfo[i].push_back(who);
			// 같은 파티에 참가하는 인원끼리 전부 그래프로 엮어준다.
			unionParent(parent, partyinfo[i][0], partyinfo[i][j]);
		}
	}
	// 사실을 알고있는 사람과 엮인 사람들의 known 배열을 전부 true로 바꿔준다.
	for (int j = 0; j < knownclub.size(); j++)
	{
		for (int i = 1; i <= n; i++)
		{
			// 엮인 경우
			if (findParent(parent, knownclub[j], i) == 1)
			{
				known[i] = true;
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= m; i++)
	{
		memset(dp, -1, sizeof(dp));
		ans += solution(n, i);
	}
	cout << ans << endl;
	return 0;
}