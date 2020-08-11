#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define MAX 300000
using namespace std;

/*
	문제 설명

	1. 그림의 폭은 모두 동일하며, 높이가 다를 수도 있다.
	2. 각 그림에 가격이 매겨져 있다
	3. 그림을 순서대로 놓았을 때 앞 쪽에서 보이는 그림은 단면으로 보인다.
	4. 높이가 높은 그림은 잘보이지만 뒤 그림을 가리게 된다.
	5. 이때 특정 정수 S이상 그림이 보이면 관심을 보여서 사게된다. 이 그림을 판매가능 그림이라고 한다.

	출력

	이 그림들의 가격의 합이 최대가 되도록 배치했을 때 그 최대 합을 출력한다.
*/
int n, s, h, c;
vector<pair<int, int>> picture;
// dp[idx] : idx 그림까지 중에 조건에 만족하는 최댓값
int dp[MAX + 1];


bool swaps(pair<int, int> t1, pair<int, int> t2)
{
	return t1.first < t2.first;				// first를 기준으로 오름차순으로 정렬한다.
}


int main()
{
	cin >> n >> s;
	picture.push_back(make_pair(0, 0));
	for (int i = 0; i < n; i++)
	{
		cin >> h >> c;
		picture.push_back(make_pair(h, c));
	}
	memset(dp, 0, sizeof(dp));
	sort(picture.begin(), picture.end(), swaps);

	for (int i = 1 , j = 0; i <= n; i++)
	{
		while (picture[j + 1].first <= picture[i].first - s) j++;
		dp[i] = max(dp[i - 1], dp[j] + picture[i].second);
	}
	cout << dp[n] << endl;
	return 0;
}