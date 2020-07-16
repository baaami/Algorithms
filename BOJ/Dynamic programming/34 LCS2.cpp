#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>
#include <string>
using namespace std;
int get_max(int a, int b)
{
	return a > b ? a : b;
}
char s1[1001];
char s2[1001];
int dp[1001][1001];
int main()
{
	int ans = 0;
	scanf("%s %s", s1, s2);
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	for (int i = 0; i <= len1; i++)
	{
		for (int j = 0; j <= len2; j++)
		{
			dp[i][j] = 0;
		}
	}

	for (int i = 1; i <= len1; i++)
	{
		for (int j = 1; j <= len2; j++)
		{
			if (s1[i - 1] == s2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = get_max(dp[i - 1][j], dp[i][j - 1]);
			}
			if (ans < dp[i][j]) ans = dp[i][j];
		}
	}
	printf("%d\n", ans);
	int i = len1;
	int j = len2;
	vector<char> result;
	while (i >= 1 && j >= 1) {
		if (dp[i][j] == dp[i - 1][j]) {
			i--;
		}
		else if (dp[i][j] == dp[i][j - 1]) {
			j--;
		}
		else {
			result.push_back(s1[i - 1]);
			i--; j--;
		}
	}
	for (i = result.size() - 1; i >= 0; i--)
		printf("%c", result[i]);

	return 0;
}