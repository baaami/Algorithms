#include <iostream>
#include <string>
using namespace std;

const int MAX = 50;

string board;

int main()
{
	cin.tie(0); cin >> board;
	int cnt(0);

	for (int i = 0; i < board.length(); i++)
	{
		if (board[i] == 'X')
		{
			cnt++;
		} 
		else {
			if (cnt % 2)			// 홀 수 일때 끝나면 못채워넣음
			{
				cout << -1;
				return 0;
			}
			cnt = 0;
		}
		if (cnt == 4)
		{
			// 현재 i - 3 위치부터 i 까지 전부 A를 넣는다.
			board[i - 3] = board[i - 2] = board[i - 1] = board[i] = 'A';
			cnt = 0;
		}
		if (cnt == 2)
		{
			if (i + 1 == board.length())
			{
				board[i - 1] = board[i] = 'B';
			} else if (board[i + 1] == '.')		// 다음 이 .이라서 2개일 때
			{
				board[i - 1] = board[i] = 'B';
				cnt = 0;
			}
		}
	}
	if (cnt % 2)
	{
		cout << -1;
	}
	else cout << board << endl;
	return 0;
}