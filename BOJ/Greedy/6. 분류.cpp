#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int cnt0 = 0; int cnt1 = 0;
	string a;	cin >> a;
	char temp = a[0];		// 첫 번째 문자를 넣어놓는다.
	int swap = 0;
	for (int i = 1; i < a.length(); i++)
	{
		if (temp != a[i])
		{
			temp = a[i];
			if (swap == 0)
			{
				cnt0++;
				swap = 1;
			}
			else {
				cnt1++;
				swap = 0;
			}
		}
	}
	if (swap == 0) cnt0++;
	else cnt1++;
	
	// 001100001
	cout << min(cnt0, cnt1);
	return 0;
}