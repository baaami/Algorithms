#include <iostream>
#include <cstring>
#include <math.h>
#define MOD 1000000000
#define MAX 1000001
using namespace std;
int n;
// dp[n][k]은 2^k일 때 k번 써서 n을 2의 멱수 합으로 나타낼 수 있는 총 경우의 수
int dp[MAX][20];
int klimit = 0;
int solution(int total, int k)
{
	if (total < 0) return 0;
	if (total == 0) return 1;
	if (k == klimit + 1) return 0;
	int& result = dp[total][k];
	if (result != -1)
		return result;

	result = 0;
	return result += (solution(total - pow(2, k), k) % MOD + solution(total, k + 1) % MOD) % MOD;
}

int main()
{
	cin >> n;
	int temp = n;
	while (temp != 1)
	{
		temp /= 2;
		klimit++;
	}
	memset(dp, -1, sizeof(dp));
	cout << solution(n, 0);
	return 0;
}