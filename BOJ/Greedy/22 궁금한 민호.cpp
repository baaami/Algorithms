#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 20;
int d[MAX][MAX];
bool _copy[MAX][MAX];
int check;
int n;

void floyd()
{
	// 이 나라에 존재할 수 있는 도로의 개수의 최솟값, 이 때 모든 도로의 시간의 합을 구하기
    // 플로이드 와샬 알고리즘을 역으로 생각하여 문제를 해결하자.
    // 1. 모든 도시를 간선으로 연결
    // 2. 거쳐가는 도시가 있을 경우 출발 도시와 도착 도시간의 간선은 없앤다.

    //  k : 거쳐가는 도시
    for (int k = 0; k < n; k++)
    {
        // i : 출발도시 , j : 도착도시
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == k || j == k || i == j) 
                    continue;
                if (d[i][j] > d[i][k] + d[k][j])
                {
                    check = -1;
                    return;
                }
                else if (d[i][j] == d[i][k] + d[k][j])
                {
                    _copy[i][j] = false;
                }
            }
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> d[i][j];
            _copy[i][j] = true;
        }
    }

    floyd();

    if (check == -1) cout << -1 << endl;
    else 
    {
        int sum = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (_copy[i][j])
                {
                    sum += d[i][j];
                }
            }
        }
        cout << sum / 2 << endl;
    }

    return 0;
}

/* 플로이드 알고리즘 ( 최단 경로 찾기 )

for (int k = 0; k < N; ++k) {


    for (int i = 0; i < N; ++i) {


        for (int j = 0; j < N; ++j) {

            // d 에는 두 정점간의 연결이 초기화가 되어 있어야하고
            // 두 정점 간의 연결이 없다면 무한대로 초기화가 되어있어야한다.
            // 두 정점 간의 연결이 무한대가 아니라면 두 정점이 연결되어 있다고 확인할 수 있다.
            // 같은 정점끼리는 보통 0 or 무한대로 둔다.
            
            if (d[i][j] > d[i][k] + d[k][j]) {    i > k > j 로 경로가 i , j로 바로 가는 경로보다 짧다면 i, j 에넣기
                d[i][j] = d[i][k] + d[k][j];
            }

        }
    }
}


첫번째 반복문 - 거쳐가는 정점
두번째 반복문 - 출발하는 정점
세번째 반복문 - 도착하는 정점

이렇게 모든 경로를 확인함으로 d 배열에는 정점 간의 최단 경로가 구해질 수 밖엥 ㅓㅄ다.

같은 정점이나 연결되지 않은 경우는 걱정할필요없다.

같은 정점은 0으로 초기화, 연결되지 않은 경우는 무한대로 초기화 되었기 때문이다.

*** 주의할점 ***

문제에 다라 d배열 셋팅이 달라질 수 있다.



출처: https://mygumi.tistory.com/110 [마이구미의 HelloWorld]
*/