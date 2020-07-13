#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, k; cin >> n >> k;
	vector<int> m(n), v(n), c(k);
	int sum = 0;
	for (int i = 0; i < n; i++) cin >> m[i] >> v[i];
	for (int i = 0; i < k; i++)	cin >> c[i];

	sort(c.begin(), c.end());						// 가방의 능력치 오름차순 정렬
	//sort(v.begin(), v.end(), greater<int>());		// 보석의 가격 내림 차순 정렬

	for (int i = 0; i < k; i++)
	{
		vector<int>::iterator itv, itm;
		int maxv = 0;
		for (int j = 0; j < v.size(); j++)
		{
			if (c[i] >= m[j])				// 가방이 보석을 들 수 있는 능력이 된다.
			{
				if (maxv < v[j])				// 들 수 있는 보석들 중 제일 비싸다.
				{
					maxv = v[j];
					itv = v.begin() + j;	// 가방에 넣은 보석 가격 위치
					itm = m.begin() + j;	// 가방에 넣은 보석 무게 위치
				}
			}
		}
		// 가방에 넣은 보석을 보석점에서 없애줘야한다.
		v.erase(itv);
		m.erase(itm);
		for (auto abc : v) cout << abc << endl;
		sum += maxv;							// 들 수 있는 것들중 가장 비싼 것을 더해준다.
	}

	cout << sum << endl;

	return 0;
}