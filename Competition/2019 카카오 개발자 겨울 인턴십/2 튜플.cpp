#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#define MAX 100000
using namespace std;

bool check[MAX];
class setinfo {
public:
    vector<int> num;
    int total = 0;
};

bool moving(class setinfo t1, class setinfo t2)
{
    if (t1.total < t2.total) return true;
    return false;
}

vector<int> solution(string s) {
    vector<int> answer;
    int finish = 0;
    int element_num = 1;
    vector<class setinfo> v;
    // parsing
    // 가장 큰 { } 는 제외하기 위해서 아래와 같이 시작, 끝
    class setinfo now;
    // 1. 원소와 원소 크기를 저장하는 클래스를 벡터에 담는다.
    for (int i = s.length() - 2; i > 0; i--)
    {
        char cur = s[i];
        if (cur == '}')
        {
            element_num = 1;
        }
        if (cur == '{')
        {
            // 끝날 때 
            now.total = element_num;
            v.push_back(now);
            now.num.clear();
            now.total = 1;
            finish = 1;
        }
        // 1.1 string 숫자를 int형 정수로 변환해서 class의 벡터에 넣는다.
        if ('0' <= cur && '9' >= cur)
        {
            finish = 0;
            int idx = 0;
            int cur_number = 0;
            while (1)
            {
                cur_number += ((cur - '0') * pow(10, idx));
                if ('0' <= s[i - 1] && '9' >= s[i - 1])
                {
                    idx++; i--;
                    cur = s[i];
                }
                else {
                    break;
                }
            }
            now.num.push_back(cur_number);
        }
        //  1.2 한 원소들을 세는 중일 때 나오는 ','는 원소의 개수를 증가시키는 것이다.
        if (finish == 0 && cur == ',')
        {
            element_num++;
        }
    }
    
    // 원소의 개수를 기준으로 오름 차순 정렬
    sort(v.begin(), v.end(), moving);

    // 원소의 개수가 적은 클래스부터 숫자를 중복되지 answer에 않게 담아넣는다
    // check에 넣은 값을 true로 넣어주면서 중복된 값을 넣지 않게해준다.
    // 원소의 최대 크기가 100000이므로 bool 자료형 2byte로는 메모리 초과가 나지 않는다.
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].num.size(); j++)
        {
            // 방문하지 않았던 숫자면 값에 넣기
            if (!check[v[i].num[j]])
            {
                answer.push_back(v[i].num[j]);
                check[v[i].num[j]] = true;
            }
        }
    }
    return answer;
}

int main()
{
    string a = "{{20,111},{111}}";
    vector<int> ans;
    ans = solution(a);
    
    for (auto& abc : ans)
    {
        cout << abc << " " << endl;
    }
    return 0;
}