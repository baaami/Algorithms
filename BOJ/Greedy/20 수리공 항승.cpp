#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, l, cnt(0);		// n : 물이 새는 곳 개수, l : 테이플의 길이
	cin >> n >> l;
	vector<int> v(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	int i, j;
	for (i = 0; i < n; i++)
	{
		cnt++;
		if (i == n - 1)
		{
			break;
		}
		// 다음 것이랑 한 번에 붙일 수 있는 경우
		if (v[i + 1] - v[i] < l)
		{
			// 어디까지 한 번에 붙일 수 있는지 붙여본다.
			for (j = 2; i + j < n; j++)
			{
				if (v[i + j] - v[i] >= l)
				{
					j--;
					break;
				}
			}
			i = i + j;
		}
	}

	cout << cnt << endl;
	return 0;
}