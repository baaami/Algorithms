#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int n;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	long long ans = 0;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	for (int i = 1; i <= n; i++)
	{
		if (i != a[i])
		{
			ans += abs(i - a[i]);
			a[i] = i;
		}
	}

	cout << ans;
	return 0;
}