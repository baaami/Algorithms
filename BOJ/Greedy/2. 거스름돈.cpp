#include <iostream>

//https://www.acmicpc.net/problem/5585

using namespace std;

int main()
{
	int En; cin >> En;	// ¹ÞÀº µ·
	int give = 1000 - En;
	int pocket[6] = { 500, 100, 50 ,10 ,5 ,1 };
	int change(0);  int cnt(0); int index(0);

	while(1)
	{
		if (change + pocket[index] > give)
		{
			index++;
			continue;
		}
		change += pocket[index];
		cnt++;
		if (change == give) break;
	}

	cout << cnt;
	return 0;
}