//#include <iostream>
//#include <vector>
//using namespace std;
//
//int R, C;
//char a[10001][501];
//bool check[10001][501];
//int main()
//{
//	cin.tie(0);
//	cin >> R >> C;
//	int cnt(0);
//	for (int i = 0; i < R; i++)
//	{
//		for (int j = 0; j < C; j++)
//		{
//			cin >> a[i][j];
//			check[i][j] = false;
//		}
//	}
//	
//	int i, j, x, y(0);
//	for (i = 0; i < R; ++i)
//	{
//		x = i;
//		vector<pair<int, int>> check_index;
//		for (j = 0; j < C; ++j)
//		{	
//			y = j;
//			// 1. 오른쪽 위로 갈 수 있는 경우 검사
//			if( x  >  0 ){					
//				if (check[x - 1][y + 1] == false && a[x - 1][y + 1] != 'x')				// true이면 갈 수있다.
//				{
//					check_index.push_back(make_pair(x - 1, y + 1));
//					x--;								// 한칸 위로감. 오른쪽은 어차피 j++ 된다.
//					continue;
//				}
//			}
//			// 2. 오른쪽으로 갈 수 있는 경우 검사
//			if (check[x][y + 1] == false && a[x][y + 1] != 'x')
//			{
//				check_index.push_back(make_pair(x, y + 1));
//				continue;
//			}
//			// 3. 오른쪽 아래로 갈 수 있는 경우 검사
//			if (x < R - 1)
//			{
//				if (check[x + 1][y + 1] == false && a[x + 1][y + 1] != 'x')
//				{
//					check_index.push_back(make_pair(x + 1, y + 1));
//					x++;
//					continue;
//				}
//			}
//			break;		// 도중에 끝난 경우, 끝에 도착한 경우
//		}
//		// 도착을 한경우, 온 길을 전부 check
//		if (y == C - 1)
//		{
//			for (auto work : check_index)
//			{
//				check[work.first][work.second] = true;
//			}
//			cnt++;
//		}
//	}
//	cout << cnt << endl;
//	return 0;
//}
#include <iostream>

using namespace std;

int r, c;
char a[10001][501];
bool check[10001][501];
int cnt = 0;
void dfs(int i, int j)
{
	if (j == c - 1)
	{
		cnt++;
		return;
	}
	int dx[] = { -1, 0 , 1 };
	int dy[] = { 1, 1, 1 };
	for (int k = 0; k < 3; k++)
	{
		if (i + dx[k] < 0 || j + dy[k] >= r || i + dx[k] >= c) continue;
		
		if (check[i + dx[k]][j + dy[k]] == false && a[i][j] == '.')			// 이면 탐색
		{
			check[i + dx[k]][j + dy[k]] = true;
			dfs(i + dx[k], j + dy[k]);
		}
	}
}
int main()
{
	cin >> r >> c;
	memset(a, 'x', sizeof(a));
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> a[i][j];
			check[i][j] = false;
		}
	}

	for (int i = 0; i < r; i++) dfs(i, 0);

	cout << cnt << endl;
	return 0;
}