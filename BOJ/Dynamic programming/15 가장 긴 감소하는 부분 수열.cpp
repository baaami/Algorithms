#include <iostream>
#include <algorithm>
using namespace std;
int a[1001];
int dp[1001];
int n;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			// 첫번째 조건 : 감소해야하므로 앞에 값보다 작아야한다.
			// 두번째 조건 : 첫번째 조건을 만족하면서 길이는 앞의 길이중 가장 길어야한다.
			if (a[i] < a[j] && dp[j] + 1 > dp[i])		
			{
				dp[i] = dp[j] + 1;
			}
		}
	}
	cout << *max_element(dp, dp + n);
	return 0;
}