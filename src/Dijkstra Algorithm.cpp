/*
	다익스트라 알고리즘

	하나의 정점에서 다른 모든 정점으로 가는 최단 경로를 알려준다. 간선이 음이 된다면 불가능하다.
	다이나믹 프로그래밍 중 하나이다. 그 이유는 여러개의 최단거리로 이루어져있기 때문.

	컴퓨터는 1개씩만 계산이 가능하다.
	>> 현재까지 알고 있던 최단 경로를 계속해서 갱신

	1. 출발 노드를 설정
	2. 출발 노드를 기준으로 각 노드의 최소 비용을 저장한다.
	3. 방문하지 않은 노드 중에서 가장 비용이 적은 노드를 선택한다.
	4. 해당 노드를 거쳐서 특정한 노드로 가는 경우를 고려하여 최소비용을 갱신한다.
	5. 3, 4번 반복한다.
*/
#include <stdio.h>

int number = 6;
int INF = 1000000000;		// int는 20억까지 가능하므로 10억넣어주면 무한대라고 생각

// 현재 그래프 그리기
int a[6][6]{
	{0,2,5,1,INF,INF},		// 1에서 가능 경로의 비용
	{2,0,3,2,INF,INF},
	{5,3,0,3,1,5},
	{1,2,3,0,1,INF},
	{INF,INF,1,1,0,2},
	{INF,INF,5,INF,2,0},
};

bool v[6];			// 방문한 노드
int d[6];			// 최단 거리 저장한 노드

// 아직 방문하지 않은 노드 중에 가장 최소 거리를 가지는 정점 반환
// 선형으로 가장 쉽게 구현 ( 효율은 x )
int getSmallIndex()
{
	int min = INF;
	int index = 0;
	for (int i = 0; i < number; i++)
	{
		if (d[i] < min && !v[i])			// 방문하지 않았고 min보다 작은 경우
		{
			min = d[i];
			index = i;
		}
	}
	return index;
}

// 다익스트라를 수행하는 함수
void dijkstra(int start)
{
	for (int i = 0; i < number; i++)
	{
		d[i] = a[start][i];			// 시작점부터 모든 경로를 담아둔다. 갱신할 table을 만든다
	}
	v[start] = true;
	// O(N * N)이 된다. getSmallIndex도 현재 N이기 때문
	// 가장 작은 값을 가져오는 경우를 heap 탐색을 통해서 가져오면 log N으로 가져올 수 있다.
	for (int i = 0; i < number - 1; i++)
	{
		int current = getSmallIndex();
		v[current] = true;
		// current 노드를 거쳐서 갈 경우 갱신할 거리가있는지 확인
		for (int j = 0; j < 6; j++)
		{
			if (!v[j])		//아직 방문하지 않은 경우
			{
				// 1 -> current + current -> j 의 비용 , 1 -> j 가는 비용 비교
				if (d[current] + a[current][j] < d[j])
				{
					d[j] = d[current] + a[current][j];
				}
			}
		}
	}
}

int main(void)
{
	dijkstra(0);
	for (int i = 0; i < number; i++)
	{
		printf("%d ", d[i]);
	}
}



