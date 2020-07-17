//#include <iostream>
//#include <string>
//using namespace std;
//long long dp[1000001];
//// 양수인 X의 자릿수가 큰 자릿수부터 작은 자릿수까지 감소한다면, 그 수를 감소하는 수라고한다.
//// Ex 1. 432, 950은 감소하는 수지만 322, 928은 아니다.
//// 문제 : N번째 감소하는 수를 출력하는 프로그램을 작성하시오.
//
//// 문제 파악 : 감소하는 수를 찾는 것인데 0은 0번째 감소 1은 1번째 감소하는 수이다..?
////				만약 N번째 감소하는 수가 없다면 -1을 출력해야 한다.
//bool check(string a)
//{
//	for (int i = 0; i < a.length() - 1; i++)
//	{
//		if (a[i] <= a[i + 1])
//		{
//			return false;
//		}
//	}
//	return true;
//}
//
//int main()
//{
//	int n; cin >> n;
//	for (int i = 0; i <= 10; i++)		// 1의 자리수 먼저 채워 넣기
//	{
//		dp[i] = i;
//	}
//	int num = 19;
//	for (int i = 11; i <= n; i++)
//	{
//		// 감소하는 수인지 확인해야한다. 11부터 시작
//		while (1)
//		{
//			num++;
//			// 증가하는 수가 나오게 되면 처음엔 10의 자리 그 다음은 다음 자리
//			// 최고자리수의 값을 증가시준다.
//			if (check(to_string(num)))			// check 함수로 num이 감소하는 수인지 확인되면
//			{
//				dp[i] = num;
//				break;
//			}
//		}
//	}
//	cout << dp[n];
//
//	return 0;
//}
#include <iostream>
#include <queue>
using namespace std;
const int MAX = 1000000;

int n;
int idx = 9;	// 1 ~ 9는 이미 감소수라고 여김
// idx는 idx번째로 감소하는 수의 위치가 된다.
queue<long long> q;
long long descending[MAX + 1];

void preCalculate()
{
	while (idx <= n)
	{
		if (q.empty())
			return;
		long long descendingNum = q.front();		// 처음에는 1이 나올 것이다. << 감소하는 수
		q.pop();
		// 마지막 숫자 확인
		int lastNum = descendingNum % 10;			//
		// 마지막 자리 숫자보다 작은 숫자들을 붙여 나간다.
		for (int i = 0; i < lastNum; i++)
		{
			q.push(descendingNum * 10 + i);
			descending[++idx] = descendingNum * 10 + i;
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= 9; i++)
	{
		q.push(i);
		descending[i] = i;
	}
	preCalculate();

	if (!descending[n] && n)		// N이 범위 초과하면
		cout << -1 << endl;
	else {
		cout << descending[n] << endl;
	}
	return 0;
}