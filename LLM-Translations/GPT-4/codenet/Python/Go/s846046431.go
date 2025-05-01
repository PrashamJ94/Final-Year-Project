
package main

import (
	"fmt"
	"sort"
)

func main() {
	var N, M int
	fmt.Scan(&N, &M)
	A := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}
	sort.Slice(A, func(i, j int) bool {
		return A[i] > A[j]
	})
	S := 0
	for _, a := range A {
		S += a
	}
	for i := 0; i < M; i++ {
		if float64(A[i])/float64(S) - 1.0/(4*float64(M)) < 0 {
			fmt.Println("No")
			return
		}
	}
	fmt.Println("Yes")
}

// 
