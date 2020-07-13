#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct info {
	int sender;
	int receiver;
	int num;
};

bool cmp(info &x, info &y)
{
	if (x.receiver < y.receiver)
		return true;
	else if (x.receiver == y.receiver)
		if (x.sender < y.sender)
			return true;
	return false;
}

int main()
{
	int n, cap;	// 마을 수, 트럭 용량
	int m;		// 보내는 박스 정보의 개수
	int cnt(0);
	cin.tie(0);
	cin >> n >> cap >> m;
	info a[10000];
	int truck[2001];
	fill_n(truck, 2001, 0);
	for (int i = 0; i < m; i++)
	{
		cin >> a[i].sender >> a[i].receiver >> a[i].num;
	}
	sort(a, a + m, cmp);			// sender를 기준으로 오름차순 정렬

	for (int i = 0; i < m; i++)
	{
		int boxcnt = 0;
		// 해당 구간을 돌면서 가장 많이 적재된 양
		for (int j = a[i].sender; j < a[i].receiver; j++)
			boxcnt = max(boxcnt, truck[j]);
		// 트럭에 더 심을 수 있는 양
		int leftspace = min(a[i].num, cap - boxcnt);
		cnt += leftspace;
		// 해당 구간에 더 적재 시킨다.
		for (int j = a[i].sender; j < a[i].receiver; j++)
			truck[j] += leftspace;
	}

	cout << cnt << endl;
	return 0;
}