package main

import (
	"fmt"
)

func main() {
	var N int
	fmt.Scan(&N)

	A := make([][]int, 2)
	for i := 0; i < 2; i++ {
		row := make([]int, N)
		for j := 0; j < N; j++ {
			fmt.Scan(&row[j])
		}
		A[i] = row
	}

	ans := make([]int, 0)

	count := 0
	for i := 0; i < N; i++ {
		baselis := A[0]
		groundlis := A[1]
		count = 0
		count = count + sum(baselis[0:i+1]) + sum(groundlis[i:N+1])
		ans = append(ans, count)
	}

	fmt.Println(max(ans))
}

func sum(arr []int) int {
	total := 0
	for _, v := range arr {
		total += v
	}
	return total
}

func max(arr []int) int {
	maxValue := arr[0]
	for _, v := range arr {
		if v > maxValue {
			maxValue = v
		}
	}
	return maxValue
}

// 
