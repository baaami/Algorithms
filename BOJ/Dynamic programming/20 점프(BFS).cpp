#include <iostream>
#include <queue>
// BFS로는 메모리초과가 난다.
using namespace std;
int n;
// 이 게임의 규칙은 규칙에 맞게 점프해서 오른쪽 가장 아래에 도착하는 것이다.
// 각 칸에 적혀있는 수는 현재 칸에서 갈 수 있는 거리를 의미한다.
// 반드시 오른쪽 or 아래쪽으로만 이동해야한다.
// 0은 더이상 진행을 막는 종착점, 항상 현재 칸에 적혀있는 수만큼 오른쪽 or 아래쪽
// 정답 : 가장 왼쪽 위에서 오른쪽 아래까지 가는 경로의 개수
int a[101][101];

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	long long ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
		}
	}
	
	if (a[1][1] == 0) cout << 0 << endl;
	else {
		queue<pair<int, int>> q;
		q.push(make_pair(1, 1));
		while (!q.empty())
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if (x == n && y == n)
			{
				ans++;
				continue;
			}
			else if(a[x][y] == 0)
			{
				continue;
			}
			if (x + a[x][y] <= n)
			{
				q.push(make_pair(x + a[x][y], y));
			}
			if (y + a[x][y] <= n)
			{
				q.push(make_pair(x, y + a[x][y]));
			}
		}

		cout << ans;
	}
	
	
	return 0;
}