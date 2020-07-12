#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	vector<int> compare;
	string a; cin >> a;
	int len = a.length();			// 숫자의 개수
	int input_num[10];
	fill_n(input_num, 10, 0);
	for (int i = 0; i < len; i++)
	{
		input_num[a[i] - '0']++;
	}
	
	if (input_num[0] > 0)				// 0 이없으면 불가능
	{
		// 3의배수는 모든 자리의 합이 3의 배수이다.
		int sum = 0;
		for (int j = 1; j < 10; j++)
		{
			sum += j * input_num[j];		// 모든 자리를 합해보기
		}
		if (sum % 3 == 0)			// 모든 자리의 합은 3의 배수인지 확인
		{
			// 맞으면 제일 큰 수 출력?
			for (int i = 9; i >= 0; i--)
			{
				for (int j = 0; j < input_num[i]; j++)
				{
					cout << i;
				}
			}
			return 0;
		}
	}
	
	cout << -1;
	
	return 0;
}