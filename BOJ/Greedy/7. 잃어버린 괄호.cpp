#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int sum = 0;
	string a; cin >> a;

	vector<char> gual;
	vector<int> c;
	string temp;
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] != '-' && a[i] != '+')
		{
			temp += a[i];						// 숫자들 저장
		}
		else {
			c.push_back(atoi(temp.c_str()));	// 저장해놨던 숫자를 저장
			temp = "";
			gual.push_back(a[i]);				// 부호들 저장
		}
		if(i == a.length() -1) c.push_back(atoi(temp.c_str()));	// 마지막 숫자까지 저장
	}
	// 덧셈 먼저 해놓기
	for (int i = 0; i < gual.size(); i++)
	{
		vector<int>::iterator it;
		if (gual[i] == '+')
		{
			c[i + 1] = c[i] + c[i + 1];
			c.erase(c.begin() + i);
			gual.erase(gual.begin() + i);
			i--;
		}
	}
	
	sum = c[0];
	for (int i = 1; i < c.size(); i++)
	{
		sum -= c[i];
	}
	cout << sum;

	return 0;
}