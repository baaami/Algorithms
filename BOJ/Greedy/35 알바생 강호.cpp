#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 100000
int a[MAX];


bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	cin.tie(0);
	long long tip = 0;
	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	// 내림차순으로 정리
	sort(a, a + n, cmp);
	for (int i = 0; i < n; i++)
	{
		if (a[i] - i > 0) tip += a[i] - i;
		else break;
	}

	cout << tip;
	return 0;
}