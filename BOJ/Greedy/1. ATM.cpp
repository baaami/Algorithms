#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//https://www.acmicpc.net/problem/11399

int main()
{
	int n; cin >> n;
	vector<int> a(n);
	int sum = 0;
	int all_sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	
	for (int i = 0; i < n; i++)
	{
		sum += a[i];
		all_sum += sum;
	}

	cout << all_sum << endl;
	return 0;
}