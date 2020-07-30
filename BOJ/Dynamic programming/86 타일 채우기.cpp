#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 501
// 문제 : https://www.acmicpc.net/problem/2718
// 참고 : http://joonas-yoon.blogspot.com/2016/03/2718.html
using namespace std;
int n;
int dp[MAX][5];

int solution(int width, int state)
{

	if (width < 0) return 0;
	if (width == 0) return state == 0;			// 아무 것도 없어야 1이 가능하다.

	int& result = dp[width][state];
	if (result != -1)
		return result;

	switch (state) {
	case 0:
		result = solution(width - 1, 0) + solution(width - 2, 0) + solution(width - 1, 1)
			+ solution(width - 1, 3) + solution(width - 1, 4);
		break;
	case 1:
		result = solution(width - 1, 0) + solution(width - 1, 4);
		break;
	case 2:
		result = solution(width - 1, 3);
		break;
	case 3:
		result = solution(width - 1, 0) + solution(width - 1, 2);
		break;
	case 4:
		result = solution(width - 1, 0) + solution(width - 1, 1);
		break;
	}
	return result;
}

int main()
{
	int t; cin >> t;
	while (t--)
	{
		cin >> n;
		memset(dp, -1, sizeof(dp));
		cout << solution(n, 0) << endl;
	}
	return 0;
}