package main

import (
	"fmt"
	"strconv"
	"strings"
)

func main() {
	var S string
	fmt.Scan(&S)
	MOD := int64(1000000007)
	dp := make([][]int64, len(S)+1)
	for i := range dp {
		dp[i] = make([]int64, 13)
	}
	dp[0][0] = 1
	for i := 0; i < len(S); i++ {
		if strings.IndexByte(S, i) == '?' {
			for j := 0; j < 10; j++ {
				for k := 0; k < 13; k++ {
					dp[i+1][(k*10+j)%13] += dp[i][k]
					dp[i+1][(k*10+j)%13] %= MOD
				}
			}
		} else {
			for k := 0; k < 13; k++ {
				x, _ := strconv.Atoi(string(S[i]))
				dp[i+1][(k*10+x)%13] += dp[i][k]
				dp[i+1][(k*10+x)%13] %= MOD
			}
		}
	}
	fmt.Println(dp[len(S)][5])
}

// 
