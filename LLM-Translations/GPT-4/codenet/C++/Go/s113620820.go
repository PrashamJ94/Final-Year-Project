
package main

import (
	"fmt"
)

const MAX_N = 4000
const LINF int64 = 1 << 60

var wis [MAX_N]int64
var wsums [MAX_N + 1]int64
var dp [MAX_N][MAX_N + 1]int64
var ks [MAX_N][MAX_N + 1]int

func main() {
	var n int
	fmt.Scan(&n)

	wsums[0] = 0
	for i := 0; i < n; i++ {
		fmt.Scan(&wis[i])
		wsums[i+1] = wsums[i] + wis[i]
	}

	for i := 0; i < n; i++ {
		for j := 0; j <= n; j++ {
			dp[i][j] = LINF
			ks[i][j] = -1
		}
		dp[i][i+1] = 0
		ks[i][i+1] = i
	}

	for l := 2; l <= n; l++ {
		for i, j := 0, l; j <= n; i, j = i+1, j+1 {
			var mind int64 = LINF
			var wsum int64 = wsums[j] - wsums[i]
			var mink int = -1
			for k := ks[i][j-1]; k <= ks[i+1][j]; k++ {
				d := dp[i][k] + dp[k][j] + wsum
				if mind > d {
					mind = d
					mink = k
				}
			}
			dp[i][j] = mind
			ks[i][j] = mink
		}
	}

	fmt.Printf("%d\n", dp[0][n])
}


