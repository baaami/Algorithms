#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#define MAX 251
using namespace std;
// https://www.acmicpc.net/problem/1793
int n;
string dp[MAX];			// n번째의 string값을 가지고 있는다.
/*
	알고리즘은 dp[n] = (dp[n - 2] * 2) + dp[n - 1]) 이다.

	여기서 long long으로 표현을 할 수가 없다. ( MOD가 없기 때문 )
	그러므로 큰 값들을 string을 이용해서 더해줘야한다.
*/

string add(string num1, string num2)
{
	long long sum = 0;
	string result;

	// 1의 자리부터 더하기 시작
	while (!num1.empty() || !num2.empty() || sum)
	{
		if (!num1.empty())
		{
			// 맨 뒤의 값 을 더해준다.
			sum += num1.back() - '0';
			// 맨 뒤의 값을 pop한다.
			num1.pop_back();
		}
		if (!num2.empty())
		{
			// 맨 뒤의 값 을 더해준다.
			sum += num2.back() - '0';
			// 맨 뒤의 값을 pop한다.
			num2.pop_back();
		}
		// 다시 string 형태로 만들어서 push_back을 한다.
		result.push_back((sum % 10) + '0');
		sum /= 10;		// 1의자리에서 10의 자리로 올림을 한 상태라면 
					    // 그 10의 자리 값을 남겨둔다. 1 or 0일 것이다. 
		cout << sum;
	}
	// 1의 자리부터 result에 넣어줬으므로 뒤집기.
	reverse(result.begin(), result.end());
	return result;
}

int main()
{
	dp[0] = dp[1] = '1';
	for (int i = 2; i <= 250; i++)
		dp[i] = add(add(dp[i - 2], dp[i - 2]), dp[i - 1]);
	// n을 몇번 입력받는지 알 수 없으므로 다음과 같이 입력한다.
	while (~scanf("%d", &n))
	{
		cout << dp[n] << endl;
	}
	return 0;
}