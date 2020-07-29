#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 5001
using namespace std;
int n; int a[MAX]; int dp[MAX][MAX];
/*
	팰린드롬 : 앞에서 뒤로 보나, 뒤에서 앞으로 보나 같은 수열을 팰린드롬이라 한다.

	문제 : 한 수열이 주어졌을 때, 이 수열에 최소 개수의 수를 끼워 넣어 팰린드롬을 만들자.
*/

int solution(int left, int right)
{
	// 기저 사례
	if (left > right)
		return 0;

	int& result = dp[left][right];
	if (result != -1)
		return result;

	// 조건 충족을 한다면
	if (a[left] == a[right])
		result = solution(left + 1, right - 1);
	else
		// 그냥 다른 경우에는 문자 1개가 더 필요하다는 의미이다.
		result = min(1 + solution(left, right - 1), 1 + solution(left + 1, right));

	return result;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	memset(dp, -1, sizeof(dp));
	cout << solution(1, n) << endl;	

	return 0;
}