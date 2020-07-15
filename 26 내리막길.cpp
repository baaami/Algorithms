#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n, m;
int input[501][501];
int dp[501][501]; //값 저장 메모장
int a[4] = { 1, 0, -1, 0 };
int b[4] = { 0, 1, 0, -1 };
int dfs(int x, int y)
{
    if (dp[x][y] != -1) return dp[x][y]; //값이 이미 있는경우 또계산하지말고 있는값 리턴
    if (x < 0 || x >= n || y < 0 || y >= m) return 0; //범위 벗어난 경우는 불가능하므로 0리턴
    if (x == 0 && y == 0) return 1; //기저사례

    dp[x][y] = 0;
    for (int i = 0; i < 4; i++)
    {
        int nextX = x + a[i];
        int nextY = y + b[i]; //상하좌우 모두 이동가능하므로.

        if (input[nextX][nextY] > input[x][y])
            dp[x][y] += dfs(nextX, nextY);
    }

    return dp[x][y];
}
int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &input[i][j]);

    memset(dp, -1, sizeof(dp));

    printf("%d", dfs(n - 1, m - 1));

    return 0;
}