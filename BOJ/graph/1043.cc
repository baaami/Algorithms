#include <iostream>
#include <vector>

using namespace std;

#define MAX_PEOPLE_NUM 50
#define MAX_PARTY_NUM 50

int getParent(int parent[], int x) {
    if (parent[x] == x) return x;
    return parent[x] = getParent(parent, x);
}

void unionParent(int parent[], int a, int b) {
    a = getParent(parent, a);
    b = getParent(parent, b);

    if (a < b) parent[b] = a;
    else parent[a] = b;
}

int main() {
    int parent[MAX_PEOPLE_NUM + 1] = {0};
    int nMemberTotal, nPartyNum, nTruth;

    cin >> nMemberTotal >> nPartyNum;
    
    cin >> nTruth;
    vector<int> truthPeople(nTruth);

    // 부모 노드 초기화
    for (int i = 1; i <= nMemberTotal; i++) {
        parent[i] = i;
    }

    // 진실을 아는 사람들 입력 받기
    for (int i = 0; i < nTruth; i++) {
        cin >> truthPeople[i];
    }

    vector<vector<int>> parties(nPartyNum);  // 각 파티의 참석자 정보 저장

    for (int i = 0; i < nPartyNum; i++) {
        int nMemberNum;
        cin >> nMemberNum;

        parties[i].resize(nMemberNum);  // 각 파티의 멤버 수에 맞춰 resize

        for (int j = 0; j < nMemberNum; j++) {
            cin >> parties[i][j];
        }

        // 파티의 첫 번째 사람을 기준으로 나머지 사람들과 그룹을 연결
        for (int j = 1; j < nMemberNum; j++) {
            unionParent(parent, parties[i][0], parties[i][j]);
        }
    }

    // 진실을 아는 사람이 있는 경우에만 같은 그룹으로 묶기
    if (nTruth > 0) {
        for (int i = 1; i < nTruth; i++) {
            unionParent(parent, truthPeople[0], truthPeople[i]);
        }
    }

    // 과장된 이야기를 할 수 있는 파티 개수 계산
    int count = 0;
    for (int i = 0; i < nPartyNum; i++) {
        bool canLie = true;

        // 진실을 아는 사람이 있는 경우에만 확인
        if (nTruth > 0) {
            for (int j = 0; j < parties[i].size(); j++) {
                // 만약 파티 참석자 중 한 명이라도 진실을 아는 그룹에 속해 있으면 과장할 수 없음
                if (getParent(parent, parties[i][j]) == getParent(parent, truthPeople[0])) {
                    canLie = false;
                    break;
                }
            }
        }

        if (canLie) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}
