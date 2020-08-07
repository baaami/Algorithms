#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/1092
int crain_n, box_n;
vector<int> crain, box;
int cnt = 0;

void Input()
{
	int value;
	cin >> crain_n;
	for (int i = 0; i < crain_n; i++)
	{
		cin >> value; crain.push_back(value);
	}

	cin >> box_n;
	for (int i = 0; i < box_n; i++)
	{
		cin >> value; box.push_back(value);
	}
}
int main()
{
	Input();
	
	// 내림차순 정렬한다.
	sort(crain.begin(), crain.end(), greater<int>());
	sort(box.begin(), box.end(), greater<int>());

	// 기저 사례
	if (crain[0] < box[0])
	{
		cout << -1;
	}
	else {
		// box를 전부 옮길 때까지 돌기
		while (box.size())
		{
			int crain_idx = 0;
			for (int i = 0; i < box.size(); i++)
			{
				// 모든 크레인이 동작한 경우
				if (crain_idx == crain.size())
					break;
				// 옮길 수 있는 경우
				if (crain[crain_idx] >= box[i])
				{
					// 다음 크레인으로 이동
					crain_idx++;
					box.erase(box.begin() + i);
					--i;
				}
			}
			cnt++;
		}
		cout << cnt;
	}

	return 0;
}