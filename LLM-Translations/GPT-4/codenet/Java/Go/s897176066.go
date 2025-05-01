package main

import (
	"fmt"
	"sort"
)

func main() {
	var N int
	fmt.Scan(&N)
	A := make([]int64, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}
	sort.Slice(A, func(i, j int) bool { return A[i] < A[j] })
	for j := 1; j < N; j++ {
		if A[j] == A[j-1] {
			fmt.Println("NO")
			return
		}
	}
	fmt.Println("YES")
}
// 
