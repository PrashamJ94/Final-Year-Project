package main

import (
	"fmt"
)

func main() {
	var m, n int
	fmt.Scan(&m, &n)

	A := make([][]int, m)
	for i := range A {
		A[i] = make([]int, n)
	}

	B := make([]int, n)
	S := make([]int, m)

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			fmt.Scan(&A[i][j])
		}
	}

	for i := 0; i < n; i++ {
		fmt.Scan(&B[i])
	}

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			S[i] = S[i] + A[i][j]*B[j]
		}
	}

	for i := 0; i < m; i++ {
		fmt.Println(S[i])
	}
}

// 
