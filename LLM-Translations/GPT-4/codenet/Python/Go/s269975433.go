package main

import (
	"fmt"
)

func combinationsWithReplacement(arr []int, r int) [][]int {
	var result [][]int
	var comb func(int, int, []int)

	comb = func(start int, index int, current []int) {
		if index == r {
			temp := make([]int, r)
			copy(temp, current)
			result = append(result, temp)
			return
		}
		for i := start; i < len(arr); i++ {
			current[index] = arr[i]
			comb(i, index+1, current)
		}
	}

	comb(0, 0, make([]int, r))
	return result
}

func main() {
	N, M, Q := 3, 4, 3

	Q_groups := [][]int{
		{1, 2, 2, 1},
		{1, 3, 3, 1},
		{2, 3, 2, 1},
	}

	max_score := 0
	arr := make([]int, M)
	for i := 1; i <= M; i++ {
		arr[i-1] = i
	}

	for _, p := range combinationsWithReplacement(arr, N) {
		temp_score := 0
		for _, q := range Q_groups {
			if p[q[1]-1]-p[q[0]-1] == q[2] {
				temp_score += q[3]
			}
		}
		if temp_score > max_score {
			max_score = temp_score
		}
	}

	fmt.Println(max_score)
}

// 
