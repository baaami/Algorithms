#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

// 이분 탐색으로 풀어야 하는 문제
// lower_bound
// 이진탐색 기반의 탐색 방법이다.
// 찾으려하는 key값이 없으면 key값보다 큰 가장 작은 정수 값을 찾는다.
// 같은 원소가 여러 개 있어도 상관없고 항상 유일한 해를 구할 수 있다.

int main() {

    int n, i, temp;
    cin >> n;
    vector<int> dp;
    dp.push_back(0);

    for (i = 0; i < n; i++) {
        cin >> temp;
//        cout << "dp.back () : " << dp.back() << endl;
        if (dp.back() < temp) dp.push_back(temp);
        else {
//            cout << "dp.back : " << dp.back();
            vector<int>::iterator it = lower_bound(dp.begin(), dp.end(), temp);
            cout << " temp : " << temp << endl;
            *it = temp;         // 4부분에 2를 넣는다.
            for (int a : dp)
            {
                cout << "dp의 값 : " << a << endl;
            }
        }
    }

    printf("%lu\n", dp.size() - 1);

    return 0;
}