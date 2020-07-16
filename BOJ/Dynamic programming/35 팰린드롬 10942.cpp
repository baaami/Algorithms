//#include <cstdio>
//#include <cstring>
//#include <vector>
//using namespace std;
//int n, t;
//int a[2001];
//int dp[2001][2001];
////https://www.acmicpc.net/problem/10942
//// 재귀로 풀이
//int palin(int x, int y)
//{
//	if (x >= y) return 1;
//	int &ret = dp[x][y];			
//	if (ret != -1) return ret;
//	if (a[x] == a[y])
//	{
//		//ret = palin(x + 1, y - 1);
//		//dp[x][y] = ret;
//		return ret = palin(x + 1, y - 1);	 // &ret로 선언하였으므로
//		//	   dp[x][y] = palin(x + 1, y - 1) 값이 들어가고 안가고의 차이가 나게 된다.
//	}
//	else {
//		return 0;
//	}
//	return true;
//}
//
//int palin2(int x, int y)
//{
//	int i, j;
//	for (i = x, j = y; i < j; i++, j--)
//	{
//		if (a[i] == a[j])
//		{
//			// 여기서 dp[i][j]에 1을 넣기에는 
//			// 끝까지갔을때 팰린드롬인지 알 수 없으니
//			// 재귀함수를 써서 나올때 1을 넣어주는 방식을 위에서 사용했다.
//		}
//	}
//}
//
//int main()
//{
//	int s, e;
//	memset(dp, -1, sizeof(dp));
//	scanf("%d", &n);
//	for (int i = 1; i <= n; ++i)
//	{
//		scanf("%d", &a[i]);
//		dp[i][i] = true;				// 길이가 1
//	}
//	scanf("%d", &t);
//	while (t--)
//	{
//		scanf("%d %d", &s, &e);
//		printf("%d\n", palin(s, e));
//	}
//	return 0;
//}
#include <cstdio>
#include <cstring>
#define MAX 2000
using namespace std;
int a[MAX + 1];
int dp[MAX + 1][MAX + 1];			// x에서 y까지가 팰린드롭인지 아닌지 확인 후 메모이제이션
int n,m, s, e;
int falin(int x, int y)
{
	if (x >= y) return 1;			// 끝난 경우 
	int& ret = dp[x][y];
	if (ret != -1) return ret;
	if (a[x] == a[y])
	{
		return ret = falin(x + 1, y - 1);
	}
	else {
		return 0;
	}
	return true;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	memset(dp, -1, sizeof(dp));
	scanf("%d", &m);
	while (m--)
	{
		scanf("%d %d", &s, &e);
		printf("%d ", falin(s, e));
	}
	return 0;
}