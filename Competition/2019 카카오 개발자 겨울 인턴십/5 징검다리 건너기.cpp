#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
    니니즈 친구들이 징검다리를 건널 때의 규칙

    1. 징검다리는 일렬로 놓여 있고 각 징검다리의 디딤돌에는 모두 숫자가 적혀 있으며 디딤돌의 숫자는 한 번 밟을 때마다 1씩 줄어듭니다.
    2. 디딤돌의 숫자가 0이 되면 더 이상 밟을 수 없으며 이때는 그 다음 디딤돌로 한번에 여러 칸을 건너 뛸 수 있습니다.
    3. 단, 다음으로 밟을 수 있는 디딤돌이 여러 개인 경우 무조건 가장 가까운 디딤돌로만 건너뛸 수 있습니다.
    4. 한 명이 모두 건너고 나서야 다음 인원이 건너갈 수 있다.

    입력

    (1) 디딤돌에 적힌 숫자 순서대로 담긴 배열
    (2) 한 번에 건너뛸 수 있는 디딤돌의 최대 칸수

    출력

    -> 최대 몇명까지 징검다리를 건널 수 있는지를 return
*/

using namespace std;

bool check(vector<int> stones, int k, int mid) {
	int cnt = 0;
	for (int i = 0; i < stones.size(); i++) {
		// 현재 인원 수가 돌의 숫자보다 더 큰 경우가 k번 이상 연속된다면 불가능
		if (stones[i] < mid) {
			cnt++;
			if (cnt >= k) return false;
		}
		else cnt = 0;
	}
	// 돌의 숫자가 0이되는 경우가 k번 이상 연속되지 않는다면 가능
	return true;
}


int solution(vector<int> stones, int k) {
	int answer = 0;

	int right = *max_element(stones.begin(), stones.end());
	int left = 1;

	// 징검다리를 건너는 인원 수를 기준으로 이분탐색
	while (left <= right) {
		int mid = (left + right) / 2;
		if (check(stones, k, mid)) {
			left = mid + 1;
			if (answer < mid) {
				answer = mid;
			}
		}
		else {
			right = mid - 1;
		}
	}

	return answer;
}

int main()
{
    vector<int> stones = { 2, 4, 5, 3, 2, 1, 4, 2, 5, 1 };
    int k = 3;
    cout << solution(stones, k);
    
	return 0;
}