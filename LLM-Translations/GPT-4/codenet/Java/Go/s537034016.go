package main

import (
	"fmt"
)

var dp []int64
var mod int64 = 1000000007

func main() {
	var s int
	fmt.Scanf("%d", &s)

	dp = make([]int64, s+1)
	for i := range dp {
		dp[i] = -1
	}
	dp[0] = 1
	fmt.Println(dfs(s))
}

func dfs(s int) int64 {
	if dp[s] != -1 {
		return dp[s]
	}

	var ret int64 = 0
	for i := s - 3; i >= 0; i-- {
		ret += dfs(i)
		ret %= mod
	}
	dp[s] = ret
	return ret
}

// 
