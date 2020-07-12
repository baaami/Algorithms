#include <iostream>
#include <vector>
using namespace std;
int n;
int v[100001];
long long max_value;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}
	max_value = v[1];

	for (int i = 2; i <= n; i++){
		if (v[i - 1] > 0 && v[i] + v[i - 1] > 0) {
			v[i] += v[i - 1];
		}
		if (max_value < v[i]) {
			max_value = v[i];
		}
	}
	cout << max_value << endl;
	return 0;
}