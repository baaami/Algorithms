#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
/*
1
5 3
1 1
1 3
2 2
*/
bool cmp(const pair<int, int>& p, const pair<int, int>& q)
{
	if (p.second != q.second)
		return p.second < q.second;				// second가 다르면 second를 오름차순으로 정렬해라
	return p.first < q.first;					// first를 기준으로 오름 차순으로 정리해라
}

int main()
{
	cin.tie(0);
	int t; cin >> t;
	while (t--)
	{
		cin >> n >> m;
		vector<pair<int, int>> range(m);

		for (int i = 0; i < m; i++)
		{
			cin >> range[i].first >> range[i].second;
		}

		int cnt = 0;
		sort(range.begin(), range.end(), cmp);

		bool book[1001] = {};
		for (int i = 0; i < m; i++)
		{
			for (int j = range[i].first; j <= range[i].second; j++)
			{
				if (book[j] == false)
				{
					cnt++;
					book[j] = true;			// j번째 book은 나눠줌
					break;
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}