#include <iostream>
#include <vector>

using namespace std;

int n, k;

int main()
{
	cin >> n >> k;
	vector<int> pocket(n);
	int cnt(0); int give(0); int index(n - 1);
	for (int i = 0; i < n; i++)
	{
		cin >> pocket[i];
	}
	for(;;)
	{
		if (give + pocket[index] > k)
		{
			index--;
			continue;
		}
		else if (give + pocket[index] < k)
		{
			give += pocket[index];
			cnt++;
		}
		else {
			cnt++;
			break;
		}
	}
	cout << cnt;

	return 0;
}