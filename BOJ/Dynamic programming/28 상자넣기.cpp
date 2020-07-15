#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n, now; scanf("%d", &n);
	int ans = 0;
	vector<int> v;
	v.push_back(-1);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &now);
		if (v.back() < now)
		{
			v.push_back(now);
			ans++;
		}
		else {
			// v 배열에서 현재 받은 값보다 큰 것중 가장 작은 것을 now값으로 바꿔준다.
			vector<int>::iterator it = lower_bound(v.begin(), v.end(), now);
			*it = now;
		}
	}
	printf("%d\n", ans);
	return 0;
}