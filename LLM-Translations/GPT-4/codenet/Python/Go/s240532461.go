package main

import (
	"fmt"
	"math"
)

func main() {
	var N, L int
	fmt.Scan(&N, &L)

	aji := make([]int, N)
	for i := 1; i <= N; i++ {
		aji[i-1] = L + i - 1
	}

	minIndex := 0
	minAbs := math.Abs(float64(aji[0]))
	for i := 1; i < N; i++ {
		if math.Abs(float64(aji[i])) < minAbs {
			minIndex = i
			minAbs = math.Abs(float64(aji[i]))
		}
	}

	aji = append(aji[:minIndex], aji[minIndex+1:]...)

	sum := 0
	for _, v := range aji {
		sum += v
	}
	fmt.Println(sum)
}
// 
