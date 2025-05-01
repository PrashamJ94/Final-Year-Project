
package main

import (
	"fmt"
	"strings"
)

func main() {
	var s string
	fmt.Scan(&s)
	sChars := strings.Split(s, "")
	n := len(sChars)
	M := 1000000007

	dp := make([][]int, n+1)
	for i := range dp {
		dp[i] = make([]int, 2)
	}
	dp[0][0] = 1

	for i := 0; i < n; i++ {
		if sChars[i] == "0" {
			dp[i+1][0] = dp[i][0]
			dp[i+1][1] = dp[i][1]
		} else {
			dp[i+1][1] = (dp[i][0] + dp[i][1]) % M
		}
		if sChars[i] == "0" {
			dp[i+1][1] += (dp[i][1] * 2) % M
			dp[i+1][1] %= M
		} else {
			dp[i+1][0] += (dp[i][0] * 2) % M
			dp[i+1][1] += (dp[i][1] * 2) % M
			dp[i+1][0] %= M
			dp[i+1][1] %= M
		}
	}
	fmt.Println((dp[n][0] + dp[n][1]) % M)
}

// //End of Code
