#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
// 자료구조 잘 사용하기
int main() {

    int n, k, i;
    char str[500001];
    deque<char> dq;

    scanf("%d %d", &n, &k);
    scanf("%s", str);

    for (i = 0; i < n; i++) {
        while (k && !dq.empty() && dq.back() < str[i]) {
            dq.pop_back();
            k--;
        }
        dq.push_back(str[i]);
    }

    for (i = 0; i < dq.size() - k; i++) {
        printf("%c", dq[i]);
    }

    printf("\n");

    return 0;
}