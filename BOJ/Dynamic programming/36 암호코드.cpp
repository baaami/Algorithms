#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
int DP[5010];
int mod = 1000000;
int main()
{
	int c = 2; int sum;
	string n;
	memset(DP, 0, sizeof(DP));
	DP[0] = 1;
	DP[1] = 1;
	cin >> n;
	if (stoi(n.substr(0, 1)) == 0) {
		cout << "0" << endl;
		return 0;
	}
	while (c <= n.length()) {
		int x = stoi(n.substr(c - 1, 1));			// c - 1번째 부터 길이 1을 리턴한 값을 int로 바꿈
		int y = stoi(n.substr(c - 2, 2));			// c = 2부터 길이 2를 리턴한 값을 int로 바꿈

		if (x > 0 && x < 10) {
			DP[c] = DP[c - 1];
		}
		if (y > 9 && y < 27) {
			DP[c] = (DP[c - 2] + DP[c]) % mod;
		}
		c++;
	}
	sum = DP[n.length()];
	cout << sum << endl;
	return 0;
}