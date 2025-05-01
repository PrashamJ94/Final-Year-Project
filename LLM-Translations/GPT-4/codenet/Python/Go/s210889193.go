package main

import (
	"fmt"
)

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func solver() {
	var N int
	fmt.Scan(&N)

	action := make([][]int, N)
	for i := range action {
		action[i] = make([]int, 3)
	}

	for i := 0; i < N; i++ {
		for j := 0; j < 3; j++ {
			fmt.Scan(&action[i][j])
		}
	}

	dp := make([][]int, N)
	for i := range dp {
		dp[i] = make([]int, 3)
	}

	for i := 0; i < 3; i++ {
		dp[0][i] = action[0][i]
	}

	for i := 1; i < N; i++ {
		dp[i][0] = max(dp[i-1][1]+action[i][0], dp[i-1][2]+action[i][0])
		dp[i][1] = max(dp[i-1][0]+action[i][1], dp[i-1][2]+action[i][1])
		dp[i][2] = max(dp[i-1][0]+action[i][2], dp[i-1][1]+action[i][2])
	}
	fmt.Println(max(dp[N-1][0], max(dp[N-1][1], dp[N-1][2])))
}

func main() {
	solver()
}

// 
