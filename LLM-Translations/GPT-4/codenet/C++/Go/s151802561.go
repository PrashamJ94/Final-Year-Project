package main

import (
	"fmt"
)

func main() {
	var n, i, j, t, sw, mini int
	var A [100]int

	fmt.Scan(&n)
	for i = 0; i < n; i++ {
		fmt.Scan(&A[i])
	}

	for i = 0; i < n; i++ {
		mini = i
		for j = i; j < n; j++ {
			if A[j] < A[mini] {
				mini = j
			}
		}
		t = A[i]
		A[i] = A[mini]
		A[mini] = t
		if i != mini {
			sw++
		}
	}

	for i = 0; i < n; i++ {
		if i != 0 {
			fmt.Print(" ")
		}
		fmt.Print(A[i])
	}
	fmt.Println()
	fmt.Println(sw)
}

// 
