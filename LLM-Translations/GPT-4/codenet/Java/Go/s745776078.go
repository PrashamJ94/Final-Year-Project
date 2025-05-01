package main

import (
	"fmt"
)

func main() {
	var n, m int
	fmt.Scan(&n, &m)

	A := make([][]int, n)
	for i := range A {
		A[i] = make([]int, m)
	}

	b := make([]int, m)

	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			fmt.Scan(&A[i][j])
		}
	}

	for i := 0; i < m; i++ {
		fmt.Scan(&b[i])
	}

	for i := 0; i < n; i++ {
		c := 0
		for j := 0; j < m; j++ {
			c += A[i][j] * b[j]
		}
		fmt.Println(c)
	}

}

// 
