package main

import (
	"fmt"
)

func main() {
	var N, K int
	fmt.Scan(&N, &K)
	A := make([]int, N)

	for i := 0; i < K; i++ {
		var d int
		fmt.Scan(&d)
		AA := make([]int, d)
		for j := 0; j < d; j++ {
			fmt.Scan(&AA[j])
			A[AA[j]-1] = 1
		}
	}

	n := 0
	for i := 0; i < N; i++ {
		if A[i] == 0 {
			n += 1
		}
	}
	fmt.Println(n)
}

// 
