#include <iostream>
#include <string>
#include <vector>
#include <stack>
/*
    0은 빈칸, 1 ~ 100은 각 각 다른 인형을 뜻한다.

*/
using namespace std;
int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int len = board[0].size();
    stack<int> barket;
    int column;
    for (int i = 0; i < moves.size(); i++)
    {
        // 현제 크레인의 위치
        column = moves[i] - 1;

        // loc 열의 행을 탐색
        for (int j = 0; j < len; j++)
        {
            int target = board[j][column];
            board[j][column] = 0;
            // 0이면 집어올리지 않는다.
            if (target == 0) continue;

            // 바구니가 비어있지 않은 경우
            if (!barket.empty())
            {
                // 바구니 상위에 있는 값과 같으면
                if (barket.top() == target)
                {
                    barket.pop();
                    answer += 2;
                }
                else {
                // 바구니 상위에 있는 값과 다르면, 그냥 넣는다.
                    barket.push(target);
                }
            }
            else {
            // 비어있지 않은 경우엔 그냥 넣는다.
                barket.push(target);
            }
            // 0이 아니면, 집어올려서 바구니에 넣는다.
            break;
        }
        
    }
    return answer;
}

int main()
{
    //int board[5][5] = { {0, 0, 0, 0, 0} ,{0, 0, 1, 0, 3},{0, 2, 5, 0, 1},{4, 2, 4, 4, 2},{3, 5, 1, 3, 1} };
    //
    //vector<int> moving;
    //moving.push_back(1); moving.push_back(5); moving.push_back(3); moving.push_back(5); moving.push_back(1); moving.push_back(2); moving.push_back(1); moving.push_back(4);
    //cout << solution(board, moving);
    return 0;
}