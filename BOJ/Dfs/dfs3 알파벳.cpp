#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int r, c;
bool alpha[27];
string board[21];
int dx[] = { 1, -1, 0, 0 };
int dy[] = {0, 0, 1, -1};
int max_ans = 0;

// true를 넣어주는 건 dfs함수를 들어왔을 때 넣어주고
// false를 넣어주는 건 dfs함수를 나왔을 때 넣어줘야하는 부분이 중요

void dfs(int x, int y, int sum)
{

	if (sum > max_ans)
		max_ans = sum;
	// true를 넣어주는 건 dfs함수를 들어왔을 때 넣어주고
	alpha[(int)(board[x][y] - 'A')] = true;
	for (int k = 0; k < 4; k++)
	{
		int nextx = x + dx[k];
		int nexty = y + dy[k];

		if (nextx >= 0 && nextx < r && nexty >= 0 && nexty < c)
		{
			if (alpha[(int)(board[nextx][nexty] - 'A')])
				continue;
			// 현재까지 지나온 알파벳과 다르다면
			
			dfs(nextx, nexty, sum + 1);
			// false를 넣어주는 건 dfs함수를 나왔을 때 넣어줘야하는 부분
			alpha[(int)(board[nextx][nexty] - 'A')] = false;
		}
	}
}

int main()
{
	cin >> r >> c;
	memset(alpha, false, sizeof(alpha));
	for (int i = 0; i < r; i++)
	{
		cin >> board[i];
	}
	
	dfs(0, 0, 1);
	cout << max_ans;
	return 0;
}