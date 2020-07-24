#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100000
using namespace std;
int n;
int ans;

int solution(int v)
{
	if (ans <= v)
	{
		ans = v;
	}
	if (v == 1) return ans;
	else {
		return v % 2 ? solution(v * 3 + 1) : solution(v / 2);
	}
}

int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		ans = n;
		printf("%d\n", solution(n));
	}
	return 0;
}