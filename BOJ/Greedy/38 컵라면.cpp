#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/1781
int n;
struct problem {
	int deadline;
	int Lamyun;
};
							// Required memory space of this problem is 2.56 million byte
problem a[200001];			// 1.2 million byte possible
bool cmp(problem c, problem d)
{
	return c.deadline < d.deadline;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &a[i].deadline, &a[i].Lamyun);
	}
	sort(a, a + n, cmp);			// deadline을 기준으로 정렬
	priority_queue<int> pq;
	for (int i = 0; i < n; i++)
	{
		int d = a[i].deadline;
		pq.push(-a[i].Lamyun);
		while (d < pq.size()) pq.pop();		// deadline인 까지중 작은 값들은 전부 pop
	}
	
	int ans = 0;
	while (!pq.empty())
	{
		ans += pq.top();
		pq.pop();
	}

	printf("%d", -ans);
	return 0;
}
