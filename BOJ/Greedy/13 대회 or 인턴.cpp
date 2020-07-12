#include <iostream>

using namespace std;

int main()
{
	int n, m, k; cin >> n >> m >> k;
	int team;
	// 인턴 보내기
	while (k--)
	{
		if (n > 2 * m || m == n / 2)
		{
			n--;
			continue;
		}
		if (m > n / 2)
		{
			m--;
			continue;
		} 
	}
	// 팀 결성
	if (n > 2 * m || m == n / 2)
	{
		team = m;
	}
	else
	{
		team = n / 2;
	}
	
	cout << team;
	return 0;
}