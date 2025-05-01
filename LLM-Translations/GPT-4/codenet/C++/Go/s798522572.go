package main

import (
	"fmt"
	"math"
)

func main() {
	var N, T int
	fmt.Scan(&N, &T)
	A := make([]int, N)
	B := make([]int, N)

	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
	}

	m := A[0]
	B[1] = A[1] - m
	m = min(m, A[1])

	for i := 2; i < N; i++ {
		B[i] = A[i] - m
		m = min(m, A[i])
	}

	maxElement := max(B)
	count := 0

	for _, value := range B {
		if value == maxElement {
			count++
		}
	}

	fmt.Println(count)
}

func min(a int, b int) int {
	if a < b {
		return a
	}
	return b
}

func max(arr []int) int {
	maxVal := math.MinInt32
	for _, value := range arr {
		if value > maxVal {
			maxVal = value
		}
	}
	return maxVal
}

// 
