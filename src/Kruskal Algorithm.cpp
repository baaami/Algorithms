#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int getParent(int parent[], int x)
{
	// 해당 부모 값과 x값이 같은 경우
	if (parent[x] == x) return x;			// 1로 모두 연결하면 이 부분을 통과하는 것은 1이될 것이다.
	// 최종 부모를 찾는 과정
	return parent[x] = getParent(parent, parent[x]);
}

// 두 부모 노드를 합치는 함수		<< 노드간에 연결해주는 함수
void unionParent(int parent[], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}
// 같은 부모를 가지는지 확인		<< 노드간에 간선으로 이뤄져있는지 확인하는 함수
int findParent(int parent[], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);

	if (a == b) return 1;
	return 0;
}
// 하나의 간선 정보를 갖는 간선 클래스 선언
class Edge{
public:
	int node[2];
	int distance;
	Edge(int a, int b, int distance) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}
	bool operator < (Edge &edge) {
		return this->distance < edge.distance;
	}
};

int main()
{
	const int n = 7;			// 노드의 개수
	const int m = 11;			// 간선의 개수

	vector<Edge> v;
	v.push_back(Edge(1, 7, 12));
	v.push_back(Edge(1, 4, 28));
	v.push_back(Edge(1, 2, 67));
	v.push_back(Edge(1, 5, 17));
	v.push_back(Edge(2, 4, 24));
	v.push_back(Edge(2, 5, 62));
	v.push_back(Edge(3, 5, 20));
	v.push_back(Edge(3, 6, 37));
	v.push_back(Edge(4, 7, 13));
	v.push_back(Edge(5, 6, 45));
	v.push_back(Edge(5, 7, 73));

	// class 내에서 정렬의 기준을 명시해놨으므로 자동으로 잘 정렬된다.
	sort(v.begin(), v.end());	

	// 각 정점이 포함된 그래프가 어디인지 저장
	int parent[n];
	for (int i = 0; i < n; i++)
	{
		parent[i] = i;
	}
	
	int sum = 0;
	for (int i = 0; i < v.size(); i++)
	{
		// 사이클이 발생하지 않는 경우 그래프에 포함하는 if문
		if (!findParent(parent, v[i].node[0] - 1, v[i].node[1] - 1))
		{
			sum += v[i].distance;
			unionParent(parent, v[i].node[0] - 1, v[i].node[1] - 1);
		}
	}

	printf("%d\n", sum);
	return 0;
}