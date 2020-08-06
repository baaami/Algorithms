#include <iostream>
#include <algorithm>
#include <cstring>
#define CHU_MAX 30
#define GU_MAX 7
#define CHU_WEIGHT 40000
using namespace std;

/*
	1g, 4g 추가 있을 경우

	예1 : 주어진 구슬과 1g 추를 양쪽 양팔 저울에 올려 놓으면 수평이면 주어진 구슬은 1g이라는 것을 알 수 있다.
	예2 : 구슬이 4g인지 확인해보려면 4g인 추 하나를 올렸을 경우 수평이 되는 것을 알 수 있다.

	목표 : 주어진 추만을 이용해서 구슬의 무게를 확인할 수 있는지
*/


int chu_n;
int chu_weight[CHU_MAX + 1];

int gu_n;
int gu_weight[GU_MAX + 1];


// 있는 추로 만들 수 있는 모든 무게를 dp로 구하자.
// 추들끼리 덧셈 or 뺄셈으로 나오는 모든 무게를 만들 수 있다.

// dp[i][weight] :  i번째 추까지 이용해서 weight를 만들 수 있는지 여부
int dp[CHU_MAX + 1][CHU_WEIGHT + 1];

int solution(int chu_idx, int weight)
{
	// 기저 사례 (추를 다 사용했는데도 weight가 0이 아닌 경우 )
	if (weight != 0 && chu_idx == 0)
		return 0;

	// 조건 충족
	if (weight == 0)
		return 1;

	int& result = dp[chu_idx][weight];
	if (result != -1)
		return result;

	// 하나라도 가능한 경우라면 가능
	if (solution(chu_idx - 1, weight - chu_weight[chu_idx]) || solution(chu_idx - 1, weight + chu_weight[chu_idx])
		|| solution(chu_idx - 1, weight))
		return result = 1;
	return result = 0;
}

void Input()
{
	// 추
	cin >> chu_n;
	for (int i = 1; i <= chu_n; i++)
		cin >> chu_weight[i];

	// 구슬
	cin >> gu_n;
	for (int i = 1; i <= gu_n; i++)
		cin >> gu_weight[i];
}

int main()
{
	Input();
	memset(dp, -1, sizeof(dp));
	// 추의 총 개수를 이용해서 구의 최대 무게까지 만들 수 있는 경우
	for (int i = 1; i <= gu_n; i++)
	{
		if (solution(chu_n, gu_weight[i]))
		{
			cout << "Y ";
		}
		else {
			cout << "N ";
		}
	}
	
	return 0;
}