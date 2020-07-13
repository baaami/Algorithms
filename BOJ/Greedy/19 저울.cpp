#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1000000001;
int n;
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);		// cin 실행속도 향상
	cin >> n;

	v.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	// 1 이 없으면 바로 끝
	if (v[0] != 1)
	{
		cout << 1 << endl;
	}
	else {
		int sum = 1;
		// 현재까지의 합 + 1 보다 큰 값이 다음 인덱스에 저장되어 있다면
		// 이전의 추들로 무게를 구할 수가 없는 상태가 된다.
		for (int i = 1; i < n; i++)
		{
			if (v[i] > sum + 1) break;
			sum += v[i];
		}
		cout << sum + 1 << endl;
	}
	
	return 0;
}
