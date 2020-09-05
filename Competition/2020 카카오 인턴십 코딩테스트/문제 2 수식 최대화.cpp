#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long solution(string expression) {
    long long answer = 0;
    vector<long long> num;
    vector<char> exp, location;
    string n = "";

    // 숫자와 연산자를 구분
    for (int i = 0; i < expression.size(); i++)
    {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*')
        {
            // 지금까지 모인 숫자 값 넣기
            num.push_back(stoi(n));
            n = "";
            // 연산자이면 연산자에 값을 넣기
            if (find(exp.begin(), exp.end(), expression[i]) == exp.end())
                exp.push_back(expression[i]);
            location.push_back(expression[i]);
        }
        else
            // 숫자 찾기
            n += expression[i];
    }

    num.push_back(stoi(n));

    // 사용된 연산자만으로 순열을 돌리면서 확인한다. 
    // 시간을 단축할 수 있는 방법
    sort(exp.begin(), exp.end());

 
    do
    {
        // 순열 이후 값초기화 
        vector<long long> tmp_num = num;
        vector<char> tmp_loc = location;

        // tmp_num에 있는 값들을 전부 연산하면서 하나의 값(연산 결과)으로 만든다.

        // 총 연산자 종류만큼 순환
        for (int i = 0; i < exp.size(); i++)
        {
            // 총 연산자 개수만큼 순환
            for (int j = 0; j < tmp_loc.size(); j++)
            {
                // j 번째에 있는 연산자와 현재 우선순위이인 연산자랑 같다면 연산
                if (exp[i] == tmp_loc[j])
                {
                    if (tmp_loc[j] == '+')
                        tmp_num[j] = tmp_num[j] + tmp_num[j + 1];
                    else if (tmp_loc[j] == '-')
                        tmp_num[j] = tmp_num[j] - tmp_num[j + 1];
                    else if (tmp_loc[j] == '*')
                        tmp_num[j] = tmp_num[j] * tmp_num[j + 1];

                    // 연산 값을 j에 저장을 했으므로 j + 1 위치에 있는 값은 제거해준다.
                    tmp_num.erase(tmp_num.begin() + j + 1);
                    tmp_loc.erase(tmp_loc.begin() + j);
                    j--;
                }
            }
        }

        if (answer < abs(tmp_num[0]))
            answer = abs(tmp_num[0]);
    } while (next_permutation(exp.begin(), exp.end()));

    return answer;
}

int main()
{
    string test;
    test = "100-200*300-500+20";

    cout << solution(test);
    return 0;
}
