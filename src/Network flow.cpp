#include <iostream>
#include <queue>
#include <vector>

#define MAX 100
#define INF 1000000000							// 무한대 표시	
using namespace std;

int n = 6 , result;
int c[MAX][MAX], f[MAX][MAX], d[MAX];			// 용량, 유량, 돌아가기 위한 전 노드 경로 (현재 특정 노드를 방문을 했는지에 대한 배열)
vector<int> a[MAX];								// 연결된 간선들 표시

void maxFlow(int start, int end)
{
	while (1)
	{
												// 모든 정점을 방문하지 않은 상태로
		fill(d, d + MAX, -1);					// 한 경로가 끝날 때마다 d가 새로 -1로 초기화 된다.
		queue<int> q;
		q.push(start);
		while (!q.empty())
		{
			int x = q.front();
			q.pop();
			for (int i = 0; i < a[x].size(); i++)
			{
				int y = a[x][i];
				// 방문하지 않은 노드 중에 용량이 남은 경우, 즉 유량이 더 흐를 수 있는 경우
				if (c[x][y] - f[x][y] > 0 && d[y] == -1)			
				{
					q.push(y);
					d[y] = x;					// 경로를 기억합니다.
					if (y == end) break;		// 도착지
				}
			}
		}

		// 유량이 end까지 가지 못한다는 것은 용량이 다 찼다는 의미										
		if (d[end] == -1) break;		// 모든 경로를 다 찾고 탈출한다.

		int flow = INF;
		
		// i = d[i] 의미는 자신 이전에 있는 노드로 돌아오면서 거꾸로 돌아가는 것.
		for (int i = end; i != start; i = d[i])					// 거꾸로 최소 유량 탐색
		{
			// 첫번째의 경우에는 최소 용량이 flow에 들어갈 것이다.
			flow = min(flow, c[d[i]][i] - f[d[i]][i]);			// 현재 갔던 가장 가능한 작은 유량을 흘려보내야함.
		}

		// 최소 유량만큼 추가한다.
		for (int i = end; i != start; i = d[i])
		{
			f[d[i]][i] += flow;
			f[i][d[i]] -= flow;
		}

		result += flow;
		//cout << "확인 : " << f[2][3] << endl;
		//cout << "2 - > 3  용량 : " << f[2][3] << endl;
		//cout << "2 - > 3  유량 : " << f[2][3] << endl;
		//cout << "3 - > 2  유량 : " << f[3][2] << endl;
	}
}
// https://koosaga.com/18  더 빠른 알고리즘 참고
int main()
{
	a[1].push_back(2);
	a[2].push_back(1);
	c[1][2] = 12;

	a[1].push_back(4);
	a[4].push_back(1);
	c[1][4] = 11;

	a[2].push_back(3);
	a[3].push_back(2);
	c[2][3] = 6;

	a[2].push_back(4);
	a[4].push_back(2);
	c[2][4] = 3;

	a[2].push_back(5);
	a[5].push_back(2);
	c[2][5] = 5;

	a[2].push_back(6);
	a[6].push_back(2);
	c[2][6] = 9;

	a[3].push_back(6);
	a[6].push_back(3);
	c[3][6] = 8;

	a[4].push_back(5);
	a[5].push_back(4);
	c[4][5] = 9;

	a[5].push_back(3);
	a[3].push_back(5);
	c[5][3] = 3;

	a[5].push_back(6);
	a[6].push_back(5);
	c[5][6] = 4;


	maxFlow(1, 6);
	cout << result << endl;
	return 0;
}