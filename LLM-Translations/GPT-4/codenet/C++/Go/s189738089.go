
package main

import (
	"fmt"
	"math"
)

func main() {
	var N, K int
	fmt.Scan(&N, &K)
	h := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&h[i])
	}

	dp := make([]int, 101000)
	for i := 0; i < len(dp); i++ {
		dp[i] = math.MaxInt32
	}
	dp[0] = 0

	for i := 0; i < N; i++ {
		for j := 1; j <= K; j++ {
			if i+j < len(dp) {
				dp[i+j] = min(dp[i+j], dp[i]+abs(h[i]-h[i+j]))
			}
		}
	}

	fmt.Println(dp[N-1])
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

// 
