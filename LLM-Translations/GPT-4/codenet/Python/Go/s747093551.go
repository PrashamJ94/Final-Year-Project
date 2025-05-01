package main

import (
	"fmt"
	"math"
)

func main() {
	var N, M, X, Y int
	fmt.Scan(&N, &M, &X, &Y)

	x := make([]int, N)
	for i := 0; i < N; i++ {
		fmt.Scan(&x[i])
	}

	y := make([]int, M)
	for i := 0; i < M; i++ {
		fmt.Scan(&y[i])
	}

	maxX, minY := math.MinInt64, math.MaxInt64
	for _, v := range x {
		if v > maxX {
			maxX = v
		}
	}
	for _, v := range y {
		if v < minY {
			minY = v
		}
	}

	if max(maxX, X) < min(minY, Y) {
		fmt.Println("No War")
	} else {
		fmt.Println("War")
	}
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
// 
