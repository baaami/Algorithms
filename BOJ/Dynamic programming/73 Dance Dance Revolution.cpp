#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 100001
using namespace std;
int order[MAX];
// idx 까지 left, right의 발 위치의 경우 힘이 드는 최솟값
int dp[MAX][5][5];
int n = 0;
/*
	DDR 게임판

	  1
	2 0 4
	  3

	제약 조건

	조건 1. 왼쪽, 오른쪽 발을 따로 움직인다. ( 두 발 동시x )
	조건 2. 두 발이 같은 위치에 있을 수 없다.

	비용 조건

	1. 중앙에 있던 말이 이동하면 힘 : 2
	2. 대각선으로 이동하면 힘 : 3
	( 예 : 왼쪽 - > 위, 왼쪽 -> 아래 )
	3. 반대로 움직이면 힘 : 4
	( 예 : 위 -> 아래, 왼쪽 -> 오룬쪽 )
	4. 같은 지점을 한번 더 누르면 힘 : 1
*/
int calculation(int start, int end)
{
	// 중앙에 있는 발이 이동하는 경우
	if (start == 0)
	{
		return 2;
	} else if(abs(start - end) == 2)
	{
		// 반대로 이동하는 경우
		return 4;
	}
	else if (start - end == 0)
	{
		// 같은 위치를 밟는 경우
		return 1;
	}
	else {
		// 대각선으로 이동하려는 경우
		return 3;
	}
}

int solution(int idx, int left, int right)
{
	// 조건 충족
	if (idx == n + 1) return 0;

	// 기저 사례, 두 발이 같은 곳에 있으면 안된다.
	if (left != 0  && left == right)
		return 987654321;
	
	int& result = dp[idx][left][right];

	if (result != -1)
		return result;

	// 왼발로 idx 위치로 옮기는 경우
	// solution(idx + 1, order[idx], right) + calculation(left, order[idx])
	// 오른발로 idx 위치로 옮기는 경우
	// solution(idx + 1, left, order[idx]) + calculation(right, order[idx])
	return result = min(solution(idx + 1, order[idx], right) + calculation(left, order[idx]),
		solution(idx + 1, left, order[idx]) + calculation(right, order[idx]));
}
int main()
{
	int temp;
	while (1)
	{
		scanf("%d", &temp);
		if (temp == 0) break;
		n++;
		order[n] = temp;
	}
	memset(dp, -1, sizeof(dp));
	cout << solution(1, 0, 0) << endl;
	return 0;
}