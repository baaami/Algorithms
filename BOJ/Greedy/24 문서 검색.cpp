#include <iostream>
#include <string>

using namespace std;

int main()
{
	string a, b; 
	cin.tie(0);
	getline(cin, a);
	getline(cin, b);

	if (b.size() > a.size())
	{
		cout << 0 << endl;
		return 0;
	}
	int i, j;

	int ans = 0;
	for (i = 0; i < a.length() - b.length() + 1; i++)
	{
		bool same = true;
		for (j = 0; j < b.size(); j++)
		{
			if (a[i + j] != b[j])
			{
				same = false;
				break;
			}
		}
		// same이 false인 경우 i는 0 > 1로 1만증가해서 비교하게된다.
		if (same)
		{
			ans++;
			i += b.size() - 1;
		}
	}
	cout << ans;
	return 0;
}