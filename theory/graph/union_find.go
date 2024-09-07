package main

import "fmt"

// 부모 노드를 찾는 함수 (경로 압축 적용)
func getParent(parent []int, x int) int {
	if parent[x] == x {
		return x
	}
	parent[x] = getParent(parent, parent[x])
	return parent[x]
}

// 두 노드를 같은 부모로 합치는 함수
func unionParent(parent []int, a, b int) {
	a = getParent(parent, a)
	b = getParent(parent, b)

	if a < b {
		parent[b] = a
	} else {
		parent[a] = b
	}
}

// 두 노드가 같은 부모를 가지는지 확인하는 함수
func findParent(parent []int, a, b int) bool {
	return getParent(parent, a) == getParent(parent, b)
}

func main() {
	// 부모 노드를 저장할 슬라이스 초기화
	parent := make([]int, 11)
	for i := 1; i <= 10; i++ {
		parent[i] = i
	}

	// 부모를 합치는 연산
	unionParent(parent, 1, 2)
	unionParent(parent, 2, 3)
	unionParent(parent, 3, 4)

	unionParent(parent, 5, 6)
	unionParent(parent, 6, 7)
	unionParent(parent, 7, 8)

	// 1과 5가 연결되어 있는지 확인
	fmt.Printf("1과 5는 연결되어 있나요?? : %t\n", findParent(parent, 1, 5))

	// 1과 5를 같은 부모로 합침
	unionParent(parent, 1, 5)

	// 다시 1과 5가 연결되어 있는지 확인
	fmt.Printf("1과 5는 연결되어 있나요?? : %t\n", findParent(parent, 1, 5))
}
