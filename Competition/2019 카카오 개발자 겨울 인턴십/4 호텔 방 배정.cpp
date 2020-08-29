#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define MAX 200002
using namespace std;
/*
        k개의 방을 배정하는 조건

        1. 한 번에 한 명씩 신청한 순서대로 방을 배정합니다.
        2. 고객은 투숙하기 원하는 방 번호를 제출합니다.
        3. 고객이 원하는 방이 비어 있다면 즉시 배정합니다.
        4. 고객이 원하는 방이 이미 배정되어 있으면 원하는 방보다 번호가 크면서 비어있는 방 중 가장 번호가 작은 방을 배정합니다.

        입력

        1. 전체 방 개수 : k개
        2. 원하는 방 

        출력

        실제로 배정된 방
*/
unordered_map<long, long> m;
vector<long long> answer;

long long find_n(long long n)
{
    if (m[n] == 0)
    {
        m[n] = n + 1;
        answer.emplace_back(n);
        return n;
    }
    return m[n] = find_n(m[n]);
}
vector<long long> solution(long long k, vector<long long> room_number) {
 
    m.reserve(MAX); 
    answer.reserve(MAX);

    for (int i = 0; i < room_number.size(); i++)
    {
        long long n = room_number[i];
        // 방이 비어있으면
        if (m[n] == 0)
        {
            answer.emplace_back(n);
            m[n] = n + 1;
        }
        else {
        // 방이 비어있지 않으면
            find_n(n);
        }
    }
    return answer;
}

int main()
{
    int k = 0;
    vector<long long> room_number;
    room_number.push_back(1); room_number.push_back(3); room_number.push_back(4); room_number.push_back(1); room_number.push_back(3); room_number.push_back(1);
    vector<long long > answer;
    answer =  solution(k, room_number);

    for (auto b : answer)
    {
        cout << b << " ";
    }
	return 0;
}