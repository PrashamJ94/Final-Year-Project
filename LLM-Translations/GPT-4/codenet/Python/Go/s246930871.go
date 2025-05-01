package main

import "fmt"

func main() {
	var N, A, B int
	fmt.Scan(&N, &A, &B)

	ans := A * (N / (A + B)) + min(A, N%(A+B))
	fmt.Println(ans)
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// 
