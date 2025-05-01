
package main

import (
	"fmt"
	"math"
)

const INF int64 = 123456789012

func main() {
	var n, m int64
	fmt.Scan(&n, &m)

	key := make([]int64, 1005)
	cost := make([]int64, 1005)
	dp := make([][]int64, (1<<12)+5)

	for i := range dp {
		dp[i] = make([]int64, 1005)
		for j := range dp[i] {
			dp[i][j] = INF
		}
	}

	dp[0][0] = 0

	for i := int64(1); i <= m; i++ {
		var b int64
		fmt.Scan(&cost[i], &b)
		for j := int64(0); j < b; j++ {
			var c int64
			fmt.Scan(&c)
			key[i] += (1 << (c - 1))
		}
	}

	for i := int64(0); i < (1 << n); i++ {
		for j := int64(0); j < m; j++ {
			dp[i][j+1] = int64(math.Min(float64(dp[i][j]), float64(dp[i][j+1])))
			dp[i|key[j+1]][j+1] = int64(math.Min(float64(dp[i|key[j+1]][j+1]), float64(dp[i][j]+cost[j+1])))
		}
	}

	if dp[(1<<n)-1][m] == INF {
		fmt.Println(-1)
	} else {
		fmt.Println(dp[(1<<n)-1][m])
	}
}
// 


