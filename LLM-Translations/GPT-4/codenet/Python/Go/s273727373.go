package main

import (
	"fmt"
)

func main() {
	var N int
	fmt.Scan(&N)

	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}

	B := make([]int, N)
	count := 1
	for _, i := range A {
		B[i-1] = count
		count++
	}

	for _, b := range B {
		fmt.Print(b, " ")
	}
	fmt.Println()
}

// 
