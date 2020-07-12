#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int,int> a, pair<int,int> b)
{
	return a.first < b.first;
}
int main()
{
	int T, n;	cin >> T;

	while (T--)
	{
		cin >> n;			// 1 < N < 100000
		vector<pair<int, int>> applicant;
		int doc, inter;		// 점수가 아니라 순위이다. 서류성적, 면접성적
		int pass = 1;
		for (int i = 0; i < n; i++)
		{
			cin >> doc >> inter;
			applicant.push_back(make_pair(doc, inter));
		}
		
		// 서류 심사 결과를 순서대로 sort한다.
		sort(applicant.begin(), applicant.end(), compare);
		
		int rank = applicant[0].second;W
		
		for (int i = 1; i < n; i++)
		{
			// 점수가 더 높은사람 채용
			if (applicant[i].second < rank)
			{
				pass++;
				rank = applicant[i].second;
			}
		}
		cout << pass << endl;
	}
	return 0;
}