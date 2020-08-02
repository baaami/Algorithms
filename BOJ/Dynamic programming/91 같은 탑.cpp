#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 51
#define MAXHEIGHT 500000
#define INF 987654321

int n;
int top[MAX];
int ans = -1;
// 한 탑의 최고 높이는 MAXHEIGHT / 2 + 1이다.
int dp[MAX][MAXHEIGHT / 2 + 1];

// 각 나무 블럭은 4가지 경우의 수가 필요하다.
// 1. 해당 블럭을 쓰지 않는 경우
// 2. 해당 블럭을 더 높은 탑에 쌓는 경우
// 3. 해당 블럭을 더 낮은 탑에 쌓는 경우
//    3.1 해당 블럭이 탑 간의 높이차보다 클 경우
//    3.2 해당 블럭이 탑 간의 높이차보다 작을 경우

// 탑 간의 높이차가 초과 or 마지막 블록까지 사용해도 높이차가 존재하면 성립 x

using namespace std;

int solution(int idx, int heightdiff)
{
	if (heightdiff > MAXHEIGHT / 2)
		return -INF;
	if (idx == n + 1 && heightdiff)			// height는 두 탑의 높이차이다
		return -INF;

	// 모든 조건 만족
	if (idx == n + 1 && heightdiff == 0)
		return 0;

	int& result = dp[idx][heightdiff];
	if (result != -1) 
		return result;

	result = -INF;
	// idx 블록을 안쓰는 경우
	result = max(result, solution(idx + 1, heightdiff));

	// idx조 각을 더 높은 탑에 사용 하는 경우에다가 top[idx]를 더해주면 안되는 이유..?
	// idx 조각을 더 높은 탑이 사용하는 경우
	result = max(result, solution(idx + 1, heightdiff + top[idx]));


	// idx 조각을 더 낮은 탑에 사용하는 경우
		// 블록높이가 탑의 차이보다 더 큰 경우
	if (top[idx] > heightdiff)
		result = max(result, heightdiff + solution(idx + 1, top[idx] - heightdiff));
	else
		// 탑의 차이가 블록높이보다 더 큰 경우
		result = max(result, top[idx] + solution(idx + 1, heightdiff - top[idx]));
	return result;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); //cin 속도 향상
	cin >> n; 
	for (int i = 1; i <= n; i++)
		cin >> top[i];
	memset(dp, -1, sizeof(dp));

	int ans = solution(1, 0);
	if (ans)
		cout << ans << endl;
	else
		cout << -1 << endl;
	return 0;
}