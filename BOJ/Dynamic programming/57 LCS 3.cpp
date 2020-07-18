#include <iostream>
#include <cstring>
#include <string>
#define MAX 100
//https://www.acmicpc.net/problem/1958
int get_max(int a, int b) { return a > b ? a : b; }
using namespace std;
int dp[MAX + 1][MAX + 1][MAX + 1];
string a, b, c;
int main()
{
	cin >> a >> b >> c;
	int i, j, k;
	int len1 = a.length();
	int len2 = b.length();
	int len3 = c.length();
	memset(dp, 0, sizeof(dp));
	
	for (i = 1; i <= len1; i++) {
		for (j = 1; j <= len2; j++) {
			for (k = 1; k <= len3; k++)
			{
				if (a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1]) dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				else dp[i][j][k] = get_max(dp[i - 1][j][k], get_max(dp[i][j - 1][k], dp[i][j][k - 1]));
			}
		}
	}
	cout << dp[len1][len2][len3];
	return 0;
}