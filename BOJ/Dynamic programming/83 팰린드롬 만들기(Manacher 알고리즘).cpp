#include <iostream>
#include <string>
#include <cstring>
#define MAX 1001
using namespace std;
string S;
int len;
bool palindrome(int idx)
{
	for (int i = 0; idx + i < len - i - 1; i++)
		if (S[idx + i] != S[len - i - 1])		// 모두 성립해야 팰린드롬
			return false;

	return true;
}

int main()
{
	cin >> S; len = S.length();
	int result = 0;

	// 1. 주어진 문자열의 길이가 len일 때 palindrome 되는지 확인
	// 2. 1번이 성립 안되면 len + 1일 때 palindrome 되는지 확인

	// 즉, 가능한 긴 팰린드롬부터 시작해서 해본다. 
	for (int i = 0; i < len; i++)
	{
		if (palindrome(i))
		{
			result = len + i;
			break;
		}
	}

	cout << result << endl;
	return 0;
}