#include <iostream>
#include <vector>
using namespace std;

const int MAX = 10;
int line[MAX];

int main()
{
	int n; cin >> n;

	for (int i = 0; i < n; i++)
	{
		int left; cin >> left;

		// 줄을 순회하는 부분
		for (int j = 0; j < n; j++)
		{
			// 자신보다 큰사람이 없고 , 자리가 비어있다면 앉기
			if (left == 0 && line[j] == 0)
			{
				line[j] = i + 1;
				break;				// 앉았으므로 다음 사람 줄 순회하기
			}						
			else if(line[j] == 0)		// 왼쪽에 자기보다 큰 사람이 더 있어야 하는데 자리가 비어있다면
			{
				left--;					// 그 좌석이 아닌 다음 좌석을 가야한다.
			}
		}
	}

	for (int i = 0 ; i < n; i++)
	{
		cout << line[i] << " ";
	}
	return 0;
}


/*
int main()
{
	int n; cin >> n;
	vector<int> a(n), b(n);

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i < n; i++)
	{
		int temp = a[i];

		while (b[temp])
		{
			temp++;
		}
		b[temp] = i + 1;
	}

	for (int &c : b)
	{
		cout << c << " ";
	}
	return 0;
}
*/