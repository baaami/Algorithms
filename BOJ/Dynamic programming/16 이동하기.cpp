#include <cstdio>
using namespace std;
int get_max(int a, int b, int c) {
    int max = 0;
    if (max < a) max = a;
    if (max < b) max = b;
    if (max < c) max = c;
    return max;
}

int main() {

    int N, M, i, j, max, temp;
    int arr[1001][1001];
    scanf("%d %d", &N, &M);
    for (i = 1; i <= N; i++) {
        for (j = 1; j <= M; j++) {
            scanf("%d", &temp);
            max = get_max(arr[i - 1][j - 1], arr[i - 1][j], arr[i][j - 1]);
            arr[i][j] = temp + max;
        }
    }

    printf("%d\n", arr[N][M]);

    return 0;
}