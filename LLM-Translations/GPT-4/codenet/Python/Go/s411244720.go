package main

import (
	"fmt"
)

func main() {
	var N, K int
	fmt.Scan(&N, &K)
	S := make(map[int]bool)
	var d int
	for i := 0; i < K; i++ {
		fmt.Scan(&d)
		for j := 0; j < d; j++ {
			var A int
			fmt.Scan(&A)
			S[A] = true
		}
	}
	fmt.Println(N - len(S))
}

// 
