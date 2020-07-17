#include <iostream>
#include <algorithm>
using namespace std;
int n;
int a[201];
int dp[201];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (a[i] > a[j] && dp[j] + 1 > dp[i])
			{
				dp[i] = dp[j] + 1;
			}
		}
	}
	cout << n - *max_element(dp, dp + n);

	return 0;
}



//
//
//
//#include <iostream>
//#include <vector>
//using namespace std;
//int n;
//
//int main()
//{
//	vector<int> v;
//	cin >> n;
//	int value, cnt = 0;
//	v.push_back(0);
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> value;
//		v.push_back(value);
//	}
//
//	while (1)
//	{
//		int max_dif = 0;
//		int max_index = -1;
//		int insert_value = 0;
//		vector<int>::iterator it, now;
//		it = v.begin() + 1;		// v의 첫번째 원소부터 시작
//		for (int i = 1; i <= n; i++, it++)
//		{
//			if (abs(i - v[i]) > max_dif)			// 차이가 가장 큰 것
//			{
//				// a[i]의 값을 i 위치에 넣어줘야한다.
//				// 일단 a[i]를 삭제
//				max_index = i;
//				max_dif = abs(i - v[i]);
//				insert_value = v[i];
//				now = it;
//			}
//		}
//		if (max_dif == 0) break;			//  차이가 나는 것이 없으면 끝난 것
//		// 제일 차이가 큰 곳을 지우고.
//		v.erase(now);
//		v.insert(v.begin() + insert_value, insert_value);
//
//		for (int i = 1; i <= n; i++)
//		{
//			cout << v[i] << " ";
//		}
//		cout << endl;
//		cnt++;
//	}
//	
//	cout << cnt;
//	return 0;
//}
