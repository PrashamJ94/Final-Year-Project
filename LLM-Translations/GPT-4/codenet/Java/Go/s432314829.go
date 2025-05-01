package main

import (
	"fmt"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)
	dp := make([]int, n+2)
	dp[n+1] = 0
	dp[n] = 1
	for i := 0; i < m; i++ {
		var blockedStep int
		fmt.Scan(&blockedStep)
		dp[blockedStep] = -1
	}
	for i := n - 1; i >= 0; i-- {
		if dp[i] == -1 {
			dp[i] = 0
		} else {
			dp[i] = (dp[i+1] + dp[i+2]) % 1000000007
		}
	}
	fmt.Println(dp[0])
}

// 
