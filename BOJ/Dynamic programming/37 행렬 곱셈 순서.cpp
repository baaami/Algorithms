#include <iostream>
#include <string>
#include<cstring>
#include<queue>
#include <vector>
#include <algorithm>
#include<cmath>
using namespace std;

int n, diagonal;
//행렬A_i~부터 A_j까지 곱셈 연산 최소값 저장 M[i][j];
int M[501][501];
int d[501];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> d[i] >> d[i + 1];
    }

    for (diagonal = 1; diagonal <= n - 1; diagonal++) {
        for (int i = 1; i <= n - diagonal; i++) {
            int j = i + diagonal;
            for (int k = i; k <= j - 1; k++) {
                if (M[i][j] == 0 || (M[i][j] > M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j])) {
                    M[i][j] = M[i][k] + M[k + 1][j] + d[i - 1] * d[k] * d[j];
                }
            }
        }
    }
    cout << M[1][n];

    return 0;
}


/*
6
4 2
2 3
3 1
1 2
2 2
2 3
*/