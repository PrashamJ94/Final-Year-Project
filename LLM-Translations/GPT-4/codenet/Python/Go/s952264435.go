package main

import (
	"fmt"
)

func main() {
	var N, M int
	fmt.Scan(&N, &M)

	A := make([]int, M)
	var A_sum int

	for i := 0; i < M; i++ {
		fmt.Scan(&A[i])
		A_sum += A[i]
	}

	if N-A_sum >= 0 {
		fmt.Println(N - A_sum)
	} else {
		fmt.Println("-1")
	}
}
// 
