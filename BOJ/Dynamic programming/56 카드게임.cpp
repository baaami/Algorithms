#include <iostream>
#include <cstring>
#include <algorithm>
// 카드 게임
// https://www.acmicpc.net/problem/10835
#define MAX 2000
using namespace std;
int n;
int dp[MAX + 1][MAX + 1];
int a[MAX + 1];
int b[MAX + 1];

int solution(int left, int right)
{
	// 카드 더미가 남아있지 않은 경우
	if (left == n || right == n) return 0;
	int& val = dp[left][right];
	if (val != -1) return val;
	// 왼쪽 카드의 숫자가 오른쪽 카드의 숫자보다 클 경우면 오른쪽 카드를 버릴 경우와 비교
	// 오른쪽 카드의 숫자가 크면 왼쪽 카드만 버릴 경우와 둘다 버릴 경우를 비교
	val = a[left] > b[right] ? max(val, solution(left, right + 1) + b[right]) : max(solution(left + 1, right), solution(left + 1, right + 1));
	return val;
}

int main()
{
	cin >> n; int left, right, value, grade = 0;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	memset(dp, -1, sizeof(dp));
	cout << solution(0, 0);
	return 0;
}