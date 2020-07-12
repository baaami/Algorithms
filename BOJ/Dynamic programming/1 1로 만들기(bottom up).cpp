#include <iostream>
#include <algorithm>
using namespace std;
class makeOne {
private:
	int n;
	int arr[1000001];
public:
	void setNum()
	{
		cin >> n;
		fill_n(arr, 1000001, 0);
	}
	void solution()
	{
		arr[1] = 0;

		for (int i = 2; i <= n; i++)
		{
			arr[i] = arr[i - 1] + 1;		// 1을 빼는 경우
			if (i % 2 == 0)
			{
				arr[i] = min(arr[i], arr[i / 2] + 1);	// 2로 나누어지는 경우
			}
			if (i % 3 == 0)
			{
				arr[i] = min(arr[i], arr[i / 3] + 1);	// 3으로 나누어지는 경우
			}
		}
	}
	void printMin()
	{
		cout << arr[n];
	}
};

int main(void)
{
	makeOne a;
	a.setNum();
	a.solution();
	a.printMin();
	return 0;
}