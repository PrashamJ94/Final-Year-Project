package main

import (
	"fmt"
	"sort"
)

func main() {
	var X, N int
	fmt.Scan(&X, &N)

	p := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&p[i])
	}

	sort.Ints(p)

	candidates := map[int][]int{}
	for i := -1; i < 102; i++ {

		if contains(p, i) {
			continue
		}

		if _, ok := candidates[abs(X-i)]; !ok {
			candidates[abs(X-i)] = []int{i}
		} else {
			candidates[abs(X-i)] = append(candidates[abs(X-i)], i)
		}
	}

	smallest := minKey(candidates)

	minNum := minIntSlice(candidates[smallest])

	fmt.Println(minNum)
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func contains(s []int, e int) bool {
	for _, a := range s {
		if a == e {
			return true
		}
	}
	return false
}

func minKey(m map[int][]int) int {
	min := 200
	for k := range m {
		if k < min {
			min = k
		}
	}
	return min
}

func minIntSlice(s []int) int {
	min := s[0]
	for _, v := range s {
		if v < min {
			min = v
		}
	}
	return min
}

// 
