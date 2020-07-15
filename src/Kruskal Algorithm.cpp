#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int getParent(int parent[], int x)
{
	// �ش� �θ� ���� x���� ���� ���
	if (parent[x] == x) return x;			// 1�� ��� �����ϸ� �� �κ��� ����ϴ� ���� 1�̵� ���̴�.
	// ���� �θ� ã�� ����
	return parent[x] = getParent(parent, parent[x]);
}

// �� �θ� ��带 ��ġ�� �Լ�		<< ��尣�� �������ִ� �Լ�
void unionParent(int parent[], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}
// ���� �θ� �������� Ȯ��		<< ��尣�� �������� �̷����ִ��� Ȯ���ϴ� �Լ�
int findParent(int parent[], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);

	if (a == b) return 1;
	return 0;
}
// �ϳ��� ���� ������ ���� ���� Ŭ���� ����
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
	const int n = 7;			// ����� ����
	const int m = 11;			// ������ ����

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

	// class ������ ������ ������ �����س����Ƿ� �ڵ����� �� ���ĵȴ�.
	sort(v.begin(), v.end());	

	// �� ������ ���Ե� �׷����� ������� ����
	int parent[n];
	for (int i = 0; i < n; i++)
	{
		parent[i] = i;
	}
	
	int sum = 0;
	for (int i = 0; i < v.size(); i++)
	{
		// ����Ŭ�� �߻����� �ʴ� ��� �׷����� �����ϴ� if��
		if (!findParent(parent, v[i].node[0] - 1, v[i].node[1] - 1))
		{
			sum += v[i].distance;
			unionParent(parent, v[i].node[0] - 1, v[i].node[1] - 1);
		}
	}

	printf("%d\n", sum);
	return 0;
}