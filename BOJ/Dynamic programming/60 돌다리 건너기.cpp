#include <iostream>
#include <cstring>
#include <string>
using namespace std;

string key, bridge[2];
int dp[2][101][21];
/*
1. 왼쪽(출발지역)에서 오른쪽(도착지역)으로 다리를 지나가야 하며, 
반드시 마법의 두루마리에 적힌 문자열의 순서대로 모두 밟고 지나가야 한다.

2. 반드시 <악마의 돌다리>와 <천사의 돌다리>를 번갈아가면서 돌을 밟아야 한다. 
	단, 출발은 어떤 돌다리에서 시작해도 된다.

3. 반드시 한 칸 이상 오른쪽으로 전진해야하며, 건너뛰는 칸의 수에는 상관이 없다. 
만일 돌다리의 모양이 그림 1과 같고 두루마리의 문자열이 "RGS"라면 돌다리를 건너갈 수 있는 
경우는 다음의 3가지 뿐이다. (아래 그림에서 빨간색 문자는 밟고 지나가는 돌다리를 나타낸다.)
*/
int solution(int row, int col, int idx)
{
	// 기저 사례, 정답을 찾은 경우
	if (idx == key.length())
		return 1;

	int& result = dp[row][col][idx];
	if (result != -1)
	{
		return result;
	}

	result = 0;
	for (int i = col; i < bridge[0].length(); i++)
	{
		if (bridge[row][i] == key[idx])
		{
			result += solution(1 - row, i + 1, idx + 1);
			cout << result << endl;
		}
	}
	return result;
}

int main()
{
	int ans = 0;
	cin >> key;
	cin >> bridge[0]; cin >> bridge[1];
	memset(dp, -1, sizeof(dp));
	// 악마의 돌다리부터 시작하는 경우
	ans += solution(0, 0, 0);
	// 천사의 돌다리부터 시작하는 경우
	ans += solution(1, 0, 0);
	cout << ans;
	return 0;
}