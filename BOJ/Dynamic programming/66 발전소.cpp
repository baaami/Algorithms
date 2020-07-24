#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#define MAX 16 + 1
#define INF 987654321
int min(int a, int b) { return a < b ? a : b;}
using namespace std;
int n;
int p;
int cost[MAX][MAX];
// 발전소의 상태가 string으로 주어지지만 'Y' = 1, 'N' = 0으로 바꾸어서 비트 형태로 표현하면 
// 메모이제이션을 할 수 있기 때문에 비트마스킹을 이용했습니다.
int bit = 1 << MAX;
// dp[n][m] 은 n 발전소, 발전소 가동상태
int dp[MAX][1 << MAX];
string state;


// 비트 내의 1 세는 법
int countone(int x)
{
	int cnt = 0;
	while (x)
	{
		cnt += x & 1;
		x >>= 1;
	}
	return cnt;
}

int solution(int idx, int curstate)
{
	// 조건 충족
	// -1 해주는 이유는 bit = 1 << MAX 이기 때문에 맨 왼쪽에 1이 있기 때문이다.
	// 조건 충족한 경우 0을 리턴해주는 이유는 
	// result = min(result, cost[idx][i] + solution(i, nextState)); 이 줄에서
	// cost[idx][i]를 더해주기 때문에 0을 리턴해주면 비용을 전부 더한 값을 얻을 수 있다.
	if (countone(curstate) - 1 >= p)
		return 0;

	int& result = dp[idx][curstate];
	if (result != -1)
		return result;

	result = INF;
	for (int i = 0; i < n; i++)
	{
		if ((curstate & (1 << i)) == 0)		// i번째 발전소가 꺼져있는 발전소인 경우
		{
			int nextState = curstate | (1 << i);		// 그 i번째 발전소를 켠 상태로 만들고

			// 현재 켜져있는 발전소에 한해서 다시 돌려본다.
			// idx 발전소부터 방금 i번째 발전소를 켠 발전소까지 켜져있는 모든 발전소에서 다시 꺼져있는 발전소를 전부 켜본다. 그 때 비용의 최솟값을 result가 갖게 될 것이다.
			for (int j = 0; j < n; j++)
			{
				if ((nextState & (1 << j)))				
					result = min(result, cost[idx][i] + solution(j, nextState));
			}
		}
	}

	return result;
}

int main()
{
	// n개의 발전소가 있고 적어도 p개의 발전소가 고장나지 않게 해야한다.
	// 각  i 발전소fh j 발전소를 재시작할 때 비용이 발생하고 그것은 배열로 나타나 있다.

	// 불가능한 경우 -1 출력
	// 적어도 p만큼 발전소를 고쳐야하는 것
	cin >> n;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> cost[i][j];
		
	cin >> state >> p;
	
	for (int i = 0; i < state.length(); i++)
	{
		if (state[i] == 'Y')
			bit |= (1 << i);
	}

	if (p == 0)
		cout << 0 << endl;
	else {
		memset(dp, -1, sizeof(dp));
		int result = INF;
		for (int i = 0; i < n; i++)
		{
			if (state[i] == 'Y')
				result = min(result, solution(i, bit));
		}

		if (result == INF)
			cout << -1 << endl;
		else
			cout << result << endl;
	}

	return 0;
}