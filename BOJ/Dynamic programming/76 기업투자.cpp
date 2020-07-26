#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstring>
#define MAXCOST 301
#define MAXCOMP 22
using namespace std;
//https://www.acmicpc.net/problem/2662
int n, m;
int table[MAXCOST][MAXCOMP];
// dp[n][m] : m 기업에게 n만큼 투자했을 때 얻을 수 있는 최대이익금
int dp[MAXCOST][MAXCOMP];
// investment[현재 보유하고 있는 금액][투자금액]을 출력하고 현재 보유하고 있는 금액을 갱신해준다.
int investment[MAXCOST][MAXCOMP];
/*
	- 문제 설명 -

	각 기업에 돈을 투자했을 때 이득 볼 수 있는 이득 테이블이 주어진다.
	투자액이 정해져있고, 각 기업에 투자했을 때 
	가장 많은 이익을 얻을 수 있는 투자 방식, 이익금을 구하는 프로그램을 작성하라

	- 제약 조건 -

	같은 기업에 돈을 나누어 투자는 불가능하다.

	- 출력 -

	최대이익금을 찾았을 때, 1 ~ m 기업까지 각 각 얼마나 투자했고, 그 이익금을 출력

	1 ~ m 기업까지 각 각 얼마나 투자했는지 <- 이 부분 찾는 것이 중요
*/

int solution(int company, int money)
{
	// 기저 사례
	if (company == m + 1 || money == 0) return 0;
	
	int& result = dp[money][company];
	if (result != -1)
		return result;

	for (int i = 0; i <= money; i++)
	{
		// 현재 company에게 money만큼 투자하는 경우
		int now = solution(company + 1, money - i) + table[i][company];
		if (result < now)
		{
			// [현재 보유하고 있는 금액][투자금액] 에 넣어준다.
			
			investment[money][company] = i;   /****/
			result = now;
		}
	}

	return result;
}

int main()
{
	cin >> n >> m;
	memset(table, 0, sizeof(table));
	memset(investment, 0, sizeof(investment));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			cin >> table[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));
	// 투자금 n을 넘겨준다.
	cout << solution(1, n) << endl;
	/***********/
	for (int i = 1; i <= m; i++)
	{
		// 첫번째 : 보유한 금액이 n일 때 1번째 회사에 투자한 금액
		// 두번쨰 : 보유한 금액이 n일 때 2번째 회사에 투자한 금액
		//                            .
		//                            .
		//                            .
		// m번째 : 보유한 금액이 n일 때 m번째 회사에 투자한 금액
		cout << investment[n][i] << " ";
		n -= investment[n][i];
	}
	return 0;
}