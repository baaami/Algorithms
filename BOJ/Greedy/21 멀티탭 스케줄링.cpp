#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, k, cnt(0);
	cin.tie(0);
	cin >> n >> k;		// n : 멀티탭 구멍 개수, k : 사용할 전자제품 개수
	vector<int> v(k);			// 사용할 전자 제품
	vector<int> multi;		// 멀티탭에 현재 꽂혀있는 것들
	for (int i = 0; i < k; i++)
	{
		cin >> v[i];
	}
	int index = 0;
	while (1)
	{
		multi.push_back(v[index]);			// 처음부터일단 하나씩 꽂기 시작	
		if (multi.size() == n)
		{
			multi.erase(unique(multi.begin(), multi.end()), multi.end());
			if (multi.size() != n)
			{
				continue;
			}
			else {
				break;
			}
		}
		index++;
		if (index == k)
		{
			cout << 0 << endl;
			return 0;
		}
	}

	int i(0), j(0);
	// index == 1, k == 7
	for (i = index; i < k; i++)
	{
		vector<int> _new;
		vector<int> use;
		for (j = 1; j <= n; j++)		// 뒤에 있는 값들을 멀티탭 크기 만큼 본다.
		{
			if (i + j >= k) break;
			//cout << "i + j : " << i + j << endl;
			if (multi.end() == find(multi.begin(), multi.end(), v[i + j]))		// 없다 == 새로운 전자제품
			{
				_new.push_back(v[i + j]);				//	 새로운 전자제품 숫자를 넣음
				//cout << "i : "<< i << ", v[i + j] : " << v[i + j] << endl;
			}
			else {																// 있다 == 원래 거랑 중복
				use.push_back(v[i + j]);					//	  중복되는 제품을 넣음
			}
		}
		// 중복되는 제품이 아닌 콘센트 빼기
		for (j = 0; j < _new.size() + use.size(); j++)
		{
			// 새로운 제품과 바꿔야 하는 애들
			if (use.end() == find(use.begin(), use.end(), multi[j]))
			{
				multi.erase(multi.begin() + j);
				int temp = _new.back(); _new.pop_back();
				//cout << "temp : " << temp << endl;
				multi.push_back(temp);
				cnt++;
			}
		}

		//for (int m : multi)
		//	cout << "m : " << m << " ";
		//cout << endl;
		i = i + n - 1;
		if (i + j >= k) break;
	}
	
	cout << cnt;
	return 0;
}