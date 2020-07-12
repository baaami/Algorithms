#include <iostream>
using namespace std;
int n;
long long d[101];
int main()
{
	int t; cin >> t;
	d[1] = d[2] = d[3] = 1;
	while (t--)
	{
		cin >> n;
		for (int i = 4; i <= n; i++)
		{
			d[i] = d[i - 2] + d[i - 3];
		}
		cout << d[n] << endl;
	}
	return 0;
