
package main

import (
	"fmt"
)

func main() {
	var N, S int

	for {
		fmt.Scan(&N)
		if N <= 0 {
			break
		}

		M, m, addup := -1, 1001, 0

		for i := 0; i < N; i++ {
			fmt.Scan(&S)
			addup += S
			if S > M {
				M = S
			}
			if S < m {
				m = S
			}
		}
		fmt.Println((addup - M - m) / (N - 2))
	}
}
// 

