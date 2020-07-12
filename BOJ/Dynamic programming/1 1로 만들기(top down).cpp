#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 1000001

int arr[MAX];

int go(int n)
{
	if (n == 1) return 0;
	if (arr[n] > 0) return arr[n];		// 해당 저장 공간에 값이 존재할 경우, 그 값을 반환 매우 중요

	arr[n] = go(n - 1) + 1;
	if (n % 2 == 0)
	{
		int temp = go(n / 2) + 1;
		if (temp < arr[n])
		{
			arr[n] = temp;
		}
	}
	if (n % 3 == 0)
	{
		int temp = go(n / 3) + 1;
		if (temp < arr[n])
		{
			arr[n] = temp;
		}
	}
	return arr[n];
}

int main()
{
	fill_n(arr, MAX, 0);
	int n; cin >> n;

	go(n);

	cout << arr[n];
	
	return 0;
}