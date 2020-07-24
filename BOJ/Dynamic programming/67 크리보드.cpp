#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 101
using namespace std;

int n;
long long dp[MAX];

// button을 누른 idx
long long solution(int idx)
{
	long long& result = dp[idx];
	if (result != -1)
		return result;

	result = solution(idx - 1) + 1;			// A추가 시킨 경우

	// CTRL A , CTRL C , CTRL V 여러번
	// 조건 2,3,4는 하나의 조건으로 생각 한다.
	// 그러므로 적어도 버튼이 2번눌리고 3번 이상부터 사용할 수 있다.
	if(idx >= 3)
		for (int i = 1; i <= idx - 2; i++)
		{
			result = max(result, solution((idx - 2) - i) * (i + 1));
		}
	return result;
}

int main()
{
	cin >> n;
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	cout << solution(n) << endl;
}

// bottom up

/*
#include<iostream>
#include<algorithm>
typedef long long ll;

using namespace std;

int main(int argc, char *argv[]) {
	int n;
	int maxNum;
	ll DP[101];

	cin >> n;

	DP[0] = 0;
	DP[1] = 1;
	DP[2] = 2;
	DP[3] = 3;
	DP[4] = 4;
	DP[5] = 5;

	for (int i = 6; i <= n; i++) {
		DP[i] = max({ DP[i - 1] + 1, DP[i - 3] * 2, DP[i - 4] * 3, DP[i - 5] * 4 });
	}

	cout << DP[n] << endl;

	return 0;
}
*/

// 내 틀린 식
/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 101
using namespace std;
// button을 n번 누른다.
int n;
// 키보드를 n번 누른 결과 A가 최대로 출력된 수
int dp[MAX];
// button 누른 횟수
int solution(int screen,int buffer ,int push, bool drag)
{
	// screen에 있는 숫자, buffer에 있는 A숫자
	if (push < 0) return 0;

	int& result = dp[push];

	if (result != -1)
		return result;

	result = 0;
	int a1, a2, a3, a4;
	a1 = a2 = a3 = a4 = -984321;
	// 화면에 A를 출력하는 경우
	a1 = solution(screen + 1, buffer, push - 1, drag) + 1;
	// 전체 선택을 하는 경우, << 전체 선택을 해야만 화면에 있는 내용을 복사할 수 있다.
	// drag가 true여야 할 수 있다.
	// drag가 안되어있는 상태에서만 하면 된다.
	if (!drag)
	{
		drag = true;
		a3 = solution(screen, buffer, push - 1, drag);
		drag = false;
	}
	// 화면에 있는 내용을 복사하는 경우
	if (drag)
	{
		int pre_buf = buffer;			// 이전에 buffer에 있던 값은 다시 가지고 있어야한다.
		drag = false;
		buffer = screen;
		a2 = solution(screen, buffer, push - 1, drag);
		buffer = pre_buf;
	}
	// Ctrl + V

	a4 = solution(screen + buffer, buffer, push - 1, drag) + buffer;
	return result = max(max(a1, a2), max(a3, a4));
}

int main()
{
	// 화면에 A를 출력하는 경우
	cin >> n;
	memset(dp, -1, sizeof(dp));
	cout << solution(0, 0, n, false);
	return 0;
}

*/
