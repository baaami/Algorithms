#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#define INF 987654321
#define MAX 30
using namespace std;
/*
    직선도로 : 100원
    코너 : 500원
*/
// 상하좌우

// 1. 왔던 곳을 다시 가는건 의미가 없으므로 제거
// 2. 코너를 찾기 위한 방법은 
/*
    dir이 2, 3이었는데 다음 가는 방향이 0, 1인경우
    dir이 0, 1이었는데 다음 가는 방향이 2, 3인경우
*/
// 3. 맨처음 시작할때 0으로시작하므로 이때는 무조건 직선도로를 설치하는 것이라고 예외 처리

// 0 : 아래
// 1 : 위
// 2 : 오른쪽
// 3 : 왼쪽
const int dx[] = { 0,0,-1,1 }, dy[] = { -1,1,0,0 };
struct path {
    int x, y, z;
};

int solution(vector<vector<int>> board) {
    int answer = 0;
    int siz = board[0].size();
    int dist[26][26][4];
    memset(dist, 1000000, sizeof(dist));
    queue<path> q;
    // 아래 오른쪽 으로 시작
    q.push({ 0,0,1 });
    q.push({ 0,0,3 });
    dist[0][0][1] = dist[0][0][3] = 0;
    while (!q.empty())
    {
        int x = q.front().x, y = q.front().y;
        int z = q.front().z; q.pop();
        int lastcost = dist[x][y][z];
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || nx >= siz || ny < 0 || ny >= siz || board[nx][ny]) continue;
            if (k == z) { //같은 방향으로 이동할 때
                if (dist[nx][ny][k] > lastcost + 100) {
                    dist[nx][ny][k] = lastcost + 100;
                    q.push({ nx,ny,k });
                }
            }
            else if (dist[nx][ny][k] > lastcost + 600) { //다른 방향으로 이동할때 코너 비용 추가
                dist[nx][ny][k] = lastcost + 600;
                q.push({ nx,ny,k });
            }
        }
    }
    // 마지막은 오른쪽으로 들어온 것, 위에서들어온 것
    answer = min(dist[siz - 1][siz - 1][1], dist[siz - 1][siz - 1][3]);
    return answer;
}

int main()
{
    vector<vector<int>> board;
    board = { {0, 0, 1, 0 },{0, 0, 0, 0 },{0, 1, 0, 1 },{1, 0, 0, 0 } };
    cout << solution(board);
    return 0;
}

/*
    [[0, 0, 0, 0, 0, 0, 0, 1], [0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 1, 0, 0], [0, 0, 0, 0, 1, 0, 0, 0], [0, 0, 0, 1, 0, 0, 0, 1], [0, 0, 1, 0, 0, 0, 1, 0], [0, 1, 0, 0, 0, 1, 0, 0], [1, 0, 0, 0, 0, 0, 0, 0]]
*/