#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 21
using namespace std;
int a, b, c;		
int dp[MAX][MAX][MAX];

// 기저사례로 들어와서 연산이 될 수 있는 크기는 0 ~ 20이다
int w(int x, int y, int z)
{

	if (x <= 0 || y <= 0 || z <= 0)
		return 1;

	if (x > 20 || y > 20 || z > 20)
		return w(20, 20, 20);

	int& result = dp[x][y][z];
	if (result != -1)
		return result;

	if (x < y && y < z)
		result = w(x, y, z - 1) + w(x, y - 1, z - 1) - w(x, y - 1, z);
	else
		result = w(x - 1, y, z) + w(x - 1, y - 1, z) + w(x - 1, y, z - 1) - w(x - 1, y - 1, z - 1);

	return result;
}


int main()
{
	
	while (1)
	{
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1)
			break;
		memset(dp, -1, sizeof(dp));
		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << endl;
	}
	return 0;
}