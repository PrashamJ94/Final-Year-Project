package main

import (
	"fmt"
)

func main() {
	var N int
	fmt.Scan(&N)
	A := make([]int, N+1)
	B := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}
	for i := 0; i < N; i++ {
		fmt.Scan(&B[i])
	}

	ans := 0
	for i := 0; i < N; i++ {
		d := min(A[i], B[i])
		ans += d
		A[i] -= d
		B[i] -= d
		d = min(A[i+1], B[i])
		ans += d
		A[i+1] -= d
		B[i] -= d
	}

	fmt.Println(ans)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// 
