
package main

import (
	"fmt"
	"strconv"
)

func main() {
	var cs string
	fmt.Scan(&cs)

	const MOD int64 = 1e9 + 7
	dp := make([][]int64, len(cs))
	for i := range dp {
		dp[i] = make([]int64, 13)
	}

	base := 1
	for i := 0; i < len(cs); i++ {
		if cs[len(cs)-1-i] == '?' {
			for pre := 0; pre < 13; pre++ {
				for next := 0; next < 10; next++ {
					dp[i][(base*next+pre)%13] += func() int64 {
						if i > 0 {
							return dp[i-1][pre]
						}
						if pre == 0 {
							return 1
						}
						return 0
					}()
					dp[i][(base*next+pre)%13] %= MOD
				}
			}
		} else {
			next, _ := strconv.Atoi(string(cs[len(cs)-1-i]))
			for pre := 0; pre < 13; pre++ {
				dp[i][(base*next+pre)%13] += func() int64 {
					if i > 0 {
						return dp[i-1][pre]
					}
					if pre == 0 {
						return 1
					}
					return 0
				}()
				dp[i][(base*next+pre)%13] %= MOD
			}
		}
		base = base * 10 % 13
	}

	fmt.Println(dp[len(dp)-1][5])
}

// //End of Code


