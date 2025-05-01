
package main

import (
	"fmt"
)

const mod int = 1e9+7

func main() {
	var S string
    fmt.Scan(&S)
	n := len(S)
	if n == 1 {
		if S == "5" || S == "?" {
			fmt.Println(1)
		} else {
			fmt.Println(0)
		}
		return
	}
	dp := make([][]int, n)
	for i := range dp {
		dp[i] = make([]int, 13)
	}
	for i := 0; i < n; i++ {
		if i == 0 {
			if S[i] != '?' {
				dp[i][int(S[i]-'0')]++
			} else {
				for j := 0; j < 10; j++ {
					dp[i][j]++
				}
			}
		} else {
			if S[i] != '?' {
				for k := 0; k < 13; k++ {
					dp[i][(k*10+int(S[i]-'0'))%13] += dp[i-1][k]
				}
			} else {
				for j := 0; j < 10; j++ {
					for k := 0; k < 13; k++ {
						dp[i][(k*10+j)%13] += dp[i-1][k]
					}
				}
			}
			for k := 0; k < 13; k++ {
				dp[i][k] %= mod
			}
		}
	}
	fmt.Println(dp[n-1][5])
}
// End of Code

Please note that this Go code requires you to enter the string as input in the command line after running the program. If you are running the program in an online compiler, you might need to add an input field for the string.
