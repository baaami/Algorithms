package main

import (
	"fmt"
)

func findParent(parent []int, x int) int {
	if parent[x] == x {
		return x
	}
	parent[x] = findParent(parent, parent[x])
	return parent[x]
}

func unionParent(parent []int, a, b int) {
	rootA := findParent(parent, a)
	rootB := findParent(parent, b)

	if rootA < rootB {
		parent[rootB] = rootA
	} else {
		parent[rootA] = rootB
	}
}

func main() {
	var nMemberTotal, nPartyNum, nTruth int

	// 입력 받기
	fmt.Scan(&nMemberTotal, &nPartyNum)

	// 부모 노드 초기화
	parent := make([]int, nMemberTotal+1)
	for i := 1; i <= nMemberTotal; i++ {
		parent[i] = i
	}

	// 진실을 아는 사람들 입력
	fmt.Scan(&nTruth)
	truthPeople := make([]int, nTruth)
	for i := 0; i < nTruth; i++ {
		fmt.Scan(&truthPeople[i])
	}

	// 파티 정보 입력
	parties := make([][]int, nPartyNum)
	for i := 0; i < nPartyNum; i++ {
		var nMemberNum int
		fmt.Scan(&nMemberNum)
		parties[i] = make([]int, nMemberNum)

		for j := 0; j < nMemberNum; j++ {
			fmt.Scan(&parties[i][j])
		}

		// 파티에서 첫 번째 사람과 나머지 사람을 그룹으로 묶기
		for j := 1; j < nMemberNum; j++ {
			unionParent(parent, parties[i][0], parties[i][j])
		}
	}

	// 진실을 아는 사람들을 같은 그룹으로 묶기
	if nTruth > 0 {
		for i := 1; i < nTruth; i++ {
			unionParent(parent, truthPeople[0], truthPeople[i])
		}
	}

	// 과장된 이야기를 할 수 있는 파티 개수 계산
	count := 0
	for i := 0; i < nPartyNum; i++ {
		canLie := true

		// 진실을 아는 사람이 있는 경우에만 확인
		if nTruth > 0 {
			for j := 0; j < len(parties[i]); j++ {
				// 만약 파티 참석자 중 한 명이라도 진실을 아는 그룹에 속해 있으면 과장할 수 없음
				if findParent(parent, parties[i][j]) == findParent(parent, truthPeople[0]) {
					canLie = false
					break
				}
			}
		}

		if canLie {
			count++
		}
	}

	// 결과 출력
	fmt.Println(count)
}
