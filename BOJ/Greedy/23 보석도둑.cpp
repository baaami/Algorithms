#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> p;

p jew[1000000];
int bag[300000];
int n, k, m, v, c, i, j;

bool check[1000000];

int main()
{
	scanf("%d %d", &n, &k);
	for (i = 0; i < n; ++i)
	{
		scanf("%d %d", &jew[i].first, &jew[i].second);
	}
	for (i = 0; i < k; ++i)
		scanf("%d", &bag[i]);

	sort(jew, jew + n);
	sort(bag, bag + k);

	/*for (auto b : jew)
	{
		cout << b.first << " " << b.second << endl;
		if (b.first == 0) break;
	}*/
	long long sum = 0;
	priority_queue<int> pq;
	for (i = 0, j = 0; i < k; ++i)
	{
		while (j < n && jew[j].first <= bag[i])			// i 가방에 넣을 수 있는 보석들 pq에 담기
			pq.push(jew[j++].second);					// 무게들을 넣는다.
		if (!pq.empty())								// 우선순위 queue가 비어 있지 않은 경우
		{
			sum += pq.top();							// top에는 가장 큰 값이 들어가있음
			pq.pop();									// pq에 있는 값 중에 top에 있던 값만 삭제하면된다.
		}
	}

	cout << sum << endl;

	return 0;
}