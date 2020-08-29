#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> repository;
vector<vector<int>> totallist;
// 검사해야하는 것은 2개이다.
// 1. 벌써 그 순열을 고른 경우가 있나
// 2. 순열 중 숫자 중복이 있나
int choice(int bigidx, int smallidx, vector<int> banlist)
{
	// 이경우가 모두 고른 경우
	if (bigidx == repository.size())
	{
		sort(banlist.begin(), banlist.end());
		for (int i = 0; i < totallist.size(); i++)
		{
			if (totallist[i] == banlist) return 0;
		}
		totallist.push_back(banlist);
		return 1;
	}
	if (smallidx == repository[bigidx].size()) return 0;
	int result = 0;
	// 이 인덱스를 고른 경우
	for (int i = 0; i < banlist.size(); i++)
	{
		// 중복숫자가 있는 경우
		if (repository[bigidx][smallidx] == banlist[i]) return result += choice(bigidx, smallidx + 1, banlist);
	}
	banlist.push_back(repository[bigidx][smallidx]);
	result += choice(bigidx + 1, 0, banlist);
	banlist.pop_back();
	// 이 인덱스를 고르지 않은 경우
	result += choice(bigidx, smallidx + 1, banlist);

	return result;
}

int solution(vector<string> user_id, vector<string> banned_id) {
	int answer = 0;
	int i, j, k;
	for (i = 0; i < banned_id.size(); i++)
	{
		// i 번 제재 아이디가 될 수 있는 j 번 아이디 넘버 저장
		vector<int> ban;
		for (j = 0; j < user_id.size(); j++)
		{
			// 최소한 길는 같아야한다,
			if (banned_id[i].length() != user_id[j].length()) continue;
			for (k = 0; k < banned_id[i].length(); k++)
			{
				if (banned_id[i][k] == '*') continue;
				// 다르면 끝
				if (banned_id[i][k] != user_id[j][k]) break;
			}
			if (k == banned_id[i].length())
			{
				// 끝까지 같은 경우에는
				ban.push_back(j);
			}
		}
		repository.push_back(ban);
	}

	vector<int> banlist;
	answer += choice(0, 0, banlist);
	return answer;
}

int main()
{
	vector<string> user_id; vector<string> banned_id;
	user_id.push_back("frodo"); user_id.push_back("fradi"); user_id.push_back("crodo"); user_id.push_back("abc123"); user_id.push_back("frodoc");
	banned_id.push_back("*rodo"); banned_id.push_back("*rodo"); banned_id.push_back("******"); 
	cout << solution(user_id, banned_id);
	return 0;
}