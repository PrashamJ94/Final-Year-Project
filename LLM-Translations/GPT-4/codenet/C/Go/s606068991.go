
package main

import (
	"fmt"
)

func white(n int, A []int) {
	for i := 0; i < n-1; i++ {
		fmt.Printf("%d ", A[i])
	}
	fmt.Printf("%d\n", A[n-1])
}

func insertionSort(n int, A []int) {
	var i, j, a int
	for i = 0; i < n; i++ {
		for j = 0; j < i; j++ {
			if A[i] < A[j] {
				a = A[i]
				A[i] = A[j]
				A[j] = a
			}
		}
		white(n, A)
	}
}

func main() {
	var i, n int
	var A = make([]int, 100)
	fmt.Scanf("%d", &n)
	for i = 0; i < n; i++ {
		fmt.Scanf("%d", &A[i])
	}
	insertionSort(n, A[:n])
}

// 
