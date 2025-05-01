
package main

import (
	"fmt"
)

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}

func main() {
	var A, B, C, K int64
	fmt.Scan(&A, &B, &C, &K)

	if A+B >= K {
		fmt.Println(min(A, K))
	} else {
		fmt.Println(A - (K - (A + B)))
	}
}


