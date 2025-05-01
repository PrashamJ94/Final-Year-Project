package main

import (
	"fmt"
)

func main() {
	var N, T int
	fmt.Scan(&N, &T)
	L := make([][]int, N)
	for i := range L {
		L[i] = make([]int, 2)
		fmt.Scan(&L[i][0], &L[i][1])
	}

	dp := make([][]int, N+1)
	for i := range dp {
		dp[i] = make([]int, T)
	}

	for i := 0; i < N; i++ {
		for j := 0; j < T; j++ {
			if j < L[i][0] {
				dp[i+1][j] = dp[i][j]
			} else {
				dp[i+1][j] = max(dp[i][j], dp[i][j-L[i][0]]+L[i][1])
			}
		}
	}

	used := map[int]bool{}
	B := dp[N][T-1]
	j := T - 1
	for i := N - 1; i >= 0; i-- {
		if B == dp[i][j] {
			continue
		}
		B -= L[i][1]
		used[i] = true
		j -= L[i][0]
	}

	ans := dp[N][T-1]
	c := 0
	for i := 0; i < N; i++ {
		if used[i] {
			continue
		}
		c = max(c, L[i][1])
	}

	fmt.Println(ans + c)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// 
