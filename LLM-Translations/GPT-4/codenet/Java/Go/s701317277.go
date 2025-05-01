package main

import (
	"fmt"
	"math"
	"sort"
)

func main() {
	var N int
	fmt.Scan(&N)

	A := make([]int, N)
	min := math.MaxInt32
	count := 0
	sum := int64(0)

	for i := 0; i < N; i++ {
		fmt.Scan(&A[i])
		if A[i] < 0 {
			count++
		}
		absValue := int(math.Abs(float64(A[i])))
		min = int(math.Min(float64(min), float64(absValue)))
		sum += int64(absValue)
	}

	if count%2 == 0 {
		fmt.Println(sum)
	} else {
		fmt.Println(sum - int64(min*2))
	}
}

// 
