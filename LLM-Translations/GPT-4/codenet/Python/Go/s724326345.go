package main

import (
	"fmt"
	"math"
)

func main() {
	var A, B, C, X, Y int
	fmt.Scanf("%d %d %d %d %d", &A, &B, &C, &X, &Y)

	ans := math.MaxInt32

	for k := 0; k <= max(X, Y); k++ {
		total := 2*C*k + A*max(0, X-k) + B*max(0, Y-k)
		if total < ans {
			ans = total
		}
	}

	fmt.Println(ans)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// 
