#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n; cin >> n;
	vector<int> lope(n);
	int max = 0; int weight = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> lope[i];
	}
	sort(lope.begin(), lope.end());
	max = lope[0] * lope.size();
	// 위와 같은 무게로 시작
	while (1)
	{
		 // 제일 작은 무게인 로프를 지운다.
		lope.erase(lope.begin());
		if (lope.size() == 0) break;
		weight = lope[0] * lope.size();
		if (weight > max)
		{
			max = weight;
		}
	}

	cout << max;

	return 0;
}