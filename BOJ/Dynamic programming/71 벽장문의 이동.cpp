#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 21
using namespace std;
// 벽장문의 이동

// 한 벽장 앞에 있는 문은 이웃 벽장 앞에 문이 없다면(즉, 벽장이 열려있다면), 
// 그 벽장 앞으로 움직일 수 있다.
int n;
int use;
int order[MAX];			// 벽장 사용 순서
// target 인덱스 위치 벽장을 열어야할 때, 현재 open1, oepn2가 열려있는 경우
// 최소로 벽장을 이동하는 경우
int dp[MAX][MAX][MAX];

// 열어야하는 벽장문
int solution(int targetidx, int open1, int open2)
{
	if (targetidx == use + 1) return 0;
	int& result = dp[targetidx][open1][open2];
	
	if (result != -1)
		return result;

	// open 1과 target을 바꾸는 경우
	//abs(open1 - order[targetidx]) + solution(targetidx + 1, order[targetidx], open2)
	// open 2와 target을 바꾸는 경우
	// abs(open2 - order[targetidx]) + solution(targetidx + 1, open1, order[targetidx])
	return result = min(abs(open1 - order[targetidx]) + solution(targetidx + 1, order[targetidx], open2),
		abs(open2 - order[targetidx]) + solution(targetidx + 1, open1, order[targetidx]));
}


int main()
{
	int ans = 0;
	// 무조건 두개의 벽장이 열려있다.
	cin >> n;
	int open[2];
	cin >> open[0] >> open[1];
	cin >> use;
	for (int i = 1; i <= use; i++)
		cin >> order[i];

	memset(dp, -1, sizeof(dp));

	cout << solution(1, open[0], open[1]) << endl;
	return 0;
}