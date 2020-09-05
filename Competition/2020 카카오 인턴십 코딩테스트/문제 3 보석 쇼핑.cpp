#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#define MAX 100000
using namespace std;
// 참조 : https://eunchanee.tistory.com/90
/*
    조건

    1. 진열된 모든 종류의 보석을 적어도 1개 이상 포함하는 가장 짧은 구간을 찾아서 구매

    2. 가장 짧은 구간을 찾아서 시작 진열대 번호, 끝 진열대 번호를 배열에 담아서 리턴
*/

vector<int> solution(vector<string> gems) {
    vector<int> answer = { 0, 0 };
    queue<string> q;
    map<string, int> m;

    int gems_size = 0, start = 0, end = MAX + 1, tmp = 0;

    // 모든 gems의 key 값에 1을 만든다.
    // 중복을 제거하는 것과 같다
    for (auto i : gems)
        m[i] = 1;

    // 최소한 1개는 사야되는 총 보석 개수
    gems_size = m.size();
    m.clear();


    for (int i = 0; i < gems.size(); i++)
    {
        // 담지 않은 보석을 담는다
        if (m[gems[i]] == 0)
            m[gems[i]] = 1;
        else
        // 담았던 보석이면 개수를 증가시켜준다.
            m[gems[i]] += 1;
        // 담은 보석을 q에 넣는다. <- queue의 크기가 구간 길이
        q.push(gems[i]);

        while (1)
        {
            // 보석의 가장 앞에 있는 보석이 뒤에 또 있다면 가장 앞에 있는 보석은
            // 구간 길이만 차지한다.
            if (m[q.front()] > 1)
            {
                // 그러므로 제거해줘도 된다.
                m[q.front()] -= 1;
                q.pop();

                // 그럼 시작하는 구간이 당겨지므로 tmp로 그 값을 세준다.
                tmp++;
            }
            else
                break;
        }

        // 보석을 다 모았고, 
        // end : q.size()를 넣는 곳이므로 지금까지 구간 중 최소 구간인지 확인해준다.
        if (m.size() == gems_size && end > q.size())
        {
            end = q.size();
            start = tmp;
        }
    }
    // 0부터 시작했으므로 start + 1을 해준다.
    answer[0] = start + 1;
    // 시작 위치 + 구간길이가 end위치
    answer[1] = start + end;
    return answer;
}

int main()
{
    vector<string> gems = { "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" };
    vector<int> ans;
    ans =  solution(gems);
    cout << ans[0] << " " << ans[1];
    return 0;
}