#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#define INF 987654321
#define MININF -987654321
#define MAX 51
using namespace std;
// https://www.acmicpc.net/problem/1103
/*
	 1. H는 ASCII : 72이므로 그냥 int로 값을 받으면 밖으로 나가져 버리므로 int 배열을 사용하겠다.
	 
	 2. 형택이가 동전을 무한번 움직일 수 있다면 -1을 출력한다. ( 사이클이 생기는 경우 )
*/
int n, m;
string cmap[MAX];
int map[MAX][MAX];
bool check[MAX][MAX];
// dp[n][m] : n행 m열을 방문했을 때 까지 최대 동전을 움직일 수
int	dp[MAX][MAX];

int solution(int x, int y)
{
	// 더이상 못가는 경우
	if (x < 1 || x > n || y < 1 || y > m || map[x][y] == 'H')
		return 0;
	// 사이클이 생기는 경우
	if (check[x][y])
	{
		cout << -1;
		exit(0);
	}		

	int& result = dp[x][y];
	if (result != MININF)
	{
		return result;
	}
	check[x][y] = true;
	// 움직일 수 있는 값
	int move = map[x][y];
	int dx[] = { move, -move, 0, 0 };
	int dy[] = { 0, 0, move, -move };
	// 도저히 어디도 갈 수 없는 경우를 아는 것이 중요
	for (int k = 0; k < 4; k++)
	{
		int next_x = x + dx[k];
		int next_y = y + dy[k];
		result = max(result, solution(next_x, next_y) + 1);
	}
	// check = false를 해주는 이유는
	// 이 경로로 왔을 때 방문한 것이므로 나중에 다른 경로로 돌아서 갔을 경우에도 방문한 곳이라고 뜨면
	// 잘못이다.

	// for문 밖에 해주는 이유는
	// 벌써 골목길 x, y까지 온것은 당연한거고 거기서 어디로 갔냐 이기 때문이다.
	check[x][y] = false;
	return result;
}


int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			dp[i][j] = MININF;
	
	for (int i = 1; i <= n; i++)
		cin >> cmap[i];
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (cmap[i][j - 1] == 'H')
				map[i][j] = cmap[i][j - 1];
			else map[i][j] = cmap[i][j - 1] - '0';
		}
	}
	
	cout << solution(1, 1);
	return 0;
}
