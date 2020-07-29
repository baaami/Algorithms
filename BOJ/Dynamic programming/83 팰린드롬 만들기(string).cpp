#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#define MAX 1001
//https://www.acmicpc.net/problem/1254
using namespace std;
// dp[left][right] : left ~ right까지 팰린드롬 구간
/*
	문자열 S 뒤에 0개의 문자를 추가해서 팰린드롬을 만든다.
	가장 짧은 문자열을 만들 경우 그 길이를 출력하라.

	뒤에서 더해줘야하는 문자의 최소개수를 찾는다.
*/
string S;			// abab
int len;

int solution()
{
	int result = 0;

	for (int i = 0; i < len - 1; i++)
	{
		// 양 끝이 같다면
		if (S[i] == S[len - 1])
		{
			// 하나씩 값을 당긴다.
			int start = i;
			int end = len - 1;
			// (len - i) / 2 이 숫자가 중요
			// len : 4, i : 1 이므로 3/2 = 1 이니까 j = 0일때 for문을 돈다
			for (int j = 0; j < (len - i) / 2; j++)
			{
				if (S[start] == S[end])
				{
					start++;
					end--;
				}
				else {
					result++;
					break;
				}
			}
			// 더이상 당길 수 없는 경우
			if (start >= end)
				break;
		}
		else
			result++;
	}

	return result;
}

int main()
{
	cin >> S; len = S.length();

	// 문자열 내에 있는 가장 긴 팰린드롬의 길이가 출력
	cout << len + solution();

	return 0;
}