#include <iostream>
#include <vector>
#define MAX 101
using namespace std;

vector<int> a[MAX];		// 간선
int d[MAX];				// 노트북과 매칭이 될 사람 인덱스를 담을 배열
bool c[MAX];			// 특정한 정점 처리했는지
int n = 3, m;

bool dfs(int x)
{
	for (int i = 0; i < a[x].size(); i++)
	{
		int t = a[x][i];
		// 이미 처리한 노드는 볼 필요 없다.
		if (c[t] == true) continue;
		c[t] = true;

		// 비어있거나 점유 노드에 더 들어갈 공간이 있는 경우
		// dfs(d[t]) 는 다른 점유 노드한테 다른 곳으로 갈 수 있는지 물어보는 것
		if (d[t] == 0 || dfs(d[t]))
		{
			d[t] = x;
			return true;
		}
	}
	
	return false;
}


int main()
{
	a[1].push_back(1);
	a[1].push_back(2);
	a[1].push_back(3);
	a[2].push_back(1);
	a[3].push_back(2);
	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		fill(c, c + MAX, false);			// 매번 매칭할 때마다 c를 초기화
		if (dfs(i)) count++;
	}

	cout << count << endl;

	for (int i = 1; i < MAX; i++)
	{
		if (d[i] != 0)
		{
			printf("%d -> %d\n", d[i], i);
		}
	}
}